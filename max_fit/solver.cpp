//
// Created by nikul on 22.02.2022.
//
#include "solver.hpp"

#include <algorithm>
#include <mutex>
#include <vector>
#include <thread>
#include <iostream>

#include "../structures.hpp"

namespace solvers {
    using std::vector;

//Naive VM selection policy - each requests is mapped onto the first VM type separately
    vector<VM>
    MaxFit::vm_generator(vector<Container> requests, const vector<Host> &hosts, const vector<VM> &vm_types) {
        vector<VM> res;
        res.reserve(requests.size());
        for (const auto &current: requests) {
            res.push_back(VM(vm_types[0]) + current);
        }
        return res;
    }

    void MaxFit::vm_placement(vector <VM> &vms, std::vector<Host> &hosts) {
        for (auto &current: vms) {
            int ans_ind = -1;
            int cpu_limit = -1;
            std::mutex mtx;
            std::vector<std::thread> tasks;
            for (int i = 0; i < hosts.size(); i += hosts.size() / k_thread_count) {
                int l = i;
                int r = std::min(hosts.size(), i + hosts.size() / k_thread_count);
                tasks.emplace_back([&ans_ind, &cpu_limit, &mtx, l, r, current = VM(current), &hosts](){
                    int local_ind = -1;
                    for (int i = l; i < r; ++i) {
                        if (hosts[i].cpu_limit < current.cpu_request || hosts[i].m_limit < current.memory_request) {
                            continue;
                        }
                        if (local_ind == -1 || hosts[i].cpu_limit + hosts[i].m_limit > hosts[local_ind].cpu_limit + hosts[local_ind].m_limit) {
                            local_ind = i;
                        }
                    }
                    std::lock_guard<std::mutex> lk(mtx);

                    if (local_ind < 0) {
                        return;
                    }

                    if (ans_ind == -1 || cpu_limit > hosts[local_ind].cpu_limit) {
                        ans_ind = local_ind;
                        cpu_limit = hosts[local_ind].cpu_limit;
                    }
                });
            }
            for (int i = 0; i < tasks.size(); ++i) {
                tasks[i].join();
            }

            if (ans_ind < 0)
                throw std::invalid_argument("Best fit cannot fit VMs onto PMs");
            current.host = ans_ind;
            hosts[ans_ind].Place(current);
        }
    }

    long double MaxFit::energy_consumption(const std::vector<Host> &hosts) {
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