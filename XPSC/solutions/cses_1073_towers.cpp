// XPSC Week 15 Day 04 - CSES 1073 Towers
// Link: https://cses.fi/problemset/task/1073
//
// Problem: place cubes in order; a cube goes on a tower whose top is strictly
//          larger, or starts a new tower. Minimum towers.
// Idea:    greedy - put the cube on the tower with the smallest top > cube
//          (multiset::upper_bound). Equivalent to LIS-like patience sorting.
// Time: O(n log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1073_towers.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

int towers(const std::vector<int>& cubes) {
    std::multiset<int> tops;
    for (int k : cubes) {
        auto it = tops.upper_bound(k);                    // smallest top strictly bigger
        if (it != tops.end()) tops.erase(it);             // that tower's top becomes k
        tops.insert(k);
    }
    return static_cast<int>(tops.size());
}

int main() {
    assert(towers({3, 8, 2, 1, 5}) == 2);
    assert(towers({1, 1, 1}) == 3);                       // equal size cannot stack
    std::cout << "cses_1073_towers: all tests passed\n";
    return 0;
}
