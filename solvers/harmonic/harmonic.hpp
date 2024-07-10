//
// Created by nikul on 22.02.2022.
//

#ifndef HARMONIC_FUNCTIONS_INCLUDED
#define HARMONIC_FUNCTIONS_INCLUDED

#include <vector>
#include <algorithm>
#include <map>

#include <isolver.hpp>
#include <structures.hpp>
#include <baseline.hpp>

namespace solvers {

    class HarmonicSolver : public BaseSolver {
    public:

        HarmonicSolver() = default;

        explicit HarmonicSolver(int inp, int rc, int seg_count) : BaseSolver(inp), k_resource_limit(rc), k_segment_count(seg_count) {
            assert(k_segment_count > 0);
        }

        HarmonicSolver(HarmonicSolver&) = default;

        HarmonicSolver(HarmonicSolver&&) = default;

        virtual std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts, const std::vector<VM> &vm_types) override;

        virtual ~HarmonicSolver() override = default;

    private:
        void vm_generate_single(std::vector<Container> requests, std::vector<VM>& res,
                                double max_cpu_host, double max_memory_host, const std::vector<VM> &vm_types) override;

        /*const int k_vm_min_count = 3;
        int max_vm_used = 0;
        const double k_w1 = 0.5;
        const double  k_w2 = 0.5;*/

        const double k_resource_limit = 1;
        const int k_segment_count = 1;
    };

}
#endif
