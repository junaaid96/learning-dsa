// XPSC Week 07 Day 01 - Codeforces 1097B Petr and a Combination Lock
// Link: https://codeforces.com/problemset/problem/1097/B
//
// Problem: rotate by each a_i clockwise or counter-clockwise; can the total be
//          a multiple of 360?
// Idea:    n <= 15 -> try all 2^n sign choices with a bitmask.
// Time: O(2^n * n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1097B_petr_and_combination_lock.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

bool canOpen(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    for (int mask = 0; mask < (1 << n); ++mask) {
        int angle = 0;
        for (int i = 0; i < n; ++i) angle += (mask >> i & 1) ? a[i] : -a[i];   // bit = direction
        if (angle % 360 == 0) return true;      // works for negatives too (remainder 0)
    }
    return false;
}

int main() {
    assert(canOpen({10, 20, 30}));
    assert(!canOpen({10, 10, 10}));
    assert(canOpen({120, 120, 120}));
    std::cout << "cf_1097B_petr_and_combination_lock: all tests passed\n";
    return 0;
}
