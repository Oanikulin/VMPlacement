#include <cmath>
#include <iomanip>
#include <iostream>
#include <isolver.hpp>
#include <memory>
#include <structures.hpp>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 4) {
        cerr << "Usage arguments: task_description host_description vm_types_description\n";
        return 1;
    }
    vector<Container> tasks = read_containers(argv[1]);
    vector<Host> hosts = read_hosts(argv[2]);
    vector<VM> vm_types = read_vm_types(argv[3]);
    assert(vm_types.size() == 1);
    double cpu_request = 0;
    double mem_request = 0;
    double cpu_owned = 0;
    double mem_owned = 0;
    int big_cpu_count = 0;
    int big_mem_count = 0;
    for (const auto& tmp : tasks) {
        cpu_request += tmp.cpu_request;
        mem_request += tmp.memory_request;
        if (tmp.cpu_request > (1.0 / 6)) {
            ++big_cpu_count;
        }
        if (tmp.memory_request > (1.0 / 6)) {
            ++big_mem_count;
        }
    }
    for (const auto& tmp : hosts) {
        cpu_owned += tmp.cpu_limit;
        mem_owned += tmp.m_limit;
    }

    // calculate memory and CPU request correlation
    double average_cpu = cpu_request / tasks.size();
    double average_mem = mem_request / tasks.size();
    double sum = 0;
    double x_deviation = 0;
    double y_deviation = 0;
    for (const auto& tmp : tasks) {
        sum += (tmp.cpu_request - average_cpu) * (tmp.memory_request - average_mem);
        x_deviation += (tmp.cpu_request - average_cpu) * (tmp.cpu_request - average_cpu);
        y_deviation += (tmp.memory_request - average_mem) * (tmp.memory_request - average_mem);
    }
    std::cerr << "CPU requested sum " << cpu_request << " out of " << cpu_owned << "\n Memory requested sum "
              << mem_request << " out of " << mem_owned << std::endl;
    std::cerr << "Requests with over sixth CPU (of max host)" << big_cpu_count << " out of " << tasks.size()
              << std::endl;
    std::cerr << "Requests with over sixth memory (of max host)" << big_mem_count << " out of " << tasks.size()
              << std::endl;
    std::cerr << "Memory and CPU correlation is " << (sum / (std::sqrt(x_deviation * y_deviation))) << std::endl;
    return 0;
}