#include <algorithm>
#include <best_fit_decreasing.hpp>
#include <iostream>
#include <mutex>
#include <structures.hpp>
#include <thread>
#include <vector>

namespace solvers {
using std::vector;

// Naive VM selection policy - each requests is mapped onto the first VM type separately
vector<VM> BestFitDecreasing::vm_generator(vector<Container> requests, const vector<Host> &hosts,
                                           const vector<VM> &vm_types) {
    vector<VM> res;
    res.reserve(requests.size());
    for (const auto &current : requests) {
        res.push_back(vm_types[0] + current);
    }
    return res;
}

// Basic first fit algo - maps each VM onto first available Host, throws if it is impossible
void BestFitDecreasing::vm_placement(vector<VM> &vms, std::vector<Host> &hosts) {
    std::sort(vms.begin(), vms.end(), [](VM a, VM b) { return a.cpu_request > b.cpu_request; });
    int ind = 0;
    for (auto &current : vms) {
        int ans_ind = -1;
        double cpu_limit = -1;
        std::mutex mtx;
        std::vector<std::thread> tasks;
        for (int i = 0; i < hosts.size(); i += hosts.size() / k_thread_count) {
            int l = i;
            int r = std::min(hosts.size(), i + hosts.size() / k_thread_count);
            tasks.emplace_back([&ans_ind, &cpu_limit, &mtx, l, r, current, &hosts]() {
                int local_ind = -1;
                for (int i = l; i < r; ++i) {
                    if (hosts[i].cpu_limit < current.cpu_request || hosts[i].m_limit < current.memory_request) {
                        continue;
                    }
                    if (local_ind == -1 ||
                        hosts[i].cpu_limit + hosts[i].m_limit < hosts[local_ind].cpu_limit + hosts[local_ind].m_limit) {
                        local_ind = i;
                    }
                }
                if (local_ind < 0) {
                    return;
                }
                std::lock_guard<std::mutex> lk(mtx);
                if (ans_ind == -1 || cpu_limit > hosts[local_ind].cpu_limit) {
                    ans_ind = local_ind;
                    cpu_limit = hosts[local_ind].cpu_limit;
                }
            });
        }
        for (auto &task : tasks) {
            task.join();
        }

        if (ans_ind < 0) {
            std::cerr << " First failed index " << ind << std::endl;
            throw std::invalid_argument("Best fit cannot fit VMs onto PMs");
        }
        ++ind;
        current.host = ans_ind;
        hosts[ans_ind].Place(current);
    }
}

long double BestFitDecreasing::energy_consumption(const std::vector<Host> &hosts) {
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