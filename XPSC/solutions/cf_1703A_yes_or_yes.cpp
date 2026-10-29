// XPSC Week 03 Day 02 - Codeforces 1703A YES or YES?
// Link: https://codeforces.com/contest/1703/problem/A
//
// Problem: is a 3-letter string equal to "yes" ignoring case?
// Idea:    lowercase every char, compare.
// Time: O(1)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1703A_yes_or_yes.cpp && ./a.out

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

bool isYes(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s == "yes";
}

int main() {
    assert(isYes("YES") && isYes("yES") && isYes("yes") && isYes("Yes"));
    assert(!isYes("noo") && !isYes("orZ") && !isYes("yEz"));
    std::cout << "cf_1703A_yes_or_yes: all tests passed\n";
    return 0;
}
