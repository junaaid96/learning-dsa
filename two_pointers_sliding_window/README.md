# Two Pointers & Sliding Window

[← back to roadmap](../README.md)

## What it is

Two indices move through the data in one direction so each element is touched O(1) times.

## When to use it

- Contiguous subarray/substring with a constraint
- Sorted array pair/triple sums
- "Longest/shortest window such that …"

## Intuition

If a window is valid, shrinking (or growing) it keeps a monotone property, so the left pointer never needs to move back.

## Common patterns

- Fixed window size k
- Variable window: expand right, shrink left while invalid
- Opposite ends on sorted data (3Sum, container)
- "at most K" − "at most K−1" = "exactly K"

## Template

```cpp
for (int l = 0, r = 0; r < n; ++r) {
    add(a[r]);
    while (!valid()) remove(a[l++]);
    best = std::max(best, r - l + 1);
}
```

## Pitfalls

- Sliding window on sums needs non-negative values (else use prefix sums + hash)
- Updating answer before vs after shrinking
- Duplicate skipping in 3Sum

## Complexity

O(n) time (each pointer moves ≤ n), O(1)–O(σ) space.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`container_with_most_water.cpp`](container_with_most_water.cpp) | Container With Most Water (opposite-direction two pointers). | [link](https://leetcode.com/problems/container-with-most-water/) |
| [`fixed_window_max_average.cpp`](fixed_window_max_average.cpp) | Maximum Average Subarray I (fixed-size sliding window). | [link](https://leetcode.com/problems/maximum-average-subarray-i/) |
| [`longest_substring_without_repeating.cpp`](longest_substring_without_repeating.cpp) | Longest Substring Without Repeating Characters (variable-size window). | [link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| [`minimum_window_substring.cpp`](minimum_window_substring.cpp) | Minimum Window Substring (variable window with "need" counter). | [link](https://leetcode.com/problems/minimum-window-substring/) |
| [`subarrays_with_k_distinct.cpp`](subarrays_with_k_distinct.cpp) | Subarrays with K Different Integers ("exactly K = atMost(K) - atMost(K-1)"). | [link](https://leetcode.com/problems/subarrays-with-k-different-integers/) |
| [`three_sum.cpp`](three_sum.cpp) | 3Sum (sort + two pointers). | [link](https://leetcode.com/problems/3sum/) |
| [`trapping_rain_water.cpp`](trapping_rain_water.cpp) | Trapping Rain Water (two pointers with running maxima). | [link](https://leetcode.com/problems/trapping-rain-water/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh two_pointers_sliding_window` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
- [ ] [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [ ] [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

**Medium**

- [ ] [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [ ] [3Sum](https://leetcode.com/problems/3sum/)
- [ ] [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [ ] [CSES 1141 – Playlist](https://cses.fi/problemset/task/1141)

**Hard**

- [ ] [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [ ] [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
- [ ] [Subarrays With K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)
