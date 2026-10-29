// XPSC Week 01 Day 03 - Codeforces 633A Ebony and Ivory
// Link: https://codeforces.com/problemset/problem/633/A
//
// Problem: can c be written as a*x + b*y with x, y >= 0?
// Idea:    c <= 10^4, so try every x and check the remainder is divisible by b.
// Time: O(c / a)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_633A_ebony_and_ivory.cpp && ./a.out

#include <cassert>
#include <iostream>

bool canMake(int a, int b, int c) {
    for (int x = 0; a * x <= c; ++x)              // x shots from Ebony
        if ((c - a * x) % b == 0) return true;    // rest must be made by Ivory
    return false;
}

int main() {
    assert(!canMake(4, 6, 15));
    assert(canMake(3, 2, 7));
    assert(canMake(6, 11, 6));
    std::cout << "cf_633A_ebony_and_ivory: all tests passed\n";
    return 0;
}
