// Kadane's algorithm: maximum subarray sum in O(n).
//
// Problem:
//   Given an array (possibly with negative numbers), find the maximum sum
//   over all contiguous subarrays.
//
// Idea:
//   Maintain:
//     current = best sum of subarray ending at current index
//     best    = best seen so far
//
//   current = max(nums[i], current + nums[i])
//   best    = max(best, current)
//
// Compile: g++ -std=c++17 -O2 kadane_max_subarray.cpp -o kadane
// Run:     ./kadane

#include <iostream>
#include <vector>
#include <limits>

int maxSubArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Array must not be empty");
    }

    long long current = nums[0];
    long long best = nums[0];

    for (std::size_t i = 1; i < nums.size(); ++i) {
        const int value = nums[i];
        current = std::max(static_cast<long long>(value), current + value);
        best = std::max(best, current);
    }

    return static_cast<int>(best);
}

int main() {
    const std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << "Array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    const int result = maxSubArray(nums);
    std::cout << "Maximum subarray sum = " << result << "\n";

    return 0;
}

