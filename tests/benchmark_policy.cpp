#include <benchmark/benchmark.h>     // Include Google Benchmark framework
#include <vector>                    // Include the vector container for data
#include <algorithm>                 // Include algorithm utilities (like std::sort if needed)
#include <iostream>                  // For std::cerr
#include <cstdlib>                   // For std::stoi
#include "../include/sort_utils.hpp" // Include the custom header file for sort utilities

// Benchmark for the sequential sorting policy
static void BenchmarkSequential(benchmark::State &state)
{
    std::vector<int> vec;
    std::size_t vector_size{static_cast<std::size_t>(state.range(0))}; // Access vector size from benchmark range and cast to std::size_t
    initializeVector(vec, vector_size);                                // Initialize the vector with vector_size

    for (auto _ : state)
    {
        measure_sort(vec, Policy::Sequential); // Measure sort using Sequential policy
    }
}

// Benchmark for the parallel sorting policy
static void BenchmarkParallel(benchmark::State &state)
{
    std::vector<int> vec;
    std::size_t vector_size{static_cast<std::size_t>(state.range(0))}; // Access vector size from benchmark range and cast to std::size_t
    initializeVector(vec, vector_size);                                // Initialize the vector with vector_size

    for (auto _ : state)
    {
        measure_sort(vec, Policy::Parallel); // Measure sort using Parallel policy
    }
}

// Benchmark for the vectorized sorting policy
static void BenchmarkVectorized(benchmark::State &state)
{
    std::vector<int> vec;
    std::size_t vector_size{static_cast<std::size_t>(state.range(0))}; // Access vector size from benchmark range and cast to std::size_t
    initializeVector(vec, vector_size);                                // Initialize the vector with vector_size

    for (auto _ : state)
    {
        measure_sort(vec, Policy::Vectorized); // Measure sort using Vectorized policy
    }
}

// Benchmark for the parallel-vectorized sorting policy
static void BenchmarkParallelVectorized(benchmark::State &state)
{
    std::vector<int> vec;
    std::size_t vector_size{static_cast<std::size_t>(state.range(0))}; // Access vector size from benchmark range and cast to std::size_t
    initializeVector(vec, vector_size);                                // Initialize the vector with vector_size

    for (auto _ : state)
    {
        measure_sort(vec, Policy::ParallelVectorized); // Measure sort using Parallel-Vectorized policy
    }
}

// Main function for Google Benchmark
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: Please provide a vector size as the first argument." << std::endl;
        return 1; // Return error if vector_size is not provided
    }

    // Convert the command-line argument to size_t
    std::size_t vector_size{std::stoull(argv[1])};

    // Print the conversion from milliseconds and seconds to nanoseconds
    std::cout << "1 millisecond = " << 1000000 << " nanoseconds" << std::endl;
    std::cout << "1 second = " << 1000000000 << " nanoseconds" << std::endl;

    // Initialize Google Benchmark and run the benchmarks
    benchmark::Initialize(&argc, argv);

    // Register the benchmarks with the vector size as an argument using the range
    BENCHMARK(BenchmarkSequential)->Arg(vector_size);         // Pass vector_size as range
    BENCHMARK(BenchmarkParallel)->Arg(vector_size);           // Pass vector_size as range
    BENCHMARK(BenchmarkVectorized)->Arg(vector_size);         // Pass vector_size as range
    BENCHMARK(BenchmarkParallelVectorized)->Arg(vector_size); // Pass vector_size as range

    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
