// Monotonic deque: sliding window maximum in O(n).
//
// Problem:
//   Given an array nums and an integer k, return the maximum
//   for each contiguous subarray (window) of size k.
//
// Idea:
//   Maintain a deque of indices where the corresponding values
//   are in decreasing order. The front is always the maximum
//   in the current window.
//
// Compile: g++ -std=c++17 -O2 deque_sliding_window_maximum.cpp -o window_max
// Run:     ./window_max

#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (k <= 0 || k > n) {
        throw std::invalid_argument("k must be in range [1, n]");
    }

    std::deque<int> dq; // holds indices, values decreasing
    std::vector<int> result;
    result.reserve(static_cast<std::size_t>(n - k + 1));

    for (int i = 0; i < n; ++i) {
        // Remove indices that are out of this window
        const int windowStart = i - k + 1;
        if (!dq.empty() && dq.front() < windowStart) {
            dq.pop_front();
        }

        // Maintain decreasing order: remove smaller values from back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Window becomes valid after we see k elements
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    const std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    const int k = 3;

    const std::vector<int> res = maxSlidingWindow(nums, k);

    std::cout << "Array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\nWindow size k = " << k << "\n";

    std::cout << "Sliding window maximums: ";
    for (int value : res) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    return 0;
}

