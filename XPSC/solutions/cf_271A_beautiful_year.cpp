// XPSC Week 02 Day 05 - Codeforces 271A Beautiful Year
// Link: https://codeforces.com/problemset/problem/271/A
//
// Problem: smallest year > y whose digits are all distinct.
// Idea:    brute force upward; checking a year costs 4 digit lookups.
// Time: tiny (answer for y <= 9000 is close)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_271A_beautiful_year.cpp && ./a.out

#include <cassert>
#include <iostream>

bool distinctDigits(int x) {
    bool seen[10] = {};
    for (; x > 0; x /= 10) {
        if (seen[x % 10]) return false;           // repeated digit
        seen[x % 10] = true;
    }
    return true;
}

int nextBeautiful(int y) {
    do ++y; while (!distinctDigits(y));
    return y;
}

int main() {
    assert(nextBeautiful(1987) == 2013);
    assert(nextBeautiful(2013) == 2014);
    std::cout << "cf_271A_beautiful_year: all tests passed\n";
    return 0;
}
