// Matrix DP: Unique paths in an m x n grid.
//
// Problem:
//   You are at top-left (0,0), want to reach bottom-right (m-1,n-1),
//   moving only right or down. Count unique paths.
//
// State:
//   dp[i][j] = number of ways to reach cell (i,j).
//
// Transition:
//   dp[i][j] = dp[i-1][j] + dp[i][j-1] (if inside grid).
//
// Compile: g++ -std=c++17 -O2 dp_unique_paths_grid.cpp -o unique_paths
// Run:     ./unique_paths

#include <iostream>
#include <vector>

long long uniquePaths(int m, int n) {
    std::vector<std::vector<long long>> dp(
        static_cast<std::size_t>(m),
        std::vector<long long>(static_cast<std::size_t>(n), 0)
    );

    for (int i = 0; i < m; ++i) {
        dp[static_cast<std::size_t>(i)][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][static_cast<std::size_t>(j)] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)] =
                dp[static_cast<std::size_t>(i - 1)][static_cast<std::size_t>(j)] +
                dp[static_cast<std::size_t>(i)][static_cast<std::size_t>(j - 1)];
        }
    }

    return dp[static_cast<std::size_t>(m - 1)][static_cast<std::size_t>(n - 1)];
}

int main() {
    const int m = 3;
    const int n = 7;

    const long long paths = uniquePaths(m, n);
    std::cout << "Unique paths in a " << m << "x" << n << " grid = " << paths << "\n";

    return 0;
}

