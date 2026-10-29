// Cycle detection (undirected + directed) and bipartite check.
//
// Problems:
//   (1) Does an undirected graph contain a cycle?
//       Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//   (2) Does a directed graph contain a cycle? (Course Schedule)
//       Link: https://leetcode.com/problems/course-schedule/
//   (3) Is the graph bipartite (2-colourable)?
//       Links: https://leetcode.com/problems/is-graph-bipartite/  https://cses.fi/problemset/task/1668
//
// Idea:
//   (1) DFS; reaching an already visited node that is not our parent = cycle.
//   (2) Three colours: 0 unvisited, 1 on the current DFS path, 2 finished.
//       An edge to a colour-1 node is a back edge = cycle.
//   (3) BFS colouring; an edge joining equal colours means odd cycle.
//
// Time: O(n + m)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_cycle_detection_bipartite.cpp -o cyc && ./cyc

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

bool undirectedDfs(int v, int parent, const Graph& g, std::vector<bool>& vis) {
    vis[v] = true;
    for (int u : g[v]) {
        if (u == parent) continue;                         // ignore the edge we came from
        if (vis[u] || undirectedDfs(u, v, g, vis)) return true;
    }
    return false;
}
bool hasCycleUndirected(const Graph& g) {
    std::vector<bool> vis(g.size(), false);
    for (int v = 0; v < static_cast<int>(g.size()); ++v)
        if (!vis[v] && undirectedDfs(v, -1, g, vis)) return true;   // every component
    return false;
}

bool directedDfs(int v, const Graph& g, std::vector<int>& color) {
    color[v] = 1;                                          // on the current path
    for (int u : g[v]) {
        if (color[u] == 1) return true;                    // back edge -> cycle
        if (color[u] == 0 && directedDfs(u, g, color)) return true;
    }
    color[v] = 2;                                          // fully explored
    return false;
}
bool hasCycleDirected(const Graph& g) {
    std::vector<int> color(g.size(), 0);
    for (int v = 0; v < static_cast<int>(g.size()); ++v)
        if (color[v] == 0 && directedDfs(v, g, color)) return true;
    return false;
}

bool isBipartite(const Graph& g) {
    std::vector<int> side(g.size(), -1);                   // -1 = uncoloured
    for (int s = 0; s < static_cast<int>(g.size()); ++s) {
        if (side[s] != -1) continue;
        side[s] = 0;
        std::queue<int> q; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : g[v]) {
                if (side[u] == -1) { side[u] = side[v] ^ 1; q.push(u); }  // opposite colour
                else if (side[u] == side[v]) return false;               // conflict
            }
        }
    }
    return true;
}

int main() {
    Graph tree{{1, 2}, {0}, {0}};
    Graph tri{{1, 2}, {0, 2}, {0, 1}};
    assert(!hasCycleUndirected(tree));
    assert(hasCycleUndirected(tri));
    assert(!hasCycleDirected({{1}, {2}, {}}));
    assert(hasCycleDirected({{1}, {2}, {0}}));
    assert(isBipartite({{1, 3}, {0, 2}, {1, 3}, {0, 2}}));   // square: even cycle
    assert(!isBipartite(tri));                              // triangle: odd cycle
    std::cout << "graph_cycle_detection_bipartite: all tests passed\n";
    return 0;
}
