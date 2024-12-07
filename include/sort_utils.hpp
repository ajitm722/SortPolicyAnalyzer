#pragma once

#include <vector>
#include <string_view>
#include <variant>
#include <execution>

namespace se = std::execution;

// To avoid weak string based APIs
enum class Policy
{
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

double measure_sort(std::vector<int> &vec, Policy policy);

void initializeVector(std::vector<int> &vec, std::size_t size);
