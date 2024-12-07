#include "sort_utils.hpp"
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <algorithm>

void initializeVector(std::vector<int> &vec, std::size_t size)
{
    vec.resize(size);                     // Resize the vector to the desired size
    std::iota(vec.begin(), vec.end(), 0); // Fill the vector with sequential values starting from 0
}

std::string_view policyToString(Policy policy)
{
    switch (policy)
    {
    case Policy::Sequential:
        return "Sequential";
    case Policy::Vectorized:
        return "Vectorized";
    case Policy::Parallel:
        return "Parallel";
    case Policy::ParallelVectorized:
        return "Parallel & Vectorized";
    }
    throw std::logic_error("Unhandled Policy value");
}

ExecutionPolicyVariant getExecutionPolicy(Policy policy)
{
    switch (policy)
    {
    case Policy::Sequential:
        return se::seq;
    case Policy::Vectorized:
        return se::unseq;
    case Policy::Parallel:
        return se::par;
    case Policy::ParallelVectorized:
        return se::par_unseq;
    }
    throw std::logic_error("Unhandled Policy value");
}

double measure_sort(std::vector<int> &vec, Policy policy)
{
    try
    {
        // Get the appropriate execution policy
        auto exec_policy = getExecutionPolicy(policy);

        // Start timer
        auto start = std::chrono::high_resolution_clock::now();

        // Sort the vector in place
        std::visit([&](auto &&sort_policy)
                   { std::sort(sort_policy, vec.begin(), vec.end(), std::greater<int>()); }, exec_policy);

        // End timer
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate duration in milliseconds
        std::chrono::duration<double, std::milli> duration = end - start;

        // Return the duration count
        return duration.count();
    }
    catch (...)
    {
        // Handle any non-standard exceptions
        std::cerr << "Unknown error occurred in measure_sort for policy '"
                  << policyToString(policy) << "'\n";
        return -1.0; // Return an error value if an exception occurs
    }
}
