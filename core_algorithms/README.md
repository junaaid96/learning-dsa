# Core algorithms (binary search, merge sort, backtracking intro)

[← back to roadmap](../README.md)

## What it is

Three classic algorithm families: divide & conquer (merge sort), halving the search space (binary search) and exhaustive search (subsets).

## When to use it

- Sorted data or monotone predicates → binary search
- Need stable O(n log n) sort or inversion count → merge sort
- Small n, list all options → backtracking

## Intuition

Divide the problem, solve the halves, combine. Binary search discards half the candidates every step.

## Common patterns

- lo/hi invariant binary search
- merge two sorted halves
- choose / explore / un-choose

## Template

```cpp
int lo = 0, hi = n; // first index with a[i] >= x
while (lo < hi) { int mid = lo + (hi - lo) / 2; if (a[mid] < x) lo = mid + 1; else hi = mid; }
```

## Pitfalls

- Infinite loop from wrong mid/bounds
- `(lo + hi) / 2` overflow
- Forgetting to undo state in backtracking

## Complexity

Binary search O(log n); merge sort O(n log n) time, O(n) space; subsets O(2^n · n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`backtracking_subsets.cpp`](backtracking_subsets.cpp) | Backtracking: generate all subsets (power set) of a given set of integers. | — |
| [`binary_search_variants.cpp`](binary_search_variants.cpp) | Binary search variants on a sorted array: | — |
| [`merge_sort_demo.cpp`](merge_sort_demo.cpp) | Merge sort (divide & conquer) on an array of integers. | — |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh core_algorithms` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Binary Search](https://leetcode.com/problems/binary-search/)
- [ ] [Subsets](https://leetcode.com/problems/subsets/)

**Medium**

- [ ] [Sort An Array](https://leetcode.com/problems/sort-an-array/)
- [ ] [Search A 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

**Hard**

- [ ] [Count Of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
