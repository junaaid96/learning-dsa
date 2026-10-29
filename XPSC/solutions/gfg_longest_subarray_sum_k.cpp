// XPSC Week 03 Day 01 - Longest Sub-Array with Sum K (GfG)
// Link: https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
//
// Problem: length of the longest subarray summing to K (values may be negative).
// Idea:    prefix sums + map of FIRST index where each prefix appeared;
//          sum(j+1..i) = K  <=>  prefix[j] = prefix[i] - K.
//          (Sliding window only works when all values are positive.)
// Time: O(n) average   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_longest_subarray_sum_k.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

int longestSumK(const std::vector<int>& a, long long K) {
    std::unordered_map<long long, int> first{{0, -1}};   // empty prefix at index -1
    long long pre = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        pre += a[i];
        auto it = first.find(pre - K);
        if (it != first.end()) best = std::max(best, i - it->second);
        first.emplace(pre, i);                            // keeps the earliest index only
    }
    return best;
}

int main() {
    assert(longestSumK({10, 5, 2, 7, 1, 9}, 15) == 4);
    assert(longestSumK({-1, 2, 3}, 6) == 0);
    assert(longestSumK({-5, 8, -14, 2, 4, 12}, -5) == 5);
    std::cout << "gfg_longest_subarray_sum_k: all tests passed\n";
    return 0;
}
