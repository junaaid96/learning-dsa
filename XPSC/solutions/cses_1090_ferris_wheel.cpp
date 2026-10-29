// XPSC Week 16 Day 01 - CSES 1090 Ferris Wheel
// Link: https://cses.fi/problemset/task/1090
//
// Problem: gondolas carry <= 2 kids with total weight <= x. Minimum gondolas.
// Idea:    sort; pair the heaviest with the lightest if they fit, else heaviest alone.
// Time: O(n log n)   Space: O(1)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1090_ferris_wheel.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int gondolas(std::vector<int> p, int x) {
    std::sort(p.begin(), p.end());
    int l = 0, r = static_cast<int>(p.size()) - 1, cnt = 0;
    while (l <= r) {
        if (l < r && p[l] + p[r] <= x) ++l;               // lightest rides along
        --r; ++cnt;                                       // heaviest always boards
    }
    return cnt;
}

int main() {
    assert(gondolas({7, 2, 3, 9}, 10) == 3);
    assert(gondolas({5, 5}, 10) == 1);
    std::cout << "cses_1090_ferris_wheel: all tests passed\n";
    return 0;
}
