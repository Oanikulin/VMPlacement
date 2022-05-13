#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

#include "../isolver.hpp"
#include "../structures.hpp"
#include "modified_solver.hpp"
#include "../run.hpp"

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
    unique_ptr<solvers::ISolver> solver = make_unique<solvers::ModifiedSolver>();
    run(solver, tasks, hosts, vm_types);
    return 0;
}