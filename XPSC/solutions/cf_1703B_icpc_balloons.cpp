// XPSC Week 01 Day 07 - Codeforces 1703B ICPC Balloons
// Link: https://codeforces.com/contest/1703/problem/B
//
// Problem: each solve gives 1 balloon; the first solve of a problem gives 1 extra.
// Idea:    answer = number of solves + number of distinct problems.
// Time: O(n)   Space: O(26)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1703B_icpc_balloons.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <set>
#include <string>

int balloons(const std::string& s) {
    std::set<char> firstSolved(s.begin(), s.end());   // distinct problems
    return static_cast<int>(s.size() + firstSolved.size());
}

int main() {
    assert(balloons("ABA") == 5);
    assert(balloons("A") == 2);
    assert(balloons("ORZ") == 6);
    assert(balloons("BAAAA") == 7);
    std::cout << "cf_1703B_icpc_balloons: all tests passed\n";
    return 0;
}
