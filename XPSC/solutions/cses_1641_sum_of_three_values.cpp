// XPSC Week 14 Day 06 - CSES 1641 Sum of Three Values
// Link: https://cses.fi/problemset/task/1641
//
// Problem: find three distinct positions whose values sum to x (or IMPOSSIBLE).
// Idea:    sort (value, index) pairs; fix the first, two pointers for the rest.
// Time: O(n^2)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1641_sum_of_three_values.cpp && ./a.out

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

// returns 1-indexed positions, or {-1,-1,-1}
std::array<int, 3> threeValues(const std::vector<long long>& a, long long x) {
    const int n = static_cast<int>(a.size());
    std::vector<std::pair<long long, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {a[i], i + 1};
    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long s = v[i].first + v[l].first + v[r].first;
            if (s == x) return {v[i].second, v[l].second, v[r].second};
            if (s < x) ++l; else --r;                     // move toward the target
        }
    }
    return {-1, -1, -1};
}

int main() {
    std::vector<long long> a{2, 7, 5, 1};
    auto r = threeValues(a, 8);
    assert(r[0] != -1 && a[r[0] - 1] + a[r[1] - 1] + a[r[2] - 1] == 8);
    assert(r[0] != r[1] && r[1] != r[2] && r[0] != r[2]);
    assert(threeValues({1, 1, 1}, 4)[0] == -1);
    std::cout << "cses_1641_sum_of_three_values: all tests passed\n";
    return 0;
}
