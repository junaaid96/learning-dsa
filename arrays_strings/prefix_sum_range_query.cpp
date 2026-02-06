// Prefix sum: answer range sum queries in O(1) after O(n) preprocessing.
//
// Problem:
//   Given an array nums and many queries [l, r], compute sum(nums[l..r]).
//
// Idea:
//   Build prefix[i] = sum of nums[0..i-1], with prefix[0] = 0.
//   Then sum(l..r) = prefix[r + 1] - prefix[l].
//
// Compile: g++ -std=c++17 -O2 prefix_sum_range_query.cpp -o prefix_sum
// Run:     ./prefix_sum

#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<long long> buildPrefixSum(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    return prefix;
}

long long rangeSum(const std::vector<long long>& prefix, int left, int right) {
    const int n = static_cast<int>(prefix.size()) - 1;
    if (left < 0 || right < left || right >= n) {
        throw std::out_of_range("Invalid range for rangeSum");
    }
    return prefix[right + 1] - prefix[left];
}

int main() {
    const std::vector<int> nums{2, 4, 5, 7, 9, 3};
    const std::vector<std::pair<int, int>> queries{{0, 2}, {1, 4}, {2, 5}};

    std::cout << "Array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\n\n";

    const std::vector<long long> prefix = buildPrefixSum(nums);

    for (const auto& q : queries) {
        const int l = q.first;
        const int r = q.second;
        const long long sum = rangeSum(prefix, l, r);
        std::cout << "Sum of nums[" << l << ".." << r << "] = " << sum << "\n";
    }

    return 0;
}

