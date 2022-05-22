//
// Created by nikul on 22.02.2022.
//
#include "solver.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

#include "../structures.hpp"

namespace solvers {
    using std::vector;

//Naive VM selection policy - each requests is mapped onto the first VM type separately
    vector<VM>
    FirstFitDecreasingSolver::vm_generator(vector<Container> requests, const vector<Host> &hosts, const vector<VM> &vm_types) {
        vector<VM> res;
        res.reserve(requests.size());
        for (const auto &current: requests) {
            res.push_back(VM(vm_types[0]) + current);
        }
        return res;
    }

//Basic first fit algo - maps each VM onto first available Host, throws if it is impossible
    void FirstFitDecreasingSolver::vm_placement(vector <VM> &vms, std::vector<Host> &hosts) {
        std::sort(vms.begin(), vms.end(), [](VM a, VM b) {
            return a.cpu_request > b.cpu_request;
        });
        for (auto &current: vms) {
            for (int i = 0; i < hosts.size(); ++i) {
                if (hosts[i].cpu_limit >= current.cpu_request && hosts[i].m_limit >= current.memory_request) {
                    current.host = i;
                    hosts[i].Place(current);
                    break;
                }
            }
            if (current.host < 0)
                throw std::invalid_argument("First fit decreasing cannot fit VMs onto PMs");
        }
    }

    long double FirstFitDecreasingSolver::energy_consumption(const std::vector<Host> &hosts) {
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