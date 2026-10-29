// XPSC Week 13 Day 01 - Codeforces 25D Roads not only in Berland
// Link: https://codeforces.com/contest/25/problem/D
//
// Problem: n cities, n-1 roads. Each day close one road and build one so that in
//          the end every city is reachable. Minimum days + the plan.
// Idea:    DSU over the roads: an edge joining already-connected cities is
//          redundant. Components c -> exactly c-1 redundant edges exist; reuse
//          each one to join component roots.
// Time: O(n alpha(n))   Space: O(n)
// Compile: g++ -std=c++17 -Wall -Wextra cf_25D_roads_not_only_in_berland.cpp && ./a.out

#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct DSU {
    std::vector<int> p;
    explicit DSU(int n) : p(n + 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false; p[a] = b; return true; }
};

// returns plan: {close u, close v, build a, build b}
std::vector<std::array<int, 4>> fixRoads(int n, const std::vector<std::pair<int, int>>& roads) {
    DSU d(n);
    std::vector<std::pair<int, int>> extra;
    for (auto [u, v] : roads) if (!d.unite(u, v)) extra.push_back({u, v});   // redundant road
    std::vector<int> roots;
    for (int v = 1; v <= n; ++v) if (d.find(v) == v) roots.push_back(v);
    std::vector<std::array<int, 4>> plan;
    for (size_t i = 0; i + 1 < roots.size(); ++i)                          // chain components
        plan.push_back({extra[i].first, extra[i].second, roots[i], roots[i + 1]});
    return plan;
}

int main() {
    assert(fixRoads(2, {{1, 2}}).empty());
    auto plan = fixRoads(7, {{1, 2}, {2, 3}, {3, 1}, {4, 5}, {5, 6}, {6, 7}});
    assert(plan.size() == 1);
    assert(plan[0][0] == 3 && plan[0][1] == 1);            // the cycle edge is reused
    std::cout << "cf_25D_roads_not_only_in_berland: all tests passed\n";
    return 0;
}
