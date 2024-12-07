#include <gtest/gtest.h>             // Include the Google Test framework header for unit testing
#include <vector>                    // Include the vector container for storing data
#include <algorithm>                 // Include algorithm utilities (like std::sort if needed)
#include "../include/sort_utils.hpp" // Include the custom header file for sort utilities

// Check if the results are reverse sorted for different policies

// Test case for the Sequential policy
TEST(SortPolicyTest, SequentialSort) // Define a test case named "SequentialSort" under the "SortPolicyTest" test suite
{
    // Input vector with unsorted elements
    std::vector<int> vec{5, 2, 8, 3, 1};

    // Sort the vector using the Sequential policy
    measure_sort(vec, Policy::Sequential);

    // Expected sorted result in descending order
    std::vector<int> sorted_vec{8, 5, 3, 2, 1};

    // Assert that the sorted vector matches the expected result
    EXPECT_EQ(vec, sorted_vec);
}

// Test case for the Parallel policy
TEST(SortPolicyTest, ParallelSort) // Define a test case named "ParallelSort" under the "SortPolicyTest" test suite
{
    // Input vector with unsorted elements
    std::vector<int> vec{5, 2, 8, 3, 1};

    // Sort the vector using the Parallel policy
    measure_sort(vec, Policy::Parallel);

    // Expected sorted result in descending order
    std::vector<int> sorted_vec{8, 5, 3, 2, 1};

    // Assert that the sorted vector matches the expected result
    EXPECT_EQ(vec, sorted_vec);
}

// Test case for the Vectorized policy
TEST(SortPolicyTest, VectorizedSort) // Define a test case named "VectorizedSort" under the "SortPolicyTest" test suite
{
    // Input vector with unsorted elements
    std::vector<int> vec{5, 2, 8, 3, 1};

    // Sort the vector using the Vectorized policy
    measure_sort(vec, Policy::Vectorized);

    // Expected sorted result in descending order
    std::vector<int> sorted_vec{8, 5, 3, 2, 1};

    // Assert that the sorted vector matches the expected result
    EXPECT_EQ(vec, sorted_vec);
}

// Test case for the Parallel-Vectorized policy
TEST(SortPolicyTest, ParallelVectorizedSort) // Define a test case named "ParallelVectorizedSort" under the "SortPolicyTest" test suite
{
    // Input vector with unsorted elements
    std::vector<int> vec{5, 2, 8, 3, 1};

    // Sort the vector using the Parallel-Vectorized policy
    measure_sort(vec, Policy::ParallelVectorized);

    // Expected sorted result in descending order
    std::vector<int> sorted_vec{8, 5, 3, 2, 1};

    // Assert that the sorted vector matches the expected result
    EXPECT_EQ(vec, sorted_vec);
}
