// XPSC Week 07 Day 01 - Codeforces 1527A And Then There Were K
// Link: https://codeforces.com/problemset/problem/1527/A
//
// Problem: largest k with n & (n-1) & ... & k == 0.
// Idea:    the highest bit of n survives until we pass 2^h - 1 (all lower bits set,
//          highest cleared), and 2^h & (2^h - 1) = 0. So k = 2^h - 1.
// Time: O(log n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1527A_and_then_there_were_k.cpp && ./a.out

#include <cassert>
#include <iostream>

long long maxK(long long n) {
    long long p = 1;
    while (p * 2 <= n) p *= 2;                 // p = highest power of two <= n
    return p - 1;
}

int main() {
    assert(maxK(2) == 1);
    assert(maxK(5) == 3);
    assert(maxK(17) == 15);
    assert(maxK(1) == 0);
    std::cout << "cf_1527A_and_then_there_were_k: all tests passed\n";
    return 0;
}
