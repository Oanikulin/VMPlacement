//
// Created by nikul on 12.05.2022.
//

#include "structures.hpp"
#include "isolver.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <chrono>

#ifndef SIMULATOR_RUN_HPP
#define SIMULATOR_RUN_HPP

using std::vector;
using std::fixed;
using std::setprecision;

void run(std::unique_ptr<solvers::ISolver>& solver, vector<Container> tasks, vector<Host> hosts, vector<VM> vm_types) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto vms = solver->vm_generator(tasks, hosts, vm_types);
    std::chrono::steady_clock::time_point vms_generated = std::chrono::steady_clock::now();
    std::cerr << "vms generated" << std::endl;
    solver->vm_placement(vms, hosts);
    if (!get_correctness(tasks, vms, hosts)) {
        assert(false);
    }
    std::chrono::steady_clock::time_point vms_placed = std::chrono::steady_clock::now();
    long double energy = solver->energy_consumption(hosts);
    std::cout << "Number of generated VMs " << vms.size() << std::endl;
    std::cout << fixed << setprecision(10) << "Energy consumption of mapping strategy is " << energy << "\n";
    std::cout << fixed << setprecision(10) << "CPU utilisation is " << get_cpu_utilisation(hosts) << std::endl;
    std::cout << fixed << setprecision(10) << "Memory utilisation is " << get_memory_utilisation(hosts) << std::endl;
    std::cout << fixed << setprecision(10) << "Total active CPU limit " << get_active_cpu(hosts) << std::endl;
    std::cout << fixed << setprecision(10) << "Active hosts count " << get_active_hosts_count(hosts) << std::endl;
    std::cout << "Time to generate vms = " << std::chrono::duration_cast<std::chrono::microseconds>(vms_generated - begin).count() << "[µs]" << std::endl;
    std::cout << "Time to place vms = " << std::chrono::duration_cast<std::chrono::microseconds>(vms_placed - vms_generated).count() << "[µs]" << std::endl;
    std::cout << "Total time = " << std::chrono::duration_cast<std::chrono::microseconds>(vms_placed - begin).count() << "[µs]" << std::endl;
}
#endif //SIMULATOR_RUN_HPP
