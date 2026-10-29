// XPSC Week 15 Day 01 - CSES 1755 Palindrome Reorder
// Link: https://cses.fi/problemset/task/1755
//
// Problem: reorder letters into a palindrome, or NO SOLUTION.
// Idea:    at most one letter may have an odd count. Build the left half from
//          count/2 of each letter, put the odd letter in the middle, mirror.
// Time: O(n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1755_palindrome_reorder.cpp && ./a.out

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>

std::string reorder(const std::string& s) {
    std::array<int, 26> f{};
    for (char c : s) ++f[c - 'A'];
    int odd = -1;
    std::string half;
    for (int c = 0; c < 26; ++c) {
        if (f[c] % 2) { if (odd != -1) return "NO SOLUTION"; odd = c; }   // second odd -> impossible
        half += std::string(f[c] / 2, static_cast<char>('A' + c));
    }
    std::string rev(half.rbegin(), half.rend());
    return half + (odd != -1 ? std::string(f[odd] % 2, static_cast<char>('A' + odd)) : "") + rev;
}

int main() {
    std::string r = reorder("AAAACACBA");
    assert(r.size() == 9 && std::equal(r.begin(), r.end(), r.rbegin()));
    std::string sorted1 = r, sorted2 = "AAAACACBA";
    std::sort(sorted1.begin(), sorted1.end()); std::sort(sorted2.begin(), sorted2.end());
    assert(sorted1 == sorted2);                           // same letters
    assert(reorder("AB") == "NO SOLUTION");
    std::cout << "cses_1755_palindrome_reorder: all tests passed\n";
    return 0;
}
