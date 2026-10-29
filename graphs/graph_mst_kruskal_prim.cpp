// Minimum Spanning Tree: Kruskal (sort edges + DSU) and Prim (priority queue).
//
// Problem:
//   Connect all n nodes with minimum total edge weight (or report impossible).
// Links: https://cses.fi/problemset/task/1675  (Road Reparation)
//        https://leetcode.com/problems/min-cost-to-connect-all-points/
//
// Idea:
//   Kruskal: take edges from lightest; skip an edge if it would form a cycle.
//   Prim: grow one tree; always add the cheapest edge leaving the tree.
//   Both rely on the cut property: the lightest edge across a cut is safe.
//
// Time: O(m log m)    Space: O(n + m)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_mst_kruskal_prim.cpp -o mst && ./mst

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

struct Edge { int u, v; long long w; };

long long kruskal(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
    long long total = 0; int used = 0;
    for (const Edge& e : edges) {
        int a = find(e.u), b = find(e.v);
        if (a == b) continue;                    // would create a cycle
        p[a] = b; total += e.w; ++used;          // take the edge
    }
    return used == n - 1 ? total : -1;           // -1 = graph not connected
}

long long prim(int n, const std::vector<Edge>& edges) {
    std::vector<std::vector<std::pair<int, long long>>> g(n);
    for (const Edge& e : edges) { g[e.u].push_back({e.v, e.w}); g[e.v].push_back({e.u, e.w}); }
    using P = std::pair<long long, int>;                             // (weight, node)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    std::vector<bool> in(n, false);
    pq.push({0, 0});
    long long total = 0; int cnt = 0;
    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if (in[v]) continue;                     // stale entry
        in[v] = true; total += w; ++cnt;         // cheapest edge into the tree
        for (auto [u, wu] : g[v]) if (!in[u]) pq.push({wu, u});
    }
    return cnt == n ? total : -1;
}

int main() {
    // CSES 1675 sample, converted to 0-indexed nodes: answer 14
    std::vector<Edge> e{{0, 1, 3}, {1, 2, 5}, {1, 3, 2}, {2, 3, 8}, {4, 0, 7}, {4, 3, 4}};
    assert(kruskal(5, e) == 14);
    assert(prim(5, e) == 14);
    assert(kruskal(3, {{0, 1, 1}}) == -1);       // node 2 is isolated -> IMPOSSIBLE
    std::cout << "graph_mst_kruskal_prim: all tests passed\n";
    return 0;
}
