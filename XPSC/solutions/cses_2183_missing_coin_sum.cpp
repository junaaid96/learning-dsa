// XPSC Week 14 Day 07 - CSES 2183 Missing Coin Sum
// Link: https://cses.fi/problemset/task/2183
//
// Problem: smallest sum that cannot be formed with a subset of the coins.
// Idea:    sort; if coins so far make every sum in [1, reach], a coin c <= reach + 1
//          extends it to [1, reach + c]; otherwise reach + 1 is impossible.
// Time: O(n log n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_2183_missing_coin_sum.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long missingSum(std::vector<long long> c) {
    std::sort(c.begin(), c.end());
    long long reach = 0;                                  // all of 1..reach are formable
    for (long long x : c) {
        if (x > reach + 1) break;                          // gap at reach + 1
        reach += x;
    }
    return reach + 1;
}

int main() {
    assert(missingSum({2, 9, 1, 2, 7}) == 6);
    assert(missingSum({2}) == 1);
    assert(missingSum({1, 2, 4}) == 8);
    std::cout << "cses_2183_missing_coin_sum: all tests passed\n";
    return 0;
}
