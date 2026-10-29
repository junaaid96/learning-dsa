// Bitmask DP: Travelling Salesman (shortest Hamiltonian cycle).
//
// Problem:
//   n <= 16 cities with distance matrix; start at 0, visit all, return to 0.
//   Find the minimum total distance.
// Links: https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
//        https://cses.fi/problemset/task/1690  (Hamiltonian Flights - counting variant)
//
// Idea:
//   dp[mask][v] = shortest path that starts at 0, visits exactly the cities in
//   `mask`, and currently stands at v. Transition: go to an unvisited u.
//
// Time: O(2^n * n^2)    Space: O(2^n * n)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_bitmask_tsp.cpp -o tsp && ./tsp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int tsp(const std::vector<std::vector<int>>& d) {
    const int n = static_cast<int>(d.size());
    const int INF = 1e9, FULL = 1 << n;
    std::vector<std::vector<int>> dp(FULL, std::vector<int>(n, INF));
    dp[1][0] = 0;                                          // mask {0}, standing at 0
    for (int mask = 1; mask < FULL; ++mask)
        for (int v = 0; v < n; ++v) {
            if (!(mask >> v & 1) || dp[mask][v] >= INF) continue;  // v must be in mask
            for (int u = 0; u < n; ++u) {
                if (mask >> u & 1) continue;               // already visited
                int nmask = mask | (1 << u);
                dp[nmask][u] = std::min(dp[nmask][u], dp[mask][v] + d[v][u]);
            }
        }
    int best = INF;
    for (int v = 1; v < n; ++v) best = std::min(best, dp[FULL - 1][v] + d[v][0]);  // go home
    return n == 1 ? 0 : best;
}

int main() {
    std::vector<std::vector<int>> d{{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    assert(tsp(d) == 80);
    std::cout << "dp_bitmask_tsp: all tests passed\n";
    return 0;
}
