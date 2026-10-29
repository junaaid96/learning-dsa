// XPSC Week 14 Day 07 - CSES 1623 Apple Division
// Link: https://cses.fi/problemset/task/1623
//
// Problem: split n <= 20 apples into two groups with minimal weight difference.
// Idea:    enumerate all 2^n subsets as bitmasks (or recurse take / skip).
// Time: O(2^n * n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1623_apple_division.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

long long minDiff(const std::vector<long long>& p, size_t i = 0, long long a = 0, long long b = 0) {
    if (i == p.size()) return std::llabs(a - b);           // all apples assigned
    return std::min(minDiff(p, i + 1, a + p[i], b),        // apple i -> group A
                    minDiff(p, i + 1, a, b + p[i]));       // apple i -> group B
}

int main() {
    assert(minDiff({3, 2, 7, 4, 1}) == 1);
    assert(minDiff({10}) == 10);
    std::cout << "cses_1623_apple_division: all tests passed\n";
    return 0;
}
