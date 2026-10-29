// XPSC Week 07 Day 02 - Codeforces 1850F We Were Both Children
// Link: https://codeforces.com/contest/1850/problem/F
//
// Problem: frog i lands on a_i, 2a_i, 3a_i, ...; put one trap in 1..n to catch
//          the most frogs.
// Idea:    count frogs per hop length (ignore a_i > n); for each length h add its
//          count to every multiple of h <= n. Harmonic sum -> n log n.
// Time: O(n log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cf_1850F_we_were_both_children.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int bestTrap(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    std::vector<int> cnt(n + 1, 0), caught(n + 1, 0);
    for (int x : a) if (x <= n) ++cnt[x];                 // larger hops never land in 1..n
    for (int h = 1; h <= n; ++h)
        if (cnt[h]) for (int m = h; m <= n; m += h) caught[m] += cnt[h];
    return *std::max_element(caught.begin(), caught.end());
}

int main() {
    assert(bestTrap({1, 2, 3, 4, 5}) == 3);               // trap at 4: frogs 1, 2, 4
    assert(bestTrap({2, 2, 2}) == 3);
    assert(bestTrap({7, 8, 9}) == 0);
    std::cout << "cf_1850F_we_were_both_children: all tests passed\n";
    return 0;
}
