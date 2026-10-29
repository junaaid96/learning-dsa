// XPSC Week 16 Day 01 - Codeforces 1873E Building an Aquarium
// Link: https://codeforces.com/contest/1873/problem/E
//
// Problem: water height h needs sum(max(0, h - a_i)) units; at most x units.
//          Maximum h.
// Idea:    needed water is monotone in h -> binary search on the answer.
// Time: O(n log(maxH))   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1873E_building_an_aquarium.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <vector>

long long maxHeight(const std::vector<long long>& a, long long x) {
    auto need = [&](long long h) {
        long long s = 0;
        for (long long v : a) if (h > v) s += h - v;
        return s;
    };
    long long lo = 1, hi = 2'100'000'000LL;          // answer fits: max a + x
    while (lo < hi) {                                 // last h with need(h) <= x
        long long mid = lo + (hi - lo + 1) / 2;
        if (need(mid) <= x) lo = mid; else hi = mid - 1;
    }
    return lo;
}

int main() {
    assert(maxHeight({3, 1, 2, 4, 6, 2, 5}, 9) == 4);
    assert(maxHeight({1, 1, 1}, 10) == 4);
    assert(maxHeight({1, 4, 3, 4}, 1) == 2);
    assert(maxHeight({2, 6, 5, 9, 1, 8}, 1984) == 335);
    assert(maxHeight({1}, 1000000000) == 1000000001);
    std::cout << "cf_1873E_building_an_aquarium: all tests passed\n";
    return 0;
}
