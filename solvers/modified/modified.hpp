#pragma once

#include <vector>
#include <algorithm>
#include <map>

#include <isolver.hpp>
#include <structures.hpp>
#include <baseline.hpp>

namespace solvers {

    class ModifiedSolver : public BaseSolver {
    public:

        ModifiedSolver() = default;

        explicit ModifiedSolver(int inp, int rc) : BaseSolver(inp), k_resource_limit(rc) {

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

        double k_resource_limit = 1;
    };

}
