# Arrays & Strings basics

[← back to roadmap](../README.md)

## What it is

Linear scans over contiguous memory: Kadane, prefix sums, fixed windows and two pointers on sorted data.

## When to use it

- Subarray / substring questions
- Sorted array pair questions

## Intuition

Most array problems become O(n) once you decide what to carry from index i to i+1 (a running sum, best so far, a window).

## Common patterns

- Kadane: best ending here = max(a[i], best ending at i-1 + a[i])
- Prefix sum: sum(l..r) = P[r+1] - P[l]
- Two pointers on sorted input

## Template

```cpp
long long best = a[0], cur = 0;
for (long long x : a) { cur = std::max(x, cur + x); best = std::max(best, cur); }
```

## Pitfalls

- All-negative arrays in Kadane
- Off-by-one in prefix indices
- Overflow in sums

## Complexity

Usually O(n) time, O(1)–O(n) space.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`kadane_max_subarray.cpp`](kadane_max_subarray.cpp) | Kadane's algorithm: maximum subarray sum in O(n). | — |
| [`prefix_sum_range_query.cpp`](prefix_sum_range_query.cpp) | Prefix sum: answer range sum queries in O(1) after O(n) preprocessing. | — |
| [`sliding_window_max_sum_k.cpp`](sliding_window_max_sum_k.cpp) | Sliding window: maximum sum subarray of fixed size k. | — |
| [`two_pointers_two_sum_sorted.cpp`](two_pointers_two_sum_sorted.cpp) | Two pointers: two-sum in a sorted array. | — |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh arrays_strings` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
- [ ] [Two Sum Ii Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

**Medium**

- [ ] [Range Sum Query Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
- [ ] [CSES 1643 – Maximum Subarray Sum](https://cses.fi/problemset/task/1643)

**Hard**

- [ ] [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)
