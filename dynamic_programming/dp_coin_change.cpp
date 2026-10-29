// Coin Change: minimum coins (unbounded knapsack) and number of ways.
//
// Problems:
//   (1) Fewest coins to make `amount`, or -1.
//       Links: https://leetcode.com/problems/coin-change/   https://cses.fi/problemset/task/1634
//   (2) Number of combinations (order does not matter) to make `amount`.
//       Links: https://leetcode.com/problems/coin-change-ii/  https://cses.fi/problemset/task/1636
//
// Idea:
//   (1) dp[x] = 1 + min over coins c of dp[x - c].
//   (2) Loop coins OUTSIDE and amounts inside so each combination is counted
//       once (coins are added in a fixed order). Swapping the loops counts
//       ordered sequences instead (CSES 1635).
//
// Time: O(amount * coins)    Space: O(amount)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_coin_change.cpp -o coin && ./coin

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

int coinChange(const std::vector<int>& coins, int amount) {
    const int INF = INT_MAX / 2;                      // "impossible" that will not overflow on +1
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;                                        // zero coins make amount 0
    for (int x = 1; x <= amount; ++x)
        for (int c : coins)
            if (c <= x) dp[x] = std::min(dp[x], dp[x - c] + 1);   // last coin is c
    return dp[amount] >= INF ? -1 : dp[amount];
}

long long countWays(const std::vector<int>& coins, int amount) {
    std::vector<long long> dp(amount + 1, 0);
    dp[0] = 1;                                        // one way to make 0: choose nothing
    for (int c : coins)                               // coins outer -> combinations
        for (int x = c; x <= amount; ++x) dp[x] += dp[x - c];
    return dp[amount];
}

int main() {
    assert(coinChange({1, 2, 5}, 11) == 3);
    assert(coinChange({2}, 3) == -1);
    assert(coinChange({1}, 0) == 0);
    assert(countWays({1, 2, 5}, 5) == 4);
    assert(countWays({2}, 3) == 0);
    std::cout << "dp_coin_change: all tests passed\n";
    return 0;
}
