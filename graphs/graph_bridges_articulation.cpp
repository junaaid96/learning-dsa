// Bridges and articulation points (Tarjan low-link).
//
// Problem:
//   A bridge is an edge whose removal disconnects the graph; an articulation
//   point is such a vertex.
// Links: https://leetcode.com/problems/critical-connections-in-a-network/
//        https://cses.fi/problemset/task/2076  (Necessary Roads)
//        https://cses.fi/problemset/task/2077  (Necessary Cities)
//
// Idea:
//   tin[v] = DFS entry time, low[v] = smallest tin reachable from v's subtree
//   using at most one back edge. For tree edge v -> child u:
//     bridge       if low[u] >  tin[v]
//     cut vertex   if low[u] >= tin[v] (v not root), or root with >= 2 children.
//
// Time: O(n + m)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_bridges_articulation.cpp -o br && ./br

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

struct Tarjan {
    const std::vector<std::vector<int>>& g;
    std::vector<int> tin, low;
    int timer = 0;
    std::vector<std::pair<int, int>> bridges;
    std::set<int> cut;
    explicit Tarjan(const std::vector<std::vector<int>>& g) : g(g), tin(g.size(), -1), low(g.size()) {
        for (int v = 0; v < static_cast<int>(g.size()); ++v) if (tin[v] == -1) dfs(v, -1);
    }
    void dfs(int v, int parent) {
        tin[v] = low[v] = timer++;
        int children = 0;
        for (int u : g[v]) {
            if (u == parent) continue;                       // skip the tree edge back
            if (tin[u] != -1) { low[v] = std::min(low[v], tin[u]); continue; }  // back edge
            dfs(u, v);
            ++children;
            low[v] = std::min(low[v], low[u]);               // child can reach this high
            if (low[u] > tin[v]) bridges.push_back({std::min(u, v), std::max(u, v)});
            if (parent != -1 && low[u] >= tin[v]) cut.insert(v);
        }
        if (parent == -1 && children > 1) cut.insert(v);    // root rule
    }
};

int main() {
    // LeetCode sample: n = 4, edges 0-1, 1-2, 2-0, 1-3 -> bridge (1,3)
    std::vector<std::vector<int>> g{{1, 2}, {0, 2, 3}, {1, 0}, {1}};
    Tarjan t(g);
    assert(t.bridges.size() == 1 && t.bridges[0] == std::make_pair(1, 3));
    assert(t.cut == std::set<int>{1});
    std::cout << "graph_bridges_articulation: all tests passed\n";
    return 0;
}
