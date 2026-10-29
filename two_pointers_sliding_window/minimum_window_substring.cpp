// Minimum Window Substring (variable window with "need" counter).
//
// Problem:
//   Smallest substring of s containing every character of t (with multiplicity).
// Link: https://leetcode.com/problems/minimum-window-substring/
//
// Idea:
//   need[c] = how many more c the window still needs; missing = total still
//   needed. Expand r; once missing == 0 the window is valid, so shrink l as
//   much as possible while staying valid and record the best window.
//
// Time: O(|s| + |t|)    Space: O(alphabet)
//
// Compile: g++ -std=c++17 -Wall -Wextra minimum_window_substring.cpp -o mws && ./mws

#include <array>
#include <cassert>
#include <iostream>
#include <string>

std::string minWindow(const std::string& s, const std::string& t) {
    std::array<int, 128> need{};                     // positive = still required
    for (char c : t) need[c]++;
    int missing = static_cast<int>(t.size());        // characters still missing
    int bestL = 0, bestLen = -1, l = 0;
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
        if (need[s[r]]-- > 0) --missing;             // s[r] was useful
        while (missing == 0) {                       // window [l, r] is valid
            if (bestLen == -1 || r - l + 1 < bestLen) { bestL = l; bestLen = r - l + 1; }
            if (++need[s[l]] > 0) ++missing;         // removing s[l] breaks validity
            ++l;
        }
    }
    return bestLen == -1 ? "" : s.substr(bestL, bestLen);
}

int main() {
    assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(minWindow("a", "a") == "a");
    assert(minWindow("a", "aa") == "");
    std::cout << "minimum_window_substring: all tests passed\n";
    return 0;
}
