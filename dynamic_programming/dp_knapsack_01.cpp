// Dynamic Programming: 0/1 Knapsack problem.
//
// Problem:
//   Given weights and values of n items and capacity W,
//   choose items to maximize total value such that total
//   weight <= W. Each item can be taken at most once.
//
// DP state:
//   dp[i][w] = maximum value using first i items (0..i-1)
//              with capacity w.
//
// Transition:
//   if weight[i-1] > w:
//       dp[i][w] = dp[i-1][w]
//   else:
//       dp[i][w] = max(
//           dp[i-1][w],                          // skip
//           value[i-1] + dp[i-1][w-weight[i-1]]  // take
//       )
//
// Compile: g++ -std=c++17 -O2 dp_knapsack_01.cpp -o knapsack
// Run:     ./knapsack

#include <iostream>
#include <vector>
#include <algorithm>

int knapSack(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
    const int n = static_cast<int>(weights.size());
    std::vector<std::vector<int>> dp(
        static_cast<std::size_t>(n + 1),
        std::vector<int>(static_cast<std::size_t>(capacity + 1), 0)
    );

    for (int i = 1; i <= n; ++i) {
        const int wt = weights[static_cast<std::size_t>(i - 1)];
        const int val = values[static_cast<std::size_t>(i - 1)];
        for (int w = 0; w <= capacity; ++w) {
            if (wt > w) {
                dp[static_cast<std::size_t>(i)][static_cast<std::size_t>(w)] =
                    dp[static_cast<std::size_t>(i - 1)][static_cast<std::size_t>(w)];
            } else {
                const int skip = dp[static_cast<std::size_t>(i - 1)][static_cast<std::size_t>(w)];
                const int take =
                    val + dp[static_cast<std::size_t>(i - 1)][static_cast<std::size_t>(w - wt)];
                dp[static_cast<std::size_t>(i)][static_cast<std::size_t>(w)] = std::max(skip, take);
            }
        }
    }

    return dp[static_cast<std::size_t>(n)][static_cast<std::size_t>(capacity)];
}

int main() {
    const std::vector<int> weights{10, 20, 30};
    const std::vector<int> values{60, 100, 120};
    const int capacity = 50;

    const int maxValue = knapSack(capacity, weights, values);

    std::cout << "0/1 Knapsack maximum value = " << maxValue << "\n";
    return 0;
}

