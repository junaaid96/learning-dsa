// XPSC Week 09 Day 01 - CSES 1619 Restaurant Customers
// Link: https://cses.fi/problemset/task/1619
//
// Problem: maximum number of customers in the restaurant at the same time.
// Idea:    sweep line: sort arrivals and departures, +1 / -1, track the maximum.
// Time: O(n log n)   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cses_1619_restaurant_customers.cpp && ./a.out

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

int maxInside(const std::vector<std::pair<int, int>>& c) {
    std::vector<std::pair<int, int>> ev;
    for (auto [a, b] : c) { ev.push_back({a, +1}); ev.push_back({b, -1}); }
    std::sort(ev.begin(), ev.end());                     // times are distinct in CSES
    int cur = 0, best = 0;
    for (auto [t, d] : ev) { (void)t; cur += d; best = std::max(best, cur); }
    return best;
}

int main() {
    assert(maxInside({{5, 8}, {2, 4}, {3, 9}}) == 2);
    std::cout << "cses_1619_restaurant_customers: all tests passed\n";
    return 0;
}
