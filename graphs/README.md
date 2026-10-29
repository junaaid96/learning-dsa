# Graphs

[← back to roadmap](../README.md)

## What it is

Vertices + edges. Represent with adjacency lists and pick the traversal / shortest-path algorithm by edge weights.

## When to use it

- Connectivity, components, grids
- Shortest paths
- Dependencies (topological order)
- Network design (MST), cycles, SCCs, bridges

## Intuition

Choose by weights: unweighted → BFS; 0/1 → 0-1 BFS; non-negative → Dijkstra; negative → Bellman-Ford; all pairs small n → Floyd-Warshall.

## Common patterns

- BFS / DFS / multi-source BFS on grids
- Dijkstra with min-heap
- Kahn topological sort
- Kruskal (DSU) / Prim
- Kosaraju SCC
- Tarjan low-link for bridges

## Template

```cpp
std::vector<long long> dist(n, INF); dist[s] = 0;
std::priority_queue<std::pair<long long,int>, std::vector<std::pair<long long,int>>, std::greater<>> pq;
pq.push({0, s});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d != dist[u]) continue;          // stale
    for (auto [v, w] : adj[u]) if (d + w < dist[v]) pq.push({dist[v] = d + w, v});
}
```

## Pitfalls

- Mark visited when PUSHING in BFS
- Dijkstra fails with negative edges
- INF + w overflow
- Recursive DFS depth on 2e5 nodes

## Complexity

BFS/DFS O(V+E); Dijkstra O(E log V); Bellman-Ford O(VE); Floyd O(V^3).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`graph_bellman_ford.cpp`](graph_bellman_ford.cpp) | Bellman-Ford: shortest paths with negative edges + negative cycle detection. | [link](https://cses.fi/problemset/task/1197) |
| [`graph_bfs_shortest_path.cpp`](graph_bfs_shortest_path.cpp) | BFS shortest path in an unweighted undirected graph. | — |
| [`graph_bridges_articulation.cpp`](graph_bridges_articulation.cpp) | Bridges and articulation points (Tarjan low-link). | [link](https://leetcode.com/problems/critical-connections-in-a-network/) |
| [`graph_cycle_detection_bipartite.cpp`](graph_cycle_detection_bipartite.cpp) | Cycle detection (undirected + directed) and bipartite check. | [link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1) |
| [`graph_dfs_connected_components.cpp`](graph_dfs_connected_components.cpp) | DFS: count connected components in an undirected graph. | — |
| [`graph_dijkstra_shortest_path.cpp`](graph_dijkstra_shortest_path.cpp) | Dijkstra's algorithm: shortest paths from a source in a weighted graph | — |
| [`graph_floyd_warshall.cpp`](graph_floyd_warshall.cpp) | Floyd-Warshall: all-pairs shortest paths. | [link](https://cses.fi/problemset/task/1672) |
| [`graph_grid_bfs_islands.cpp`](graph_grid_bfs_islands.cpp) | Grid graphs: Number of Islands (DFS flood fill) and Rotting Oranges (multi-source BFS). | [link](https://leetcode.com/problems/number-of-islands/) |
| [`graph_mst_kruskal_prim.cpp`](graph_mst_kruskal_prim.cpp) | Minimum Spanning Tree: Kruskal (sort edges + DSU) and Prim (priority queue). | [link](https://cses.fi/problemset/task/1675) |
| [`graph_scc_kosaraju.cpp`](graph_scc_kosaraju.cpp) | Strongly Connected Components (Kosaraju's algorithm). | [link](https://cses.fi/problemset/task/1683) |
| [`graph_toposort_kahn.cpp`](graph_toposort_kahn.cpp) | Topological sort of a DAG using Kahn's algorithm (BFS-style). | — |
| [`graph_zero_one_bfs.cpp`](graph_zero_one_bfs.cpp) | 0-1 BFS: shortest paths when every edge weighs 0 or 1. | [link](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh graphs` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Number Of Islands](https://leetcode.com/problems/number-of-islands/)
- [ ] [Flood Fill](https://leetcode.com/problems/flood-fill/)
- [ ] [CSES 1192 – Counting Rooms](https://cses.fi/problemset/task/1192)

**Medium**

- [ ] [Course Schedule](https://leetcode.com/problems/course-schedule/)
- [ ] [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)
- [ ] [Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [ ] [Is Graph Bipartite](https://leetcode.com/problems/is-graph-bipartite/)
- [ ] [CSES 1666 – Building Roads](https://cses.fi/problemset/task/1666)
- [ ] [CSES 1671 – Shortest Routes I](https://cses.fi/problemset/task/1671)

**Hard**

- [ ] [Critical Connections In A Network](https://leetcode.com/problems/critical-connections-in-a-network/)
- [ ] [CSES 1683 – Planets and Kingdoms](https://cses.fi/problemset/task/1683)
- [ ] [CSES 1197 – Cycle Finding](https://cses.fi/problemset/task/1197)
- [ ] [Minimum Cost To Make At Least One Valid Path In A Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)
