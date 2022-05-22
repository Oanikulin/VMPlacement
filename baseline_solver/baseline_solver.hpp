//
// Created by nikul on 22.02.2022.
//

#ifndef BASELINE_SOLVER_FUNCTIONS_INCLUDED
#define BASELINE_SOLVER_FUNCTIONS_INCLUDED

#include <vector>
#include <algorithm>
#include <map>

#include "../isolver.hpp"
#include "../structures.hpp"

namespace solvers {

    class BaseSolver : public ISolver {
    public:

        BaseSolver() = default;

        explicit BaseSolver(int inp) : k_vm_min_count(inp) {

        }

        BaseSolver(BaseSolver&) = default;

        BaseSolver(BaseSolver&&) = default;

        std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts, const std::vector<VM> &vm_types) override;

        void vm_placement(std::vector<VM> &vms, std::vector<Host> &hosts) override;

        long double energy_consumption(const std::vector<Host> &hosts) override;

        ~BaseSolver() override = default;

    protected:
        virtual void vm_generate_single(std::vector<Container> requests, std::vector<VM>& res,
                                double max_cpu_host, double max_memory_host, const std::vector<VM> &vm_types);

        const int k_vm_min_count = 3;
        int max_vm_used = 0;
        const double k_w1 = 0.5;
        const double  k_w2 = 0.5;

    };

}
#endif
