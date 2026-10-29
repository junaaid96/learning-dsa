// XPSC Week 13 Day 01 - Detect cycle in an undirected graph (GfG)
// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//
// Problem: does the undirected graph contain a cycle?
// Idea:    DSU - process edges; if both endpoints already share a root the edge
//          closes a cycle. (DFS with parent tracking also works.)
// Time: O(E * alpha(V))   Space: O(V)
// Compile: g++ -std=c++17 -Wall -Wextra gfg_detect_cycle_undirected.cpp && ./a.out

#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct DSU {
    std::vector<int> p, sz;
    explicit DSU(int n) : p(n), sz(n, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) { while (p[x] != x) x = p[x] = p[p[x]]; return x; }   // path halving
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;                     // already connected
        if (sz[a] < sz[b]) std::swap(a, b);           // union by size
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

bool hasCycle(int n, const std::vector<std::pair<int, int>>& edges) {
    DSU d(n);
    for (auto [u, v] : edges) if (!d.unite(u, v)) return true;
    return false;
}

int main() {
    assert(hasCycle(5, {{0, 1}, {1, 2}, {2, 3}, {3, 1}, {3, 4}}));
    assert(!hasCycle(4, {{0, 1}, {1, 2}, {2, 3}}));
    std::cout << "gfg_detect_cycle_undirected: all tests passed\n";
    return 0;
}
