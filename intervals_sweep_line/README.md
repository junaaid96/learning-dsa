# Intervals & Sweep Line

[← back to roadmap](../README.md)

## What it is

Sort interval endpoints and process them in order, keeping a running state.

## When to use it

- Merge / insert intervals
- Max overlap at any time
- Meeting rooms

## Intuition

Turn each interval into events (+1 at start, −1 at end) and sweep left to right.

## Common patterns

- Sort by start, merge if overlap
- Event sweep with +1/−1
- Sort by end for selection

## Template

```cpp
std::sort(iv.begin(), iv.end());
for (auto& x : iv)
    if (out.empty() || out.back()[1] < x[0]) out.push_back(x);
    else out.back()[1] = std::max(out.back()[1], x[1]);
```

## Pitfalls

- Touching intervals: inclusive vs exclusive end
- Tie order of start/end events at the same time

## Complexity

O(n log n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`merge_insert_intervals.cpp`](merge_insert_intervals.cpp) | Intervals: merge, insert, non-overlapping removal, meeting rooms (min rooms). | [link](https://leetcode.com/problems/merge-intervals/) |
| [`sweep_line_events.cpp`](sweep_line_events.cpp) | Sweep line: max overlap (Restaurant Customers) and skyline-style coverage length. | [link](https://cses.fi/problemset/task/1619) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh intervals_sweep_line` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)
- [ ] [Summary Ranges](https://leetcode.com/problems/summary-ranges/)

**Medium**

- [ ] [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [ ] [Insert Interval](https://leetcode.com/problems/insert-interval/)
- [ ] [Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- [ ] [CSES 1619 – Restaurant Customers](https://cses.fi/problemset/task/1619)

**Hard**

- [ ] [Meeting Rooms Ii](https://leetcode.com/problems/meeting-rooms-ii/)
- [ ] [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)
