cmake_minimum_required(VERSION 3.10)

project(ExecutionPolicyExample)

# Enable C++17 or later for modern features
set(CMAKE_CXX_STANDARD 17)

# Use FetchContent to download Google Test and Google Benchmark
include(FetchContent)

# Fetch Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0)
FetchContent_MakeAvailable(googletest)

# Fetch Google Benchmark
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.6.0)
FetchContent_MakeAvailable(benchmark)

# Include directories for header files
include_directories(include)

# Add the main executable
add_executable(
  main_exec src/main.cpp src/sort_utils.cpp) # Ensure sort_utils.cpp is included
                                             # here

# Link Google Test, Google Benchmark, and pthread (for Linux systems)
target_link_libraries(main_exec PRIVATE gtest gtest_main benchmark::benchmark
                                        pthread)

# Add tests
add_executable(test_policy tests/test_policy.cpp src/sort_utils.cpp
)# Include sort_utils.cpp for tests
target_link_libraries(test_policy PRIVATE gtest gtest_main pthread)

# Add benchmark
add_executable(benchmark_policy tests/benchmark_policy.cpp src/sort_utils.cpp
)# Include sort_utils.cpp for benchmarks
target_link_libraries(benchmark_policy PRIVATE benchmark::benchmark pthread)

# Enable testing
enable_testing()

# Add test to CTest
add_test(NAME TestExecutionPolicy COMMAND test_policy)
