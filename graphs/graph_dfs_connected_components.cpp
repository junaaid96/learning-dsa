// DFS: count connected components in an undirected graph.
//
// Idea:
//   For each unvisited node, run DFS/BFS and mark all reachable nodes.
//   Each DFS run corresponds to one connected component.
//
// Compile: g++ -std=c++17 -O2 graph_dfs_connected_components.cpp -o dfs_components
// Run:     ./dfs_components

#include <iostream>
#include <vector>

void dfs(
    int node,
    const std::vector<std::vector<int>>& adj,
    std::vector<bool>& visited
) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(const std::vector<std::vector<int>>& adj) {
    const int n = static_cast<int>(adj.size());
    std::vector<bool> visited(static_cast<std::size_t>(n), false);
    int components = 0;

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            ++components;
            dfs(v, adj, visited);
        }
    }
    return components;
}

int main() {
    // Example: 5 nodes {0..4}, edges:
    // 0-1, 1-2, 3-4 -> components: {0,1,2}, {3,4}
    std::vector<std::vector<int>> adj(5);
    auto addEdge = [&adj](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(3, 4);

    const int components = countConnectedComponents(adj);
    std::cout << "Number of connected components: " << components << "\n";

    return 0;
}

