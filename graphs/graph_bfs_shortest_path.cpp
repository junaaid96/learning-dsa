// BFS shortest path in an unweighted undirected graph.
//
// Idea:
//   BFS explores level by level; the first time we reach the target,
//   we have found the shortest path in terms of edge count.
//
// Compile: g++ -std=c++17 -O2 graph_bfs_shortest_path.cpp -o bfs_shortest
// Run:     ./bfs_shortest

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

std::vector<int> bfsShortestPath(
    const std::vector<std::vector<int>>& adj,
    int start,
    int target
) {
    const int n = static_cast<int>(adj.size());
    std::vector<bool> visited(static_cast<std::size_t>(n), false);
    std::vector<int> parent(static_cast<std::size_t>(n), -1);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        const int node = q.front();
        q.pop();

        if (node == target) {
            break;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (!visited[target]) {
        return {};
    }

    std::vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Example graph (undirected):
    // 0 -- 1 -- 2
    // |    |
    // 3 -- 4
    std::vector<std::vector<int>> adj(5);
    auto addEdge = [&adj](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 3);
    addEdge(3, 4);
    addEdge(1, 4);

    const int start = 0;
    const int target = 2;
    const std::vector<int> path = bfsShortestPath(adj, start, target);

    if (path.empty()) {
        std::cout << "No path from " << start << " to " << target << "\n";
    } else {
        std::cout << "Shortest path from " << start << " to " << target << ": ";
        for (int v : path) {
            std::cout << v << ' ';
        }
        std::cout << "\n";
    }

    return 0;
}

