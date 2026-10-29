// Bellman-Ford: shortest paths with negative edges + negative cycle detection.
//
// Problem:
//   Directed weighted graph (weights may be negative). Distances from source,
//   or report that a negative cycle is reachable.
// Links: https://cses.fi/problemset/task/1197  (Cycle Finding)
//        https://leetcode.com/problems/cheapest-flights-within-k-stops/  (bounded variant)
//
// Idea:
//   Any shortest path uses at most n-1 edges, so relaxing every edge n-1 times
//   is enough. If an n-th round still relaxes something, a negative cycle exists.
//
// Time: O(n * m)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_bellman_ford.cpp -o bf && ./bf

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

struct Edge { int u, v; long long w; };
const long long INF = LLONG_MAX / 4;

// returns false if a negative cycle is reachable from src
bool bellmanFord(int n, const std::vector<Edge>& edges, int src, std::vector<long long>& dist) {
    dist.assign(n, INF);
    dist[src] = 0;
    for (int round = 0; round < n; ++round) {
        bool changed = false;
        for (const Edge& e : edges)
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) {   // relax u -> v
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        if (!changed) return true;                 // converged early
        if (round == n - 1) return false;          // still changing in n-th round
    }
    return true;
}

int main() {
    std::vector<long long> d;
    std::vector<Edge> e{{0, 1, 4}, {0, 2, 5}, {1, 2, -3}, {2, 3, 4}, {3, 1, 2}};
    assert(bellmanFord(4, e, 0, d));
    assert(d[1] == 4 && d[2] == 1 && d[3] == 5);
    std::vector<Edge> neg{{0, 1, 1}, {1, 2, -2}, {2, 1, 1}};    // 1 -> 2 -> 1 weighs -1
    assert(!bellmanFord(3, neg, 0, d));
    std::cout << "graph_bellman_ford: all tests passed\n";
    return 0;
}
