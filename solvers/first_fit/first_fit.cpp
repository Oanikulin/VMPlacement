#include <first_fit.hpp>
#include <iostream>
#include <structures.hpp>
#include <vector>

namespace solvers {
using std::vector;

// Naive VM selection policy - each requests is mapped onto the first VM type separately
vector<VM> FirstFitSolver::vm_generator(vector<Container> requests, const vector<Host> &hosts,
                                        const vector<VM> &vm_types) {
    vector<VM> res;
    res.reserve(requests.size());
    for (const auto &current : requests) {
        res.push_back(VM(vm_types[0]) + current);
    }
    return res;
}

// Basic first fit algo - maps each VM onto first available Host, throws if it is impossible
void FirstFitSolver::vm_placement(vector<VM> &vms, std::vector<Host> &hosts) {
    for (auto &current : vms) {
        for (int i = 0; i < hosts.size(); ++i) {
            if (hosts[i].cpu_limit >= current.cpu_request && hosts[i].m_limit >= current.memory_request) {
                current.host = i;
                hosts[i].Place(current);
                break;
            }
        }
        if (current.host < 0) throw std::invalid_argument("First fit cannot fit VMs onto PMs");
    }
}

long double FirstFitSolver::energy_consumption(const std::vector<Host> &hosts) {
    long double ans = 0;
    for (const auto &current : hosts) {
        if (current.is_active) {
            ans += current.e_idle + (current.e_full - current.e_idle) *
                                        ((current.cpu_max_limit - current.cpu_limit) * 1.0 / current.cpu_max_limit);
        }
    }
    return ans;
}

}  // namespace solvers