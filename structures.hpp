//
// Created by nikul on 22.02.2022.
//

#ifndef STRUCTURES_INCLUDED
#define STRUCTURES_INCLUDED

#include <cassert>
#include <fstream>
#include <vector>

struct Container {
    double cpu_request;
    double memory_request;
    long long job;
    int os;
    int vm;

    explicit Container(double cpu = 0, double memory = 0, long long job = 0, int os = 0, int vm = -1) noexcept:
    cpu_request(cpu),
    memory_request(memory),
    job(job),
    os(os),
    vm(vm) {
        assert(os <= 3);
    }
};

std::vector<Container> read_containers(std::ifstream&& in_file);

struct VM {
    double cpu_overhead;
    double memory_overhead;
    double cpu_request;
    double memory_request;
    int os;
    long long job;
    int host;

    explicit VM(double cpu_overhead, double memory_overhead) noexcept:
    cpu_overhead(cpu_overhead),
    cpu_request(cpu_overhead),
    memory_overhead(memory_overhead),
    memory_request(memory_overhead),
    os(-1),
    job(-1),
    host(-1) {

    }

    friend VM operator + (VM lhs, const Container& rhs) {
        if (rhs.os != lhs.os && lhs.os != -1)
            throw std::invalid_argument("OS different from an already used");
        if (lhs.job != -1 && lhs.job != rhs.job)
            throw std::invalid_argument("Job from an already used");
        lhs.cpu_request += rhs.cpu_request;
        lhs.memory_request += rhs.memory_request;
        lhs.os = rhs.os;
        lhs.job = rhs.job;
        return lhs;
    }
};

std::vector<VM> read_vm_types(std::ifstream&& in_file);

struct Host {
    double e_idle = 0;
    double e_full = 0;
    double m_limit = 0;
    double m_max_limit = 0;
    double cpu_limit = 0;
    double cpu_max_limit = 0;
    bool is_active = false;

    void Place(VM vm);
};

std::vector<Host> read_hosts(std::ifstream&& in_file);

double get_cpu_utilisation(const std::vector<Host>& in);

double get_memory_utilisation(const std::vector<Host>& in);

int get_active_hosts_count(const std::vector<Host>& in);

bool get_correctness(const std::vector<Container>& cont, const std::vector<VM>& vms, const std::vector<Host>& hosts);
#endif