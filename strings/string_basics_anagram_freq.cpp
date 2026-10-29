// String basics: frequency arrays, valid anagram, first unique char, reverse words.
//
// Links: https://leetcode.com/problems/valid-anagram/
//        https://leetcode.com/problems/first-unique-character-in-a-string/
//        https://leetcode.com/problems/reverse-words-in-a-string/
//        https://codeforces.com/problemset/problem/112/A  (Petya and Strings)
//
// Idea:
//   For lowercase letters an int[26] beats a hash map. Use stringstream to split
//   on whitespace. Remember: std::string::size() is unsigned.
//
// Time: O(n)    Space: O(1) alphabet / O(n) for split
//
// Compile: g++ -std=c++17 -Wall -Wextra string_basics_anagram_freq.cpp -o sb && ./sb

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isAnagram(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    std::array<int, 26> f{};
    for (size_t i = 0; i < a.size(); ++i) { ++f[a[i] - 'a']; --f[b[i] - 'a']; }  // net count
    return std::all_of(f.begin(), f.end(), [](int x) { return x == 0; });
}

int firstUniqChar(const std::string& s) {
    std::array<int, 26> f{};
    for (char c : s) ++f[c - 'a'];
    for (int i = 0; i < static_cast<int>(s.size()); ++i) if (f[s[i] - 'a'] == 1) return i;
    return -1;
}

std::string reverseWords(const std::string& s) {
    std::istringstream in(s);
    std::vector<std::string> w;
    for (std::string x; in >> x;) w.push_back(x);      // >> skips any whitespace
    std::reverse(w.begin(), w.end());
    std::string out;
    for (size_t i = 0; i < w.size(); ++i) out += (i ? " " : "") + w[i];
    return out;
}

int compareIgnoreCase(std::string a, std::string b) {   // CF 112A
    for (auto& c : a) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    for (auto& c : b) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return a < b ? -1 : (a > b ? 1 : 0);
}

int main() {
    assert(isAnagram("anagram", "nagaram") && !isAnagram("rat", "car"));
    assert(firstUniqChar("leetcode") == 0 && firstUniqChar("loveleetcode") == 2 && firstUniqChar("aabb") == -1);
    assert(reverseWords("  the sky  is blue ") == "blue is sky the");
    assert(compareIgnoreCase("aaaa", "aaaA") == 0 && compareIgnoreCase("abs", "Abz") == -1);
    std::cout << "string_basics_anagram_freq: all tests passed\n";
    return 0;
}
