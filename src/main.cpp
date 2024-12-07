#include "sort_utils.hpp"
#include <vector>
#include <numeric>
#include <iostream>

int main(int argc, char *argv[])
{
    // Check if the user provided the vector size as a command-line argument
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <vector_size>" << std::endl;
        return 1; // Return an error code if vector_size is not provided
    }

    // Convert the argument to std::size_t
    const std::size_t vector_size = std::stoull(argv[1]);

    // Create a vector to be reused
    std::vector<int> vec;

    // Measure reverse-sort times for different policies and capture the durations
    initializeVector(vec, vector_size);
    std::cout << "Sequential sort took " << measure_sort(vec, Policy::Sequential) << " ms\n";

    initializeVector(vec, vector_size);
    std::cout << "Vectorized sort took " << measure_sort(vec, Policy::Vectorized) << " ms\n";

    initializeVector(vec, vector_size);
    std::cout << "Parallel sort took " << measure_sort(vec, Policy::Parallel) << " ms\n";

    initializeVector(vec, vector_size);
    std::cout << "Parallel-Vectorized sort took " << measure_sort(vec, Policy::ParallelVectorized) << " ms\n";

    return 0;
}
