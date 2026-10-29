// Palindromes: expand-around-center and Manacher's O(n) algorithm.
//
// Problem:
//   Longest palindromic substring; count palindromic substrings.
// Links: https://leetcode.com/problems/longest-palindromic-substring/
//        https://leetcode.com/problems/palindromic-substrings/
//        https://cses.fi/problemset/task/1111  (Longest Palindrome)
//
// Idea:
//   Expand: 2n-1 centers, grow while ends match -> O(n^2), easy to write.
//   Manacher: on t = "#a#b#..." every palindrome is odd. Reuse the mirror
//   radius inside the rightmost palindrome [c - d[c], c + d[c]].
//
// Time: O(n^2) expand, O(n) Manacher    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra palindromes_manacher.cpp -o pal && ./pal

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int countPalindromes(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int cnt = 0;
    for (int c = 0; c < 2 * n - 1; ++c) {            // even c -> odd length, odd c -> even
        int l = c / 2, r = l + c % 2;
        while (l >= 0 && r < n && s[l] == s[r]) { ++cnt; --l; ++r; }
    }
    return cnt;
}

std::string longestPalindrome(const std::string& s) {
    std::string t = "#";
    for (char ch : s) { t += ch; t += '#'; }          // separators make all lengths odd
    const int n = static_cast<int>(t.size());
    std::vector<int> d(n, 0);                          // radius around i in t
    int c = 0, r = 0;                                  // rightmost palindrome: center c, right end r
    for (int i = 0; i < n; ++i) {
        if (i < r) d[i] = std::min(r - i, d[2 * c - i]);   // mirror value
        while (i - d[i] - 1 >= 0 && i + d[i] + 1 < n && t[i - d[i] - 1] == t[i + d[i] + 1]) ++d[i];
        if (i + d[i] > r) { c = i; r = i + d[i]; }
    }
    int best = static_cast<int>(std::max_element(d.begin(), d.end()) - d.begin());
    return s.substr((best - d[best]) / 2, d[best]);    // radius in t == length in s
}

int main() {
    assert(countPalindromes("abc") == 3);
    assert(countPalindromes("aaa") == 6);
    std::string a = longestPalindrome("babad");
    assert(a == "bab" || a == "aba");
    assert(longestPalindrome("cbbd") == "bb");
    assert(longestPalindrome("aybabtu") == "bab");     // CSES 1111 sample
    std::cout << "palindromes_manacher: all tests passed\n";
    return 0;
}
