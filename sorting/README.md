# Sorting

[← back to roadmap](../README.md)

## What it is

Ordering data to expose structure: quick/merge/counting sort and custom comparators.

## When to use it

- Greedy that needs an order
- Removing duplicates / grouping
- Counting inversions

## Intuition

After sorting, equal or close elements are adjacent and many questions become linear scans.

## Common patterns

- std::sort with lambda comparator
- Merge sort counting inversions
- Counting sort for small value ranges

## Template

```cpp
std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
});
```

## Pitfalls

- Comparator must be strict weak ordering (never `<=`)
- Quick sort O(n^2) on bad pivots
- Stable order needs std::stable_sort

## Complexity

O(n log n) comparison sorts; counting sort O(n + K).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`count_inversions_merge_sort.cpp`](count_inversions_merge_sort.cpp) | Count inversions with merge sort. | [link](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) |
| [`custom_comparator_sort.cpp`](custom_comparator_sort.cpp) | Sorting with custom comparators: Sort Characters By Frequency + multi-key sort. | [link](https://leetcode.com/problems/sort-characters-by-frequency/) |
| [`quick_sort_and_counting_sort.cpp`](quick_sort_and_counting_sort.cpp) | Quick sort (Lomuto partition, random pivot) and counting sort. | [link](https://leetcode.com/problems/sort-an-array/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh sorting` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Sort Colors](https://leetcode.com/problems/sort-colors/)
- [ ] [Sort An Array](https://leetcode.com/problems/sort-an-array/)

**Medium**

- [ ] [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
- [ ] [Largest Number](https://leetcode.com/problems/largest-number/)
- [ ] [CSES 1621 – Distinct Numbers](https://cses.fi/problemset/task/1621)

**Hard**

- [ ] [GfG Inversion of array](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1)
- [ ] [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)
