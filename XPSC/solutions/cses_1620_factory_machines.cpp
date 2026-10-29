// XPSC Week 15 Day 04 - CSES 1620 Factory Machines
// Link: https://cses.fi/problemset/task/1620
//
// Problem: machine i makes a product every k_i seconds; least time to make t products.
// Idea:    in time T machines make sum(T / k_i) - monotone -> binary search T.
//          Cap the running sum to avoid overflow.
// Time: O(n log(t * min k))   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1620_factory_machines.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

long long minTime(const std::vector<long long>& k, long long t) {
    long long lo = 1, hi = *std::min_element(k.begin(), k.end()) * t;   // fastest machine alone
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2, made = 0;
        for (long long x : k) { made += mid / x; if (made >= t) break; }   // early stop
        if (made >= t) hi = mid; else lo = mid + 1;
    }
    return lo;
}

int main() {
    assert(minTime({3, 2, 5}, 7) == 8);
    assert(minTime({1}, 1000000000) == 1000000000);
    std::cout << "cses_1620_factory_machines: all tests passed\n";
    return 0;
}
