// XPSC Week 03 Day 01 - Longest K unique characters substring (GfG)
// Link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
//
// Problem: longest substring with exactly k distinct characters (-1 if none).
// Idea:    variable window; shrink from the left while distinct > k, record when == k.
// Time: O(n)   Space: O(26)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_longest_k_unique_substring.cpp && ./a.out

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>

int longestKUnique(const std::string& s, int k) {
    std::array<int, 26> cnt{};
    int distinct = 0, best = -1;
    for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
        if (cnt[s[r] - 'a']++ == 0) ++distinct;              // new letter in window
        while (distinct > k) if (--cnt[s[l++] - 'a'] == 0) --distinct;   // shrink
        if (distinct == k) best = std::max(best, r - l + 1);
    }
    return best;
}

int main() {
    assert(longestKUnique("aabacbebebe", 3) == 7);           // "cbebebe"
    assert(longestKUnique("aaaa", 2) == -1);
    std::cout << "gfg_longest_k_unique_substring: all tests passed\n";
    return 0;
}
