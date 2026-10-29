// Longest Increasing Subsequence in O(n log n) (patience sorting).
//
// Problem:
//   Length of the longest strictly increasing subsequence.
// Links: https://leetcode.com/problems/longest-increasing-subsequence/
//        https://cses.fi/problemset/task/1145
//
// Idea:
//   tails[k] = smallest possible tail of an increasing subsequence of length
//   k+1. For each x, replace the first tail >= x (lower_bound) or append.
//   tails stays sorted, and its size is the LIS length.
//   (Use upper_bound for non-decreasing subsequences.)
//
// Time: O(n log n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_lis_nlogn.cpp -o lis && ./lis

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int lengthOfLIS(const std::vector<int>& a) {
    std::vector<int> tails;
    for (int x : a) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);  // first tail >= x
        if (it == tails.end()) tails.push_back(x);                 // extends longest
        else *it = x;                                              // better (smaller) tail
    }
    return static_cast<int>(tails.size());
}

int main() {
    assert(lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(lengthOfLIS({0, 1, 0, 3, 2, 3}) == 4);
    assert(lengthOfLIS({7, 7, 7, 7}) == 1);
    assert(lengthOfLIS({7, 3, 5, 3, 6, 2, 9, 8}) == 4);   // CSES sample
    std::cout << "dp_lis_nlogn: all tests passed\n";
    return 0;
}
