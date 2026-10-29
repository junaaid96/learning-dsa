// DP on grids: Minimum Path Sum and Grid Paths with obstacles.
//
// Problems:
//   (1) Minimum sum path from top-left to bottom-right moving right/down.
//       Link: https://leetcode.com/problems/minimum-path-sum/
//   (2) Count paths avoiding traps '*' (mod 1e9+7).
//       Link: https://cses.fi/problemset/task/1638
//
// Idea:
//   A cell is reached from the top or from the left, so
//   (1) dp[i][j] = g[i][j] + min(dp[i-1][j], dp[i][j-1])
//   (2) dp[i][j] = dp[i-1][j] + dp[i][j-1] (0 if trap).
//
// Time: O(R*C)    Space: O(C) using one rolling row
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_grid_min_path_sum.cpp -o grid && ./grid

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

int minPathSum(const std::vector<std::vector<int>>& g) {
    const int R = static_cast<int>(g.size()), C = static_cast<int>(g[0].size());
    std::vector<int> dp(C, INT_MAX);                       // dp[j] = best for current row
    dp[0] = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            int fromTop = dp[j];                            // value still from row i-1
            int fromLeft = j ? dp[j - 1] : INT_MAX;         // already updated for row i
            dp[j] = g[i][j] + std::min(fromTop, fromLeft);
        }
    return dp[C - 1];
}

long long gridPaths(const std::vector<std::string>& g) {
    const long long MOD = 1'000'000'007;
    const int n = static_cast<int>(g.size());
    std::vector<long long> dp(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '*') { dp[j] = 0; continue; }  // trap: no paths through it
            if (i == 0 && j == 0) { dp[j] = 1; continue; } // start cell
            if (j) dp[j] = (dp[j] + dp[j - 1]) % MOD;      // top (old dp[j]) + left
        }
    return dp[n - 1];
}

int main() {
    assert(minPathSum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) == 7);
    assert(minPathSum({{1, 2, 3}, {4, 5, 6}}) == 12);
    assert(gridPaths({"....", ".*..", "...*", "*..."}) == 3);  // CSES sample
    std::cout << "dp_grid_min_path_sum: all tests passed\n";
    return 0;
}
