// XPSC Week 15 Day 06 - CSES 1622 Creating Strings
// Link: https://cses.fi/problemset/task/1622
//
// Problem: list all distinct permutations of a string in sorted order.
// Idea:    sort, then std::next_permutation already skips duplicates.
// Time: O(n! * n)   Space: O(n! * n) for the output
// Compile: g++ -std=c++17 -Wall -Wextra cses_1622_creating_strings.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> creatingStrings(std::string s) {
    std::sort(s.begin(), s.end());                        // start from the smallest
    std::vector<std::string> out;
    do out.push_back(s); while (std::next_permutation(s.begin(), s.end()));
    return out;
}

int main() {
    auto v = creatingStrings("aabac");
    assert(v.size() == 20);
    assert(v.front() == "aaabc" && v.back() == "cbaaa");
    assert(std::is_sorted(v.begin(), v.end()));
    std::cout << "cses_1622_creating_strings: all tests passed\n";
    return 0;
}
