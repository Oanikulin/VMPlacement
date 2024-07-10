#include <iomanip>
#include <iostream>
#include <isolver.hpp>
#include <memory>
#include <modified.hpp>
#include <run.hpp>
#include <structures.hpp>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 4) {
        cerr << "Usage arguments: task_description host_description vm_types_description\n";
        return 1;
    }
    std::cerr << "Start" << std::endl;
    vector<Container> tasks = read_containers(argv[1]);
    std::cerr << "container read " << tasks.size() << std::endl;
    vector<Host> hosts = read_hosts(argv[2]);
    std::cerr << "hosts read " << hosts.size() << std::endl;
    vector<VM> vm_types = read_vm_types(argv[3]);
    std::cerr << "vms read" << std::endl;
    assert(vm_types.size() == 1);
    unique_ptr<solvers::ISolver> solver = make_unique<solvers::ModifiedSolver>(3, 1);
    run(solver, tasks, hosts, vm_types);
    return 0;
}