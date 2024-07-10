#pragma once

#include <vector>

#include <isolver.hpp>
#include <structures.hpp>

namespace solvers {

    class FirstFitDecreasingSolver : public ISolver {
    public:
        std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts,
                                     const std::vector<VM> &vm_types) override;

        void vm_placement(std::vector<VM> &vms, std::vector<Host> &hosts) override;

        long double energy_consumption(const std::vector<Host> &hosts) override;

        virtual ~FirstFitDecreasingSolver() = default;
    };

}
