# Heaps / Priority Queues

[← back to roadmap](../README.md)

## What it is

`std::priority_queue` gives the max (or min with `std::greater`) in O(1) and push/pop in O(log n).

## When to use it

- Top-k / k-th largest
- Merging k sorted streams
- Always process the current best (Dijkstra, scheduling)
- Running median

## Intuition

Keep only what matters: a min-heap of size k holds the k largest seen so far.

## Common patterns

- Size-k min-heap
- Two heaps for median
- Greedy with heap (task scheduler)
- Heap of iterators for k-way merge

## Template

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // min-heap
for (int x : a) { pq.push(x); if ((int)pq.size() > k) pq.pop(); }
int kth = pq.top();
```

## Pitfalls

- Default priority_queue is a MAX heap
- Comparator meaning is reversed vs sort
- No decrease-key: push duplicates and skip stale

## Complexity

O(log n) push/pop, O(n) build.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`kth_largest_and_merge_k_lists.cpp`](kth_largest_and_merge_k_lists.cpp) | Heaps / priority_queue: Kth Largest Element and Merge K Sorted Arrays. | [link](https://leetcode.com/problems/kth-largest-element-in-an-array/) |
| [`median_from_data_stream.cpp`](median_from_data_stream.cpp) | Find Median from Data Stream (two heaps). | [link](https://leetcode.com/problems/find-median-from-data-stream/) |
| [`task_scheduler.cpp`](task_scheduler.cpp) | Task Scheduler (greedy counting; max-heap intuition). | [link](https://leetcode.com/problems/task-scheduler/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh heaps` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Kth Largest Element In A Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [ ] [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

**Medium**

- [ ] [Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [ ] [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- [ ] [K Closest Points To Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

**Hard**

- [ ] [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
- [ ] [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
