# Prefix Sums & Difference Arrays

[← back to roadmap](../README.md)

## What it is

Precompute cumulative sums so any range sum is O(1); difference arrays apply many range updates in O(1) each.

## When to use it

- Many range-sum queries on static data
- Many range "add v to [l, r]" updates followed by reads
- 2D sub-rectangle sums

## Intuition

P[i] = a[0] + … + a[i-1]; a range is the difference of two prefixes. Difference arrays are the inverse: mark +v at l, −v at r+1, then prefix-sum.

## Common patterns

- 1D prefix
- 2D prefix (inclusion–exclusion)
- Difference array
- Prefix/suffix products

## Template

```cpp
std::vector<long long> P(n + 1, 0);
for (int i = 0; i < n; ++i) P[i + 1] = P[i] + a[i];
auto sum = [&](int l, int r) { return P[r + 1] - P[l]; };
```

## Pitfalls

- Off-by-one with 1-indexed vs 0-indexed
- Overflow → long long
- Negative modulo when using prefix % m

## Complexity

O(n) build, O(1) query; 2D O(nm) build.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`difference_array_range_add.cpp`](difference_array_range_add.cpp) | Difference array: many "add v to range [l, r]" updates, then read all values. | [link](https://leetcode.com/problems/corporate-flight-bookings/) |
| [`product_except_self.cpp`](product_except_self.cpp) | Product of Array Except Self (prefix and suffix products, no division). | [link](https://leetcode.com/problems/product-of-array-except-self/) |
| [`range_sum_2d.cpp`](range_sum_2d.cpp) | Range Sum Query 2D - Immutable (2D prefix sums). | [link](https://leetcode.com/problems/range-sum-query-2d-immutable/) |
| [`static_range_sum_cses.cpp`](static_range_sum_cses.cpp) | Static Range Sum Queries (1D prefix sums). | [link](https://cses.fi/problemset/task/1646) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh prefix_sum_difference` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Running Sum Of 1D Array](https://leetcode.com/problems/running-sum-of-1d-array/)
- [ ] [CSES 1646 – Static Range Sum Queries](https://cses.fi/problemset/task/1646)

**Medium**

- [ ] [Product Of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [ ] [Range Sum Query 2D Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)
- [ ] [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)
- [ ] [CSES 1662 – Subarray Divisibility](https://cses.fi/problemset/task/1662)

**Hard**

- [ ] [CSES 1652 – Forest Queries](https://cses.fi/problemset/task/1652)
- [ ] [CF 1584D – Guess the Permutation](https://codeforces.com/problemset/problem/1584/D)
