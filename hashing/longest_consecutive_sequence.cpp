// Longest Consecutive Sequence.
//
// Problem:
//   Given an unsorted array, return the length of the longest run of
//   consecutive integers (x, x+1, x+2, ...) in O(n).
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
//
// Idea:
//   Put all numbers in a hash set. Only START counting from x when x-1 is not
//   in the set (x is the beginning of a run). Each number is visited O(1) times.
//
// Time: O(n) average    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra longest_consecutive_sequence.cpp -o lcs && ./lcs

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());  // O(1) membership tests
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;                      // not a run start -> skip
        int len = 1;                                       // x itself
        while (s.count(x + len)) ++len;                    // extend run x, x+1, ...
        best = std::max(best, len);                        // keep the longest
    }
    return best;
}

int main() {
    assert(longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
    assert(longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) == 9);
    assert(longestConsecutive({}) == 0);
    std::cout << "longest_consecutive_sequence: all tests passed\n";
    return 0;
}
