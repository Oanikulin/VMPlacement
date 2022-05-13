//
// Created by nikul on 22.02.2022.
//

#ifndef MODIFIED_SOLVER_FUNCTIONS_INCLUDED
#define MODIFIED_SOLVER_FUNCTIONS_INCLUDED

#include <vector>
#include <algorithm>
#include <map>

#include "../isolver.hpp"
#include "../structures.hpp"
#include "../baseline_solver/baseline_solver.hpp"

namespace solvers {

    class ModifiedSolver : public BaseSolver {
    public:

        ModifiedSolver() = default;

        explicit ModifiedSolver(int inp) : BaseSolver(inp) {

        }

        ModifiedSolver(ModifiedSolver&) = default;

        ModifiedSolver(ModifiedSolver&&) = default;

        virtual std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts, const std::vector<VM> &vm_types) override;

        virtual ~ModifiedSolver() override = default;

    private:
        void vm_generate_single(std::vector<Container> requests, std::vector<VM>& res,
                                double max_cpu_host, double max_memory_host, const std::vector<VM> &vm_types) override;

        /*const int k_vm_min_count = 3;
        int max_vm_used = 0;
        const double k_w1 = 0.5;
        const double  k_w2 = 0.5;*/

    };

}
#endif
