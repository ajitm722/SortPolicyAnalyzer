#include "sort_utils.hpp"
#include <vector>

int main() {
    // Initialize a large vector for testing
    std::vector<int> vec(2'000'000);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = vec.size() - i; // Reverse-sorted initially
    }

    // Measure sort times for different policies
    measure_sort(vec, Policy::Sequential);
    measure_sort(vec, Policy::Vectorized);
    measure_sort(vec, Policy::Parallel);
    measure_sort(vec, Policy::ParallelVectorized);

    return 0;
}

