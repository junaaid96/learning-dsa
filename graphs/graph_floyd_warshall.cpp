// Floyd-Warshall: all-pairs shortest paths.
//
// Problem:
//   Shortest distance between every pair of nodes (n <= ~500).
// Links: https://cses.fi/problemset/task/1672
//        https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
//
// Idea:
//   d[i][j] using only intermediate nodes {0..k}. Adding node k:
//   d[i][j] = min(d[i][j], d[i][k] + d[k][j]). The k loop MUST be outermost.
//
// Time: O(n^3)    Space: O(n^2)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_floyd_warshall.cpp -o fw && ./fw

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

const long long INF = 1e18;

void floyd(std::vector<std::vector<long long>>& d) {
    const int n = static_cast<int>(d.size());
    for (int k = 0; k < n; ++k)                       // allow k as a middle stop
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    // CSES 1672 sample: 4 nodes, roads (1,2,5) (1,3,9) (2,3,3), undirected
    std::vector<std::vector<long long>> d(4, std::vector<long long>(4, INF));
    for (int i = 0; i < 4; ++i) d[i][i] = 0;
    auto road = [&](int a, int b, long long w) { d[a][b] = std::min(d[a][b], w); d[b][a] = std::min(d[b][a], w); };
    road(0, 1, 5); road(0, 2, 9); road(1, 2, 3);
    floyd(d);
    assert(d[0][1] == 5 && d[0][2] == 8 && d[1][2] == 3);
    assert(d[0][3] == INF);                           // unreachable stays INF (-1 in CSES)
    std::cout << "graph_floyd_warshall: all tests passed\n";
    return 0;
}
