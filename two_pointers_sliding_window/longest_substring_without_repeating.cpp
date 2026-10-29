// Longest Substring Without Repeating Characters (variable-size window).
//
// Problem:
//   Length of the longest substring with all distinct characters.
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Idea:
//   Expand right end r. Remember the last index of every character. If s[r]
//   was seen inside the window, jump the left end to just after that index.
//
// Time: O(n)    Space: O(alphabet)
//
// Compile: g++ -std=c++17 -Wall -Wextra longest_substring_without_repeating.cpp -o lsw && ./lsw

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::array<int, 256> last;                    // last index where each byte appeared
    last.fill(-1);                                // -1 = never seen
    int best = 0, l = 0;                          // window is [l, r]
    for (int r = 0; r < static_cast<int>(s.size()); ++r) {
        unsigned char c = static_cast<unsigned char>(s[r]);
        if (last[c] >= l) l = last[c] + 1;        // duplicate inside window -> shrink
        last[c] = r;                              // update last position of c
        best = std::max(best, r - l + 1);         // window length
    }
    return best;
}

int main() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    std::cout << "longest_substring_without_repeating: all tests passed\n";
    return 0;
}
