#include <deque>
#include <exception>
#include <iostream>
#include <modified.hpp>
#include <structures.hpp>
#include <vector>
namespace solvers {

using std::vector;

std::vector<VM> ModifiedSolver::vm_generator(std::vector<Container> requests, const std::vector<Host>& hosts,
                                             const std::vector<VM>& vm_types) {
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
    std::cerr << "Max vms for a single job " << max_vm_used << " and max jobs in a batch " << max_jobs_batch
              << std::endl;
    return res;
}

// modified ffd - https://en.wikipedia.org/wiki/First-fit-decreasing_bin_packing
void ModifiedSolver::vm_generate_single(std::vector<Container> requests, std::vector<VM>& res, double max_cpu_host,
                                        double max_memory_host, const std::vector<VM>& vm_types) {
    int vm_min_cnt = 0;

    // cpu limitation
    double total_cpu_request = 0;
    for (const auto& tmp : requests) {
        total_cpu_request += tmp.cpu_request;
    }
    vm_min_cnt =
        std::max(vm_min_cnt,
                 static_cast<int>(total_cpu_request / (max_cpu_host - vm_types[0].cpu_overhead) * k_vm_min_count + 1));

    // memory limitation
    double total_memory_request = 0;
    for (const auto& tmp : requests) {
        total_memory_request += tmp.memory_request;
    }
    vm_min_cnt = std::max(
        vm_min_cnt,
        static_cast<int>(total_memory_request / (max_memory_host - vm_types[0].memory_overhead) * k_vm_min_count + 1));
    k_resource_limit = std::max(total_cpu_request / vm_min_cnt, total_memory_request / vm_min_cnt);

    std::sort(requests.begin(), requests.end(),
              [](const Container& a, const Container& b) { return a.cpu_request > b.cpu_request; });

    int start = res.size();

    std::deque<Container> sorted_container;
    std::move(std::begin(requests), std::end(requests), std::back_inserter(sorted_container));

    // process big

    int pos = 0;
    while (!sorted_container.empty() && sorted_container.front().cpu_request > 0.5 * k_resource_limit) {
        res.push_back(vm_types[0]);
        res[start + pos] = res[start + pos] + sorted_container.front();
        sorted_container.pop_front();
        ++pos;
    }
    vm_min_cnt = std::min(vm_min_cnt, pos);
    max_vm_used = std::max(max_vm_used, vm_min_cnt);

    // process medium
    std::vector<bool> contains_medium(k_vm_min_count, false);
    std::vector<Container> medium_vms;
    while (!sorted_container.empty() && sorted_container.front().cpu_request > (1 / 3.0) * k_resource_limit) {
        medium_vms.push_back(sorted_container.front());
        sorted_container.pop_front();
    }
    for (pos = 0; pos < vm_min_cnt; ++pos) {
        if (medium_vms.empty()) {
            break;
        }
        if (medium_vms.front().cpu_request + res[start + pos].cpu_request > k_resource_limit ||
            medium_vms.front().memory_request + res[start + pos].memory_request > k_resource_limit) {
            continue;
        }
        int ind = 0;
        while (ind + 1 < medium_vms.size() &&
               medium_vms[ind + 1].cpu_request + res[start + pos].cpu_request <= k_resource_limit &&
               medium_vms[ind + 1].memory_request + res[start + pos].memory_request <= k_resource_limit) {
            ++ind;
        }
        res[start + pos] = res[start + pos] + medium_vms[ind];
        contains_medium[pos] = true;
        medium_vms.erase(medium_vms.begin() + ind);
    }
    // return unused medium vms
    while (!medium_vms.empty()) {
        sorted_container.push_front(medium_vms.back());
        medium_vms.pop_back();
    }

    // process small
    std::vector<Container> small_vms;
    while (!sorted_container.empty() && sorted_container.front().cpu_request > (1 / 6.0) * k_resource_limit) {
        small_vms.push_back(sorted_container.front());
        sorted_container.pop_front();
    }
    for (pos = vm_min_cnt - 1; pos > -1; --pos) {
        if (small_vms.size() < 2 || contains_medium[pos]) {
            break;
        }
        if (small_vms.front().cpu_request + small_vms[2].cpu_request + res[start + pos].cpu_request >
                k_resource_limit ||
            small_vms.front().memory_request + small_vms[2].memory_request + res[start + pos].memory_request >
                k_resource_limit) {
            continue;
        }
        res[start + pos] = res[start + pos] + small_vms.front();
        small_vms.erase(small_vms.begin());
        int ind = 0;
        while (ind + 1 < medium_vms.size() &&
               medium_vms[ind + 1].cpu_request + res[start + pos].cpu_request <= k_resource_limit &&
               medium_vms[ind + 1].memory_request + res[start + pos].memory_request <= k_resource_limit) {
            ++ind;
        }
        res[start + pos] = res[start + pos] + small_vms[ind];
        small_vms.erase(small_vms.begin() + ind);
    }
    // return unused small vms
    while (!small_vms.empty()) {
        sorted_container.push_front(small_vms.back());
        small_vms.pop_back();
    }

    // place what is left
    for (pos = 0; pos < vm_min_cnt; ++pos) {
        while (true) {
            if (sorted_container.empty()) {
                break;
            }
            if (sorted_container.back().cpu_request + res[start + pos].cpu_request > k_resource_limit ||
                sorted_container.back().memory_request + res[start + pos].memory_request > k_resource_limit) {
                break;
            }
            int ind = static_cast<int>(sorted_container.size()) - 1;
            while (ind - 1 >= 0 &&
                   sorted_container[ind - 1].cpu_request + res[start + pos].cpu_request <= k_resource_limit &&
                   sorted_container[ind - 1].memory_request + res[start + pos].memory_request <= k_resource_limit) {
                --ind;
            }
            res[start + pos] = res[start + pos] + sorted_container[ind];
            sorted_container.erase(sorted_container.begin() + ind);
        }
    }

    // ffd for the remaining containers
    for (auto& current : sorted_container) {
        bool found_placement = false;
        for (int i = 0; i < vm_min_cnt; ++i) {
            if (res[start + i].cpu_request + current.cpu_request <= k_resource_limit &&
                res[start + i].memory_request + current.memory_request <= k_resource_limit) {
                res[start + i] = res[start + i] + current;
                found_placement = true;
                break;
            }
        }
        if (!found_placement) {
            vm_min_cnt++;
            res.emplace_back(VM(vm_types[0]));
            res.back() = res.back() + current;
        }
    }
    max_vm_used = std::max(max_vm_used, vm_min_cnt);
}

}  // namespace solvers