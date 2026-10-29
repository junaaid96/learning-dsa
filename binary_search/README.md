# Binary Search (on index and on answer)

[← back to roadmap](../README.md)

## What it is

Halve the search space each step. Works on sorted arrays and on any monotone yes/no predicate.

## When to use it

- Sorted input
- "Minimise the maximum" / "maximise the minimum"
- Answer space is a range and feasibility is monotone

## Intuition

If check(x) is false…false true…true, find the first true in O(log range) checks.

## Common patterns

- lower_bound / upper_bound
- Rotated array: one half is always sorted
- Binary search on answer + greedy check
- Partition search (median of two arrays)

## Template

```cpp
long long lo = L, hi = R;   // answer in [L, R], check monotone
while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (check(mid)) hi = mid; else lo = mid + 1;
}
```

## Pitfalls

- Wrong mid rounding with `lo = mid` (use mid = lo + (hi-lo+1)/2)
- Overflow inside check
- Non-monotone predicate

## Complexity

O(log n) per search; on-answer O(cost(check) · log range).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`aggressive_cows.cpp`](aggressive_cows.cpp) | Aggressive Cows (maximize the minimum distance; binary search on answer). | [link](https://www.spoj.com/problems/AGGRCOW/) |
| [`koko_eating_bananas.cpp`](koko_eating_bananas.cpp) | Koko Eating Bananas (binary search on the answer). | [link](https://leetcode.com/problems/koko-eating-bananas/) |
| [`lower_upper_bound_stl.cpp`](lower_upper_bound_stl.cpp) | STL binary search tools: lower_bound, upper_bound, equal_range. | [link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| [`median_two_sorted_arrays.cpp`](median_two_sorted_arrays.cpp) | Median of Two Sorted Arrays (binary search on the partition). | [link](https://leetcode.com/problems/median-of-two-sorted-arrays/) |
| [`search_rotated_sorted_array.cpp`](search_rotated_sorted_array.cpp) | Search in Rotated Sorted Array. | [link](https://leetcode.com/problems/search-in-rotated-sorted-array/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh binary_search` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Binary Search](https://leetcode.com/problems/binary-search/)
- [ ] [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

**Medium**

- [ ] [Find First And Last Position Of Element In Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- [ ] [Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [ ] [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
- [ ] [CSES 1620 – Factory Machines](https://cses.fi/problemset/task/1620)
- [ ] [CSES 1085 – Array Division](https://cses.fi/problemset/task/1085)

**Hard**

- [ ] [Median Of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
- [ ] [SPOJ AGGRCOW](https://www.spoj.com/problems/AGGRCOW/)
