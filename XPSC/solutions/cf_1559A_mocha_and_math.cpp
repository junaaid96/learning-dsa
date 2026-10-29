// XPSC Week 07 Day 01 - Codeforces 1559A Mocha and Math
// Link: https://codeforces.com/problemset/problem/1559/A
//
// Problem: operation replaces a[l+i] with a[l+i] & a[r-i]; minimise the maximum.
// Idea:    AND never increases a value and we can AND any element with any other,
//          so every element can become the AND of the whole array - and nothing
//          smaller is reachable. Answer = a1 & a2 & ... & an.
// Time: O(n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1559A_mocha_and_math.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

int mocha(const std::vector<int>& a) {
    int x = a[0];
    for (int v : a) x &= v;
    return x;
}

int main() {
    assert(mocha({1, 2}) == 0);
    assert(mocha({1, 1, 3}) == 1);
    assert(mocha({3, 11, 3, 7}) == 3);
    assert(mocha({11, 7, 15, 3, 7}) == 3);
    std::cout << "cf_1559A_mocha_and_math: all tests passed\n";
    return 0;
}
