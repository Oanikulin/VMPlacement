#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

#include "../isolver.hpp"
#include "../structures.hpp"
#include "solver.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	if (argc < 4) {
		cerr << "Usage arguments: task_description host_description vm_types_description\n";
		return 1;
	}
    std::cerr << "Start" << std::endl;
    vector<Container> tasks = read_containers(ifstream(argv[1]));
    std::cerr << "container read " << tasks.size() << std::endl;
    vector<Host> hosts = read_hosts(ifstream(argv[2]));
    std::cerr << "hosts read " << hosts.size() << std::endl;
    vector<VM> vm_types = read_vm_types(ifstream(argv[3]));
    std::cerr << "vms read" << std::endl;
    assert(vm_types.size() == 1);
    unique_ptr<solvers::ISolver> solver = make_unique<solvers::FirstFitSolver>();
    auto vms = solver->vm_generator(tasks, hosts, vm_types);
    std::cerr << "vms generated" << std::endl;
    solver->vm_placement(vms, hosts);
    long double energy = solver->energy_consumption(hosts);
    std::cout << fixed << setprecision(10) << "Energy consumption of mapping strategy is " << energy << "\n";
    std::cout << fixed << setprecision(10) << "CPU utilisation is " << get_cpu_utilisation(hosts) << std::endl;

    return 0;
}