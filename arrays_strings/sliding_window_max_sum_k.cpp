// Sliding window: maximum sum subarray of fixed size k.
//
// Problem:
//   Given an array of integers and an integer k, find the maximum sum
//   of any contiguous subarray of size k.
//
// Naive:  For each starting index, sum k elements -> O(n * k).
// Window: Maintain current window sum and slide by removing left element
//         and adding new right element -> O(n).
//
// Compile: g++ -std=c++17 -O2 sliding_window_max_sum_k.cpp -o sliding_window_k
// Run:     ./sliding_window_k

#include <iostream>
#include <vector>
#include <limits>

int maxSubarraySumOfSizeK(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (k <= 0 || k > n) {
        throw std::invalid_argument("k must be in range [1, n]");
    }

    long long windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }

    long long best = windowSum;
    for (int right = k; right < n; ++right) {
        windowSum += nums[right];
        windowSum -= nums[right - k];
        if (windowSum > best) {
            best = windowSum;
        }
    }

    return static_cast<int>(best);
}

int main() {
    const std::vector<int> nums{1, 4, 2, 10, 2, 3, 1, 0, 20};
    const int k = 4;

    try {
        const int result = maxSubarraySumOfSizeK(nums, k);
        std::cout << "Array: ";
        for (int value : nums) {
            std::cout << value << ' ';
        }
        std::cout << "\nWindow size k = " << k << "\n";
        std::cout << "Maximum sum of any subarray of size k: " << result << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}

