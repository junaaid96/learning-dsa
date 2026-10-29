// Grid graphs: Number of Islands (DFS flood fill) and Rotting Oranges (multi-source BFS).
//
// Problems:
//   (1) Count connected groups of '1' cells (4-directional).
//       Links: https://leetcode.com/problems/number-of-islands/  https://cses.fi/problemset/task/1192
//   (2) Every minute rotten oranges (2) rot their fresh neighbours (1).
//       Minutes until none fresh, or -1.
//       Link: https://leetcode.com/problems/rotting-oranges/
//
// Idea:
//   Treat each cell as a node with up to 4 neighbours (dr/dc arrays).
//   (2) Start BFS from ALL rotten cells at once; BFS layers are minutes.
//
// Time: O(R*C)    Space: O(R*C)
//
// Compile: g++ -std=c++17 -Wall -Wextra graph_grid_bfs_islands.cpp -o grid && ./grid

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};   // down, up, right, left

int numIslands(std::vector<std::string> g) {
    const int R = static_cast<int>(g.size()), C = static_cast<int>(g[0].size());
    int count = 0;
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            if (g[r][c] != '1') continue;
            ++count;                                       // new island found
            std::vector<std::pair<int, int>> st{{r, c}};   // iterative DFS (no deep recursion)
            g[r][c] = '0';                                 // sink it so it is not counted again
            while (!st.empty()) {
                auto [x, y] = st.back(); st.pop_back();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dr[k], ny = y + dc[k];
                    if (nx < 0 || ny < 0 || nx >= R || ny >= C || g[nx][ny] != '1') continue;
                    g[nx][ny] = '0';
                    st.push_back({nx, ny});
                }
            }
        }
    return count;
}

int orangesRotting(std::vector<std::vector<int>> g) {
    const int R = static_cast<int>(g.size()), C = static_cast<int>(g[0].size());
    std::queue<std::pair<int, int>> q;
    int fresh = 0;
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            if (g[r][c] == 2) q.push({r, c});              // all sources at time 0
            else if (g[r][c] == 1) ++fresh;
        }
    int minutes = 0;
    while (!q.empty() && fresh > 0) {
        for (int s = static_cast<int>(q.size()); s > 0; --s) {   // process one layer
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dr[k], ny = y + dc[k];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C || g[nx][ny] != 1) continue;
                g[nx][ny] = 2; --fresh; q.push({nx, ny});
            }
        }
        ++minutes;
    }
    return fresh ? -1 : minutes;
}

int main() {
    assert(numIslands({"11110", "11010", "11000", "00000"}) == 1);
    assert(numIslands({"11000", "11000", "00100", "00011"}) == 3);
    assert(orangesRotting({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) == 4);
    assert(orangesRotting({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}) == -1);
    assert(orangesRotting({{0, 2}}) == 0);
    std::cout << "graph_grid_bfs_islands: all tests passed\n";
    return 0;
}
