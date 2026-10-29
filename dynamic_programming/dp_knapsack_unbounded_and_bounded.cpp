// Knapsack variants: 0/1 with 1D array, unbounded, and "Book Shop".
//
// Problems:
//   (1) Book Shop (0/1 knapsack): max pages with total price <= x.
//       Link: https://cses.fi/problemset/task/1158
//   (2) Unbounded knapsack: items can be taken any number of times.
//       Link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
//
// Idea:
//   dp[w] = best value with capacity w.
//   0/1:       iterate w DOWNWARD so dp[w - wt] still means "without this item".
//   Unbounded: iterate w UPWARD so dp[w - wt] may already include this item.
//
// Time: O(n * W)    Space: O(W)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_knapsack_unbounded_and_bounded.cpp -o knap && ./knap

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int knap01(const std::vector<int>& wt, const std::vector<int>& val, int W) {
    std::vector<int> dp(W + 1, 0);
    for (std::size_t i = 0; i < wt.size(); ++i)
        for (int w = W; w >= wt[i]; --w)                       // downward = use once
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

int knapUnbounded(const std::vector<int>& wt, const std::vector<int>& val, int W) {
    std::vector<int> dp(W + 1, 0);
    for (std::size_t i = 0; i < wt.size(); ++i)
        for (int w = wt[i]; w <= W; ++w)                       // upward = reuse allowed
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

int main() {
    assert(knap01({4, 8, 5, 3}, {5, 12, 8, 1}, 10) == 13);    // CSES Book Shop sample
    assert(knapUnbounded({1, 3, 4, 5}, {1, 4, 5, 7}, 8) == 11);
    std::cout << "dp_knapsack_unbounded_and_bounded: all tests passed\n";
    return 0;
}
