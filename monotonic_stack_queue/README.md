# Monotonic Stack & Queue

[← back to roadmap](../README.md)

## What it is

A stack/deque kept sorted so that each element is pushed and popped once, answering "nearest greater/smaller" queries in O(n).

## When to use it

- Next/previous greater or smaller element
- Largest rectangle / span problems
- Sliding window min/max

## Intuition

When a new element arrives, any older element that is worse AND older can never be the answer again → pop it.

## Common patterns

- Increasing stack → previous smaller
- Decreasing stack → next greater
- Deque of indices for window extremes
- Circular arrays: iterate 2n

## Template

```cpp
std::vector<int> st, res(n, -1);
for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.back()] < a[i]) { res[st.back()] = a[i]; st.pop_back(); }
    st.push_back(i);
}
```

## Pitfalls

- Store indices, not values
- Strict vs non-strict comparison with duplicates
- Pop expired indices from the deque front

## Complexity

O(n) amortised, O(n) space.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`largest_rectangle_histogram.cpp`](largest_rectangle_histogram.cpp) | Largest Rectangle in Histogram (monotonic increasing stack). | [link](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| [`next_greater_element.cpp`](next_greater_element.cpp) | Next Greater Element (monotonic decreasing stack). | [link](https://leetcode.com/problems/next-greater-element-ii/) |
| [`sliding_window_minimum_deque.cpp`](sliding_window_minimum_deque.cpp) | Sliding Window Minimum + Shortest Subarray with Sum >= K (monotonic deque). | [link](https://cses.fi/problemset/task/3221) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh monotonic_stack_queue` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
- [ ] [CSES 1645 – Nearest Smaller Values](https://cses.fi/problemset/task/1645)

**Medium**

- [ ] [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
- [ ] [Next Greater Element Ii](https://leetcode.com/problems/next-greater-element-ii/)
- [ ] [Online Stock Span](https://leetcode.com/problems/online-stock-span/)

**Hard**

- [ ] [Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- [ ] [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- [ ] [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
