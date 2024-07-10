//
// Created by nikul on 22.02.2022.
//
#include <harmonic.hpp>

#include <vector>
#include <deque>
#include <exception>
#include <iostream>

#include <structures.hpp>
namespace solvers {

    using std::vector;

    std::vector<VM> HarmonicSolver::vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts, const std::vector<VM> &vm_types) {
        std::map<std::pair<int, long long>, std::vector<Container>> classified_requests;
        std::vector<VM> res;
        int max_jobs_batch = 0;
        for (auto tmp : requests) {
            classified_requests[{tmp.os, tmp.job}].push_back(tmp);
        }
        double max_cpu_host = 0;
        double max_memory_host = 0;
        for (const auto& host : hosts) {
            max_cpu_host = std::max(max_cpu_host, host.cpu_max_limit);
            max_memory_host = std::max(max_memory_host, host.m_max_limit);
        }
        std::cerr << "limits to use: " << max_cpu_host << " " << max_memory_host << std::endl;
        for (const auto& req_vector : classified_requests) {
            max_jobs_batch = std::max(max_jobs_batch, static_cast<int>(req_vector.second.size()));
            vm_generate_single(req_vector.second, res, max_cpu_host, max_memory_host, vm_types);
        }
        std::cerr << "Max vms for a single job " << max_vm_used << " and max jobs in a batch " << max_jobs_batch << std::endl;
        return res;
    }

    //modified ffd - https://en.wikipedia.org/wiki/First-fit-decreasing_bin_packing
    void HarmonicSolver::vm_generate_single(std::vector<Container> requests, std::vector<VM>& res,
                            double max_cpu_host, double max_memory_host, const std::vector<VM> &vm_types) {
        int vm_min_cnt = 0;

        //std::cerr << "minimum VMs on a host " << k_vm_min_count << std::endl;
        //cpu limitation
        double total_cpu_request = 0;
        for (const auto& tmp : requests) {
            total_cpu_request += tmp.cpu_request;
        }
        //std::cerr << "cpu limitations for " << requests.size() << " jobs with " << total_cpu_request << " requested CPU" << std::endl;
        vm_min_cnt = std::max(vm_min_cnt, static_cast<int>(total_cpu_request / (max_cpu_host / k_vm_min_count- vm_types[0].cpu_overhead) * 1 + 1));

        //std::cerr << "vm min cnt after CPU requirements " << vm_min_cnt << std::endl;
        //memory limitation
        double total_memory_request = 0;
        for (const auto& tmp : requests) {
            total_memory_request += tmp.memory_request;
        }
        //std::cerr << "memory limitations for " << requests.size() << " jobs with " << total_memory_request << " requested memory" << std::endl;
        vm_min_cnt = std::max(vm_min_cnt, static_cast<int>(total_memory_request / (max_memory_host / k_vm_min_count- vm_types[0].memory_overhead) * 1 + 1));

        //std::cerr << "vm min cnt after memory requirements " << vm_min_cnt << std::endl;
        std::sort(requests.begin(), requests.end(), [](const Container& a, const Container& b) {
            return a.cpu_request < b.cpu_request;
        });


        double right_limit = std::max(total_cpu_request / vm_min_cnt, total_memory_request / vm_min_cnt);
        std::vector<VM> classes(k_segment_count, vm_types[0]);
        std::vector<int> used_count(k_segment_count);
        for (auto& tmp : requests) {
            int placement_ind = k_segment_count - 1;
            for (int i = 0; i < k_segment_count; ++i) {
                if (tmp.cpu_request < right_limit / k_segment_count * (i + 1)) {
                    placement_ind = i;
                    break;
                }
            }
            if (classes[placement_ind].cpu_request + tmp.cpu_request > right_limit ||
            classes[placement_ind].memory_request + tmp.memory_request > right_limit) {
                if (used_count[placement_ind] > 0) {
                    res.push_back(classes[placement_ind]);
                }
                classes[placement_ind] = vm_types[0] + tmp;
                used_count[placement_ind] = 1;
            } else {
                if (used_count[placement_ind] < k_segment_count - placement_ind) {
                    used_count[placement_ind]++;
                    classes[placement_ind] = (classes[placement_ind] + tmp);
                } else {
                    res.push_back(classes[placement_ind]);
                    classes[placement_ind] = vm_types[0] + tmp;
                    used_count[placement_ind] = 1;
                }
            }
        }
        for (int i = 0; i < k_segment_count; ++i) {
            if (used_count[i] > 0) {
                res.push_back(classes[i]);
            }
        }

    }

}