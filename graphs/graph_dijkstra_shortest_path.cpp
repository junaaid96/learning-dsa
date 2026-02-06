// Dijkstra's algorithm: shortest paths from a source in a weighted graph
// with non-negative edge weights.
//
// Compile: g++ -std=c++17 -O2 graph_dijkstra_shortest_path.cpp -o dijkstra
// Run:     ./dijkstra

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <limits>

struct Edge {
    int to{};
    int weight{};
};

std::vector<int> dijkstra(
    const std::vector<std::vector<Edge>>& adj,
    int source
) {
    const int n = static_cast<int>(adj.size());
    const int inf = std::numeric_limits<int>::max();
    std::vector<int> dist(static_cast<std::size_t>(n), inf);
    dist[source] = 0;

    using NodeDist = std::pair<int, int>; // (distance, node)
    std::priority_queue<NodeDist, std::vector<NodeDist>, std::greater<NodeDist>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        const auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist > dist[node]) {
            continue; // stale entry
        }

        for (const Edge& edge : adj[node]) {
            if (edge.weight < 0) {
                continue; // ignore negative edges in this demo
            }
            const int next = edge.to;
            const long long candidate = static_cast<long long>(currentDist) + edge.weight;
            if (candidate < dist[next]) {
                dist[next] = static_cast<int>(candidate);
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    // Example weighted directed graph:
    // 0 -> 1 (4), 0 -> 2 (1)
    // 2 -> 1 (2), 2 -> 3 (5)
    // 1 -> 3 (1)
    // 3 -> 4 (3)
    const int n = 5;
    std::vector<std::vector<Edge>> adj(n);

    auto addEdge = [&adj](int u, int v, int w) {
        adj[u].push_back(Edge{v, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(2, 3, 5);
    addEdge(1, 3, 1);
    addEdge(3, 4, 3);

    const int source = 0;
    const std::vector<int> dist = dijkstra(adj, source);

    std::cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << "Node " << i << ": unreachable\n";
        } else {
            std::cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}

