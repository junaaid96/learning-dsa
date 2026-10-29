// Strongly Connected Components (Kosaraju's algorithm).
//
// Problem:
//   Split a directed graph into maximal groups where every node reaches every
//   other node in the group.
// Links: https://cses.fi/problemset/task/1683  (Planets and Kingdoms)
//        https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
//
// Idea:
//   1) DFS on the graph, push nodes by finish time.
//   2) DFS on the REVERSED graph in decreasing finish time; every tree found
//      is one SCC (the reversed graph cannot leak into an earlier component).
//
// Time: O(n + m)    Space: O(n + m)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_scc_kosaraju.cpp -o scc && ./scc

#include <cassert>
#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void order(int v, const Graph& g, std::vector<bool>& vis, std::vector<int>& out) {
    vis[v] = true;
    for (int u : g[v]) if (!vis[u]) order(u, g, vis, out);
    out.push_back(v);                                  // record finish time
}

void mark(int v, const Graph& rg, std::vector<int>& comp, int id) {
    comp[v] = id;
    for (int u : rg[v]) if (comp[u] == -1) mark(u, rg, comp, id);
}

int scc(const Graph& g, std::vector<int>& comp) {
    const int n = static_cast<int>(g.size());
    Graph rg(n);
    for (int v = 0; v < n; ++v) for (int u : g[v]) rg[u].push_back(v);   // reverse edges
    std::vector<bool> vis(n, false);
    std::vector<int> fin;
    for (int v = 0; v < n; ++v) if (!vis[v]) order(v, g, vis, fin);
    comp.assign(n, -1);
    int id = 0;
    for (int i = n - 1; i >= 0; --i)                   // latest finish first
        if (comp[fin[i]] == -1) mark(fin[i], rg, comp, id++);
    return id;
}

int main() {
    // 0 -> 1 -> 2 -> 0 is one SCC; 2 -> 3; 3 <-> 4 another; 5 alone
    Graph g{{1}, {2}, {0, 3}, {4}, {3}, {}};
    std::vector<int> comp;
    assert(scc(g, comp) == 3);
    assert(comp[0] == comp[1] && comp[1] == comp[2]);
    assert(comp[3] == comp[4] && comp[3] != comp[0]);
    std::cout << "graph_scc_kosaraju: all tests passed\n";
    return 0;
}
