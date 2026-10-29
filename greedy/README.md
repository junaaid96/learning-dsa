# Greedy

[← back to roadmap](../README.md)

## What it is

Make the locally best choice at every step and never undo it — correct only when an exchange argument proves it.

## When to use it

- Scheduling / interval selection
- "Minimum number of X to cover Y"
- Sorted order makes the choice obvious

## Intuition

Prove: any optimal solution can be changed to include the greedy choice without getting worse.

## Common patterns

- Sort by end time (activity selection)
- Ratio sort (fractional knapsack)
- Reach / fuel balance (jump game, gas station)
- Two pointers after sorting (Ferris wheel)

## Template

```cpp
std::sort(iv.begin(), iv.end(), [](auto& a, auto& b) { return a.second < b.second; });
int cnt = 0, end = INT_MIN;
for (auto [s, e] : iv) if (s >= end) { ++cnt; end = e; }
```

## Pitfalls

- Greedy that "feels right" but fails — test small counterexamples
- 0/1 knapsack is NOT greedy
- Ties in sorting

## Complexity

Usually O(n log n) for the sort.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`activity_selection_movie_festival.cpp`](activity_selection_movie_festival.cpp) | Activity selection / Movie Festival (sort by end time, take greedily). | [link](https://cses.fi/problemset/task/1629) |
| [`fractional_knapsack.cpp`](fractional_knapsack.cpp) | Fractional Knapsack (greedy by value/weight ratio). | [link](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1) |
| [`gas_station.cpp`](gas_station.cpp) | Gas Station (greedy restart). | [link](https://leetcode.com/problems/gas-station/) |
| [`jump_game.cpp`](jump_game.cpp) | Jump Game I and II (greedy reach). | [link](https://leetcode.com/problems/jump-game/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh greedy` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Assign Cookies](https://leetcode.com/problems/assign-cookies/)
- [ ] [Lemonade Change](https://leetcode.com/problems/lemonade-change/)

**Medium**

- [ ] [Jump Game](https://leetcode.com/problems/jump-game/)
- [ ] [Gas Station](https://leetcode.com/problems/gas-station/)
- [ ] [CSES 1629 – Movie Festival](https://cses.fi/problemset/task/1629)
- [ ] [CSES 1090 – Ferris Wheel](https://cses.fi/problemset/task/1090)
- [ ] [CSES 1074 – Stick Lengths](https://cses.fi/problemset/task/1074)

**Hard**

- [ ] [Jump Game Ii](https://leetcode.com/problems/jump-game-ii/)
- [ ] [Candy](https://leetcode.com/problems/candy/)
- [ ] [CSES 2183 – Missing Coin Sum](https://cses.fi/problemset/task/2183)
