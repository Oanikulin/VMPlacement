//
// Created by nikul on 23.02.2022.
//
#include "structures.hpp"

#include <iostream>
#include <fstream>
#include <vector>

std::vector<Container> read_containers(std::ifstream&& in_file) {
    std::vector<Container> res;
    double cpu_req;
    double mem_req;
    long long job;
    int os;
    while (in_file >> cpu_req >> mem_req >> job >> os) {
        //std::cerr << "read " << std::endl;
        if (cpu_req == 0 || mem_req == 0) {
            continue;
        }
        if (cpu_req > 1 || mem_req > 1) {
            continue;
        }
        res.emplace_back(Container(cpu_req , mem_req , job, os));
    }
    return res;
}

void Host::Place(VM vm) {
    cpu_limit -= vm.cpu_request;
    m_limit -= vm.memory_request;
    is_active = true;
}

std::vector<Host> read_hosts(std::ifstream&& in_file) {
    std::vector<Host> res;
    double cpu_cap;
    double mem_cap;
    double e_idle;
    double e_full;
    while (in_file >> mem_cap >> cpu_cap >> e_idle >> e_full) {
        res.emplace_back(Host{e_idle, e_full, mem_cap, mem_cap,cpu_cap, cpu_cap, false});
    }
    return res;
}

std::vector<VM> read_vm_types(std::ifstream&& in_file) {
    std::vector<VM> res;
    double cpu_over;
    double mem_over;
    while (in_file >> cpu_over >> mem_over) {
        res.emplace_back(VM(cpu_over, mem_over));
    }
    return res;
}

double get_cpu_utilisation(const std::vector<Host>& in) {
    double total = 0;
    double available = 0;
    for (const auto& tmp : in) {
        if (!tmp.is_active) {
            continue;
        }
        total += tmp.cpu_max_limit;
        available += tmp.cpu_limit;
    }
    return (total - available) / total;
}

double get_memory_utilisation(const std::vector<Host>& in) {
    double total = 0;
    double available = 0;
    for (const auto& tmp : in) {
        if (!tmp.is_active) {
            continue;
        }
        total += tmp.m_max_limit;
        available += tmp.m_limit;
    }
    return (total - available) / total;
}

int get_active_hosts_count(const std::vector<Host>& in) {
    int cnt = 0;
    for (const auto& tmp : in) {
        if (!tmp.is_active) {
            continue;
        }
        cnt += 1;
    }
    return cnt;
}

bool get_correctness(const std::vector<Container>& cont, const std::vector<VM>& vms, const std::vector<Host>& hosts) {
    double cpu_needed = 0;
    double mem_needed = 0;
    double mem_vms = 0;
    double cpu_vms = 0;
    for (const auto& tmp : cont) {
        cpu_needed += tmp.cpu_request;
        mem_needed += tmp.memory_request;
    }
    for (const auto& tmp : vms) {
        mem_vms += tmp.memory_request;
        cpu_vms += tmp.cpu_request;
        assert(tmp.host != -1);
    }
    assert(mem_vms >= mem_needed);
    assert(cpu_vms >= cpu_needed);
    return true;
}