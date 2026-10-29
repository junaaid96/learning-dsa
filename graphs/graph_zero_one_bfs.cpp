// 0-1 BFS: shortest paths when every edge weighs 0 or 1.
//
// Problem (Minimum Cost to Make at Least One Valid Path in a Grid):
//   Each cell points right/left/down/up (1..4). Following the arrow costs 0,
//   changing it costs 1. Minimum cost from top-left to bottom-right.
// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
//
// Idea:
//   Dijkstra with a deque: push 0-weight neighbours to the FRONT and
//   1-weight neighbours to the BACK; the deque stays sorted by distance.
//
// Time: O(V + E)    Space: O(V)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_zero_one_bfs.cpp -o zobfs && ./zobfs

#include <cassert>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

int minCost(const std::vector<std::vector<int>>& g) {
    const int R = static_cast<int>(g.size()), C = static_cast<int>(g[0].size());
    const int dr[5] = {0, 0, 0, 1, -1}, dc[5] = {0, 1, -1, 0, 0};   // index = arrow 1..4
    std::vector<std::vector<int>> dist(R, std::vector<int>(C, INT_MAX));
    std::deque<std::pair<int, int>> dq;
    dist[0][0] = 0; dq.push_back({0, 0});
    while (!dq.empty()) {
        auto [r, c] = dq.front(); dq.pop_front();
        for (int d = 1; d <= 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            int w = (g[r][c] == d) ? 0 : 1;                // follow arrow free, else pay 1
            if (dist[r][c] + w < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + w;
                if (w == 0) dq.push_front({nr, nc});       // same distance -> front
                else dq.push_back({nr, nc});               // +1 -> back
            }
        }
    }
    return dist[R - 1][C - 1];
}

int main() {
    assert(minCost({{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}}) == 3);
    assert(minCost({{1, 1, 3}, {3, 2, 2}, {1, 1, 4}}) == 0);
    assert(minCost({{1, 2}, {4, 3}}) == 1);
    std::cout << "graph_zero_one_bfs: all tests passed\n";
    return 0;
}
