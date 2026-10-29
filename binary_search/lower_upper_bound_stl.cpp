// STL binary search tools: lower_bound, upper_bound, equal_range.
//
// Problem (Find First and Last Position of Element in Sorted Array):
//   Return [first, last] index of target in a sorted array, or [-1, -1].
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// Idea:
//   lower_bound -> first element >= target.
//   upper_bound -> first element >  target.
//   The target occupies [lower, upper).
//
// Time: O(log n)    Space: O(1)
//
// Compile: g++ -std=c++17 -Wall -Wextra lower_upper_bound_stl.cpp -o lub && ./lub

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> searchRange(const std::vector<int>& a, int target) {
    auto lo = std::lower_bound(a.begin(), a.end(), target);  // first >= target
    auto hi = std::upper_bound(a.begin(), a.end(), target);  // first > target
    if (lo == hi) return {-1, -1};                           // empty range: not present
    return {static_cast<int>(lo - a.begin()), static_cast<int>(hi - a.begin()) - 1};
}

int main() {
    assert((searchRange({5, 7, 7, 8, 8, 10}, 8) == std::vector<int>{3, 4}));
    assert((searchRange({5, 7, 7, 8, 8, 10}, 6) == std::vector<int>{-1, -1}));
    assert((searchRange({}, 0) == std::vector<int>{-1, -1}));
    std::cout << "lower_upper_bound_stl: all tests passed\n";
    return 0;
}
