// XPSC Week 16 Day 01 - CSES 1074 Stick Lengths
// Link: https://cses.fi/problemset/task/1074
//
// Problem: make all sticks equal; cost |a_i - target|. Minimum total cost.
// Idea:    sum of absolute deviations is minimised at the median.
// Time: O(n) with nth_element   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1074_stick_lengths.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

long long stickCost(std::vector<long long> a) {
    std::nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
    long long med = a[a.size() / 2], cost = 0;
    for (long long x : a) cost += std::llabs(x - med);
    return cost;
}

int main() {
    assert(stickCost({2, 3, 1, 5, 2}) == 5);
    assert(stickCost({7}) == 0);
    std::cout << "cses_1074_stick_lengths: all tests passed\n";
    return 0;
}
