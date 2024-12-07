#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

#include <vector>
#include <string_view>
#include <variant>
#include <execution>


namespace se = std::execution;

enum class Policy {
    Sequential,
    Vectorized,
    Parallel,
    ParallelVectorized
};

std::string_view policyToString(Policy policy);

using ExecutionPolicyVariant = std::variant<
    se::sequenced_policy,
    se::unsequenced_policy,
    se::parallel_policy,
    se::parallel_unsequenced_policy>;

ExecutionPolicyVariant getExecutionPolicy(Policy policy);

void measure_sort(const std::vector<int>& vec, Policy policy);

#endif // SORT_UTILS_HPP

