//
// Created by nikul on 26.04.2022.
//

#ifndef SIMULATOR_ISOLVER_HPP
#define SIMULATOR_ISOLVER_HPP

#include <vector>

#include "structures.hpp"
namespace solvers {

    class ISolver {
    public:
        virtual std::vector<VM> vm_generator(std::vector<Container> requests, const std::vector<Host> &hosts,
                                             const std::vector<VM> &vm_types) = 0;

        virtual void vm_placement(std::vector<VM> vms, std::vector<Host> &hosts) = 0;

        virtual long double energy_consumption(const std::vector<Host> &hosts) = 0;

        virtual ~ISolver() = default;
    };

}
#endif //SIMULATOR_ISOLVER_HPP
