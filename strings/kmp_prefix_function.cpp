// KMP / prefix function: find all occurrences of a pattern in O(n + m).
//
// Problem:
//   Count (or list) occurrences of pattern p in text s.
// Links: https://cses.fi/problemset/task/1753  (String Matching)
//        https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//        https://leetcode.com/problems/shortest-palindrome/
//
// Idea:
//   pi[i] = length of the longest proper prefix of s[0..i] that is also a
//   suffix. On mismatch fall back to pi[k-1] instead of restarting.
//   Match p in s by computing pi on p + '#' + s: positions where pi == |p|.
//
// Time: O(n + m)    Space: O(n + m)
//
// Compile: g++ -std=c++17 -Wall -Wextra kmp_prefix_function.cpp -o kmp && ./kmp

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefixFunction(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int k = pi[i - 1];                        // best border of the previous prefix
        while (k > 0 && s[i] != s[k]) k = pi[k - 1];   // shrink to next border
        if (s[i] == s[k]) ++k;                    // extend it
        pi[i] = k;
    }
    return pi;
}

std::vector<int> findAll(const std::string& text, const std::string& pat) {
    std::string t = pat + '#' + text;             // '#' never appears in inputs
    std::vector<int> pi = prefixFunction(t), pos;
    const int m = static_cast<int>(pat.size());
    for (int i = m + 1; i < static_cast<int>(t.size()); ++i)
        if (pi[i] == m) pos.push_back(i - 2 * m); // start index inside text
    return pos;
}

int main() {
    assert((prefixFunction("aabaaab") == std::vector<int>{0, 1, 0, 1, 2, 2, 3}));
    assert((findAll("saippuakauppias", "pp") == std::vector<int>{3, 10}));   // CSES sample -> 2
    assert((findAll("aaaa", "aa") == std::vector<int>{0, 1, 2}));            // overlaps count
    assert(findAll("abc", "d").empty());
    std::cout << "kmp_prefix_function: all tests passed\n";
    return 0;
}
