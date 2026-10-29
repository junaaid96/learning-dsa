// Maximum Average Subarray I (fixed-size sliding window).
//
// Problem:
//   Find the maximum sum (average) of any contiguous subarray of length k.
// Link: https://leetcode.com/problems/maximum-average-subarray-i/
//
// Idea:
//   Sum the first k elements, then slide: add the new element, subtract the
//   element that leaves. Every window is evaluated in O(1).
//
// Time: O(n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra fixed_window_max_average.cpp -o fw && ./fw

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

double findMaxAverage(const std::vector<int>& nums, int k) {
    long long window = 0;
    for (int i = 0; i < k; ++i) window += nums[i];   // first window [0, k)
    long long best = window;
    for (int i = k; i < static_cast<int>(nums.size()); ++i) {
        window += nums[i] - nums[i - k];             // slide by one: in nums[i], out nums[i-k]
        best = std::max(best, window);
    }
    return static_cast<double>(best) / k;
}

int main() {
    assert(std::fabs(findMaxAverage({1, 12, -5, -6, 50, 3}, 4) - 12.75) < 1e-9);
    assert(std::fabs(findMaxAverage({5}, 1) - 5.0) < 1e-9);
    std::cout << "fixed_window_max_average: all tests passed\n";
    return 0;
}
