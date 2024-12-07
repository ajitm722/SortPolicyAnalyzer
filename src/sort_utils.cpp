#include "sort_utils.hpp"
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <algorithm>

std::string_view policyToString(Policy policy) {
    switch (policy) {
    case Policy::Sequential: return "Sequential";
    case Policy::Vectorized: return "Vectorized";
    case Policy::Parallel: return "Parallel";
    case Policy::ParallelVectorized: return "Parallel & Vectorized";
    }
    throw std::logic_error("Unhandled Policy value");
}

ExecutionPolicyVariant getExecutionPolicy(Policy policy) {
    switch (policy) {
    case Policy::Sequential: return se::seq;
    case Policy::Vectorized: return se::unseq;
    case Policy::Parallel: return se::par;
    case Policy::ParallelVectorized: return se::par_unseq;
    }
    throw std::logic_error("Unhandled Policy value");
}

void measure_sort(const std::vector<int>& vec, Policy policy) {
    try {
        std::vector<int> temp_vec = vec;

        auto exec_policy = getExecutionPolicy(policy);

        auto start = std::chrono::high_resolution_clock::now();

        std::visit([&](auto&& sort_policy) {
            std::sort(sort_policy, temp_vec.begin(), temp_vec.end(), std::greater<int>());
        }, exec_policy);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << policyToString(policy) << " took " << duration.count() << " ms\n";
    } catch (...) {
        std::cerr << "Unknown error occurred in measure_sort for policy '" 
                  << policyToString(policy) << "'\n";
    }
}

