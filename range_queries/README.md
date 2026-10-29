# Range Queries (Fenwick, Segment Tree, Sparse Table)

[← back to roadmap](../README.md)

## What it is

Data structures answering range sum/min/max with point or range updates in O(log n).

## When to use it

- Many queries AND updates on an array
- Static RMQ with O(1) queries
- Inversion counting / order statistics

## Intuition

Precompute answers for well-chosen blocks (powers of two) and combine O(log n) of them.

## Common patterns

- Fenwick: prefix sums + point update
- Segment tree: any associative op, lazy for range updates
- Sparse table: idempotent op (min/max/gcd) O(1)

## Template

```cpp
struct BIT { int n; std::vector<long long> t;
    BIT(int n) : n(n), t(n + 1) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) t[i] += v; }
    long long sum(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; } };
```

## Pitfalls

- Fenwick is 1-indexed
- Segment tree size 4n
- Sparse table only for idempotent ops

## Complexity

Build O(n) / O(n log n); query O(log n) (sparse O(1)).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`fenwick_tree_bit.cpp`](fenwick_tree_bit.cpp) | Fenwick Tree (Binary Indexed Tree): point update + prefix sum. | [link](https://cses.fi/problemset/task/1648) |
| [`segment_tree.cpp`](segment_tree.cpp) | Segment Tree: point update + range minimum query (and a lazy range-add sum tree). | [link](https://cses.fi/problemset/task/1649) |
| [`sparse_table_rmq.cpp`](sparse_table_rmq.cpp) | Sparse Table: O(1) range minimum queries on a static array. | [link](https://cses.fi/problemset/task/1647) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh range_queries` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Range Sum Query Mutable](https://leetcode.com/problems/range-sum-query-mutable/)
- [ ] [CSES 1646 – Static Range Sum Queries](https://cses.fi/problemset/task/1646)

**Medium**

- [ ] [CSES 1648 – Dynamic Range Sum Queries](https://cses.fi/problemset/task/1648)
- [ ] [CSES 1647 – Static Range Minimum Queries](https://cses.fi/problemset/task/1647)
- [ ] [CSES 1649 – Dynamic Range Minimum Queries](https://cses.fi/problemset/task/1649)

**Hard**

- [ ] [Count Of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
- [ ] [CSES 1651 – Range Update Queries](https://cses.fi/problemset/task/1651)
- [ ] [CSES 1735 – Range Updates and Sums](https://cses.fi/problemset/task/1735)
