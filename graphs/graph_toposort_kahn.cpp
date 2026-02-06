// Topological sort of a DAG using Kahn's algorithm (BFS-style).
//
// Idea:
//   - Compute in-degree of each node.
//   - Push nodes with in-degree 0 into queue.
//   - Repeatedly pop from queue, add to ordering, and decrement
//     in-degree of neighbors, pushing any that become 0.
//
// Compile: g++ -std=c++17 -O2 graph_toposort_kahn.cpp -o topo_kahn
// Run:     ./topo_kahn

#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topologicalSortKahn(const std::vector<std::vector<int>>& adj) {
    const int n = static_cast<int>(adj.size());
    std::vector<int> indegree(static_cast<std::size_t>(n), 0);

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            ++indegree[v];
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> order;
    order.reserve(static_cast<std::size_t>(n));

    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (static_cast<int>(order.size()) != n) {
        // Graph had a cycle; no valid topological order.
        return {};
    }
    return order;
}

int main() {
    // Example DAG:
    // 5 -> 0, 5 -> 2
    // 4 -> 0, 4 -> 1
    // 2 -> 3
    // 3 -> 1
    const int n = 6;
    std::vector<std::vector<int>> adj(n);
    auto addEdge = [&adj](int u, int v) {
        adj[u].push_back(v);
    };

    addEdge(5, 0);
    addEdge(5, 2);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    const std::vector<int> order = topologicalSortKahn(adj);

    if (order.empty()) {
        std::cout << "Graph has a cycle; no topological ordering.\n";
    } else {
        std::cout << "Topological order: ";
        for (int v : order) {
            std::cout << v << ' ';
        }
        std::cout << "\n";
    }

    return 0;
}

