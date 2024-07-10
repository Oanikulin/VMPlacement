#pragma once

#include <vector>
#include <mutex>

#include <isolver.hpp>
#include <structures.hpp>

namespace solvers {

    class MaxFit : public ISolver {
    public:

        MaxFit() = default;

        std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts,
                                     const std::vector<VM> &vm_types) override;

        void vm_placement(std::vector<VM> &vms, std::vector<Host> &hosts) override;

        long double energy_consumption(const std::vector<Host> &hosts) override;

        virtual ~MaxFit() = default;

    private:

        const int k_thread_count = 10;

    };


}
