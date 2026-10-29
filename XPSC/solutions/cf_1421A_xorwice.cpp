// XPSC Week 07 Day 01 - Codeforces 1421A XORwice
// Link: https://codeforces.com/problemset/problem/1421/A
//
// Problem: minimise (a ^ x) + (b ^ x) over x.
// Idea:    per bit: if a and b agree, x can cancel both (cost 0); if they differ
//          exactly one side pays 2^bit whatever x is -> minimum = a ^ b (x = a & b).
// Time: O(1)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1421A_xorwice.cpp && ./a.out

#include <cassert>
#include <iostream>

long long xorwice(long long a, long long b) { return a ^ b; }

int main() {
    assert(xorwice(6, 12) == 10);
    assert(xorwice(4, 9) == 13);
    assert(xorwice(59, 832) == 891);
    assert(xorwice(28, 14) == 18);
    assert(xorwice(4925, 2912) == 6237);
    assert(xorwice(1, 1) == 0);
    std::cout << "cf_1421A_xorwice: all tests passed\n";
    return 0;
}
