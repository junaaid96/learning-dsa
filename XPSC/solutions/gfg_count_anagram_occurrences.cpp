// XPSC Week 01 Day 01 - Count Occurences of Anagrams (GfG)
// Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
//
// Problem: count windows of txt that are anagrams of pat.
// Idea:    window of size |pat| with a 26-letter frequency array; track how many
//          letters currently have matching counts so each step is O(1).
// Time: O(n)   Space: O(26)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_count_anagram_occurrences.cpp && ./a.out

#include <array>
#include <cassert>
#include <iostream>
#include <string>

int countAnagrams(const std::string& txt, const std::string& pat) {
    const int k = static_cast<int>(pat.size());
    std::array<int, 26> need{};                       // need[c] = pat count - window count
    for (char c : pat) ++need[c - 'a'];
    int zero = 0;
    for (int x : need) zero += (x == 0);              // letters already balanced
    int ans = 0;
    auto change = [&](int c, int d) {                 // update one letter, keep 'zero' right
        if (need[c] == 0) --zero;
        need[c] += d;
        if (need[c] == 0) ++zero;
    };
    for (int i = 0; i < static_cast<int>(txt.size()); ++i) {
        change(txt[i] - 'a', -1);                     // enters window
        if (i >= k) change(txt[i - k] - 'a', +1);     // leaves window
        if (i >= k - 1 && zero == 26) ++ans;          // all 26 balanced -> anagram
    }
    return ans;
}

int main() {
    assert(countAnagrams("forxxorfxdofr", "for") == 3);
    assert(countAnagrams("aabaabaa", "aaba") == 4);
    std::cout << "gfg_count_anagram_occurrences: all tests passed\n";
    return 0;
}
