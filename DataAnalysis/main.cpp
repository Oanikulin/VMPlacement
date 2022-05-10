#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

#include "../isolver.hpp"
#include "../structures.hpp"

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
    double cpu_request = 0;
    double mem_request = 0;
    double cpu_owned = 0;
    double mem_owned = 0;
    for (const auto& tmp : tasks) {
        cpu_request += tmp.cpu_request;
        mem_request += tmp.memory_request;
    }
    for (const auto& tmp : hosts) {
        cpu_owned += tmp.cpu_limit;
        mem_owned += tmp.m_limit;
    }
    std::cerr << "CPU requested sum " << cpu_request << " out of " << cpu_owned << "\n Memory requested sum "
    << mem_request << " out of " << mem_owned << std::endl;
    return 0;
}