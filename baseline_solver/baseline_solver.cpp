//
// Created by nikul on 22.02.2022.
//
#include "baseline_solver.hpp"

#include <vector>
#include <deque>
#include <exception>
#include <iostream>

#include "../structures.hpp"
namespace solvers {

    using std::vector;

    std::vector<VM> BaseSolver::vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts, const std::vector<VM> &vm_types) {
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

    void BaseSolver::vm_generate_single(std::vector<Container> requests, std::vector<VM>& res,
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

        int start = res.size();
        //std::cerr << "vm min cnt " << vm_min_cnt << std::endl;
        for (int i = 0; i < vm_min_cnt; ++i) {
            res.push_back(vm_types[0]);
        }
        max_vm_used = std::max(max_vm_used, vm_min_cnt);
        std::deque<Container> sorted_container;
        std::move(std::begin(requests), std::end(requests), std::back_inserter(sorted_container));

        int pos = 0;
        while (!sorted_container.empty()) {
            res[start + pos] = (res[start + pos] + sorted_container.front());
            sorted_container.pop_front();
            if (!sorted_container.empty() && res[start + pos].cpu_request + sorted_container.back().cpu_request < 1 &&
                    res[start + pos].memory_request + sorted_container.back().memory_request < 1) {
                res[start + pos] = (res[start + pos] + sorted_container.back());
                sorted_container.pop_back();
            }
            pos = (pos + 1) % vm_min_cnt;
        }
        //std::cerr << total_cpu_request << " " << total_memory_request << " " << vm_min_cnt << " " << max_cpu_host << " " << max_memory_host << std::endl;
    }

    void BaseSolver::vm_placement(vector <VM> &vms, std::vector<Host> &hosts) {
        std::cerr << vms.size() << std::endl;
        std::sort(vms.begin(), vms.end(), [](const VM& a, const VM& b) {
            return a.cpu_request + a.memory_request > b.cpu_request + b.memory_request;
        });
        for (auto &current: vms) {
           double max_os_active = -1;
           double max_mem_active = -1;
           int best_active = -1;

           double max_os_md = -1;
           double max_mem_md = -1;
           int best_nonactive = -1;

           for (int i = 0; i < hosts.size(); ++i) {
               //os limitation
               double a_os = (hosts[i].cpu_limit - current.cpu_request);
               double b_os = (hosts[i].cpu_limit - current.cpu_request) / hosts[i].cpu_max_limit;

               //memory limitation
               double a_mem = (hosts[i].m_limit - current.memory_request);
               double b_mem = (hosts[i].m_limit - current.memory_request) / hosts[i].m_max_limit;

               if (a_os < 0 || a_mem < 0 ) {
                   continue;
               }

               double a_min = std::min(a_os, a_mem);
               double a_max = std::max(a_os, a_mem);
               double b_min = std::min(b_os, b_mem);
               double b_max = std::max(b_os, b_mem);

               a_os = (a_os - a_min) / (a_max - a_min);
               a_mem = (a_mem - a_min) / (a_max - a_min);
               b_os = (b_os - b_min) / (b_max - b_min);
               b_mem = (b_mem - b_min) / (b_max - b_min);

               double md_os = k_w1 * a_os + k_w2 * b_os;
               double md_mem = k_w1 * a_mem + k_w2 * b_mem;
               if (hosts[i].is_active && md_os > max_os_active && md_mem > max_mem_active) {
                   best_active = i;
                   max_os_active = md_os;
                   max_mem_active = md_mem;
               } else if (!hosts[i].is_active && md_os > max_os_md && md_mem > max_mem_md) {
                   best_nonactive = i;
                   max_os_md = md_os;
                   max_mem_md = md_mem;
               }
           }
           if (best_active >= 0) {
               hosts[best_active].Place(current);
               current.host = best_active;
           } else if (best_nonactive >= 0) {
               hosts[best_nonactive].is_active = true;
               hosts[best_nonactive].Place(current);
               current.host = best_nonactive;
           } else {
               throw std::invalid_argument("Baseline fit cannot fit VMs onto PMs");
           }
           //std::cerr << "placed single" << std::endl;
        }
    }

    long double BaseSolver::energy_consumption(const std::vector<Host> &hosts) {
        long double ans = 0;
        for (const auto &current: hosts) {
            if (current.is_active) {
                ans += current.e_idle + (current.e_full - current.e_idle) *
                                        ((current.cpu_max_limit - current.cpu_limit) * 1.0 / current.cpu_max_limit);
            }
        }
        return ans;
    }

}