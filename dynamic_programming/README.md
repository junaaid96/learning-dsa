# Dynamic Programming

[← back to roadmap](../README.md)

## What it is

Solve each subproblem once and store it. Define a state, a transition and base cases.

## When to use it

- "Count the ways", "min/max cost", "is it possible"
- Choices at each step with overlapping subproblems
- Constraints too big for brute force but small for n·W, n^2, 2^n·n

## Intuition

Write the brute-force recursion, notice repeated arguments, memoise, then convert to a bottom-up table.

## Common patterns

- 1D linear (stairs, robber)
- Knapsack 0/1, unbounded, bounded
- Grid DP
- Two strings (LCS, edit distance)
- LIS (n log n)
- Interval DP
- Bitmask DP
- Digit DP
- DP on trees

## Template

```cpp
std::vector<long long> dp(W + 1, 0);           // 0/1 knapsack
for (int i = 0; i < n; ++i)
    for (int w = W; w >= wt[i]; --w)            // backwards = each item once
        dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
```

## Pitfalls

- Loop direction decides 0/1 vs unbounded
- Wrong base case / initial INF
- Memory: roll arrays when only the last row is needed
- Mod arithmetic on counts

## Complexity

states × transitions.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`dp_bitmask_tsp.cpp`](dp_bitmask_tsp.cpp) | Bitmask DP: Travelling Salesman (shortest Hamiltonian cycle). | [link](https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/) |
| [`dp_climbing_stairs_house_robber.cpp`](dp_climbing_stairs_house_robber.cpp) | 1D DP: Climbing Stairs and House Robber. | [link](https://leetcode.com/problems/climbing-stairs/) |
| [`dp_coin_change.cpp`](dp_coin_change.cpp) | Coin Change: minimum coins (unbounded knapsack) and number of ways. | [link](https://leetcode.com/problems/coin-change/) |
| [`dp_digit_count.cpp`](dp_digit_count.cpp) | Digit DP intro: count numbers in [0, N] whose digit sum equals S. | [link](https://cses.fi/problemset/task/2220) |
| [`dp_grid_min_path_sum.cpp`](dp_grid_min_path_sum.cpp) | DP on grids: Minimum Path Sum and Grid Paths with obstacles. | [link](https://leetcode.com/problems/minimum-path-sum/) |
| [`dp_interval_burst_balloons.cpp`](dp_interval_burst_balloons.cpp) | Interval DP: Burst Balloons / Matrix chain style. | [link](https://leetcode.com/problems/burst-balloons/) |
| [`dp_knapsack_01.cpp`](dp_knapsack_01.cpp) | Dynamic Programming: 0/1 Knapsack problem. | — |
| [`dp_knapsack_unbounded_and_bounded.cpp`](dp_knapsack_unbounded_and_bounded.cpp) | Knapsack variants: 0/1 with 1D array, unbounded, and "Book Shop". | [link](https://cses.fi/problemset/task/1158) |
| [`dp_lcs_edit_distance.cpp`](dp_lcs_edit_distance.cpp) | 2D string DP: Longest Common Subsequence and Edit Distance. | [link](https://leetcode.com/problems/longest-common-subsequence/) |
| [`dp_lis_n2.cpp`](dp_lis_n2.cpp) | Dynamic Programming: Longest Increasing Subsequence (LIS) in O(n^2). | — |
| [`dp_lis_nlogn.cpp`](dp_lis_nlogn.cpp) | Longest Increasing Subsequence in O(n log n) (patience sorting). | [link](https://leetcode.com/problems/longest-increasing-subsequence/) |
| [`dp_on_trees.cpp`](dp_on_trees.cpp) | DP on trees: Maximum independent set / Tree Matching style + subtree sizes. | [link](https://leetcode.com/problems/house-robber-iii/) |
| [`dp_partition_subset_sum.cpp`](dp_partition_subset_sum.cpp) | Subset Sum / Partition Equal Subset Sum (0/1 knapsack on booleans). | [link](https://leetcode.com/problems/partition-equal-subset-sum/) |
| [`dp_unique_paths_grid.cpp`](dp_unique_paths_grid.cpp) | Matrix DP: Unique paths in an m x n grid. | — |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh dynamic_programming` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [ ] [House Robber](https://leetcode.com/problems/house-robber/)
- [ ] [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)
- [ ] [CSES 1633 – Dice Combinations](https://cses.fi/problemset/task/1633)

**Medium**

- [ ] [Coin Change](https://leetcode.com/problems/coin-change/)
- [ ] [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
- [ ] [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
- [ ] [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)
- [ ] [Unique Paths](https://leetcode.com/problems/unique-paths/)
- [ ] [CSES 1158 – Book Shop](https://cses.fi/problemset/task/1158)

**Hard**

- [ ] [Edit Distance](https://leetcode.com/problems/edit-distance/)
- [ ] [Burst Balloons](https://leetcode.com/problems/burst-balloons/)
- [ ] [CSES 2220 – Counting Numbers](https://cses.fi/problemset/task/2220)
- [ ] [CSES 1653 – Elevator Rides](https://cses.fi/problemset/task/1653)
