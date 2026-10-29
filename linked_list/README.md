# Linked Lists

[← back to roadmap](../README.md)

## What it is

Nodes connected by pointers; O(1) insert/delete at a known node, O(n) access.

## When to use it

- Pointer manipulation questions
- LRU cache (list + hash map)
- Cycle detection

## Intuition

Draw boxes and arrows. A dummy head removes edge cases; fast/slow pointers find the middle and cycles.

## Common patterns

- Dummy head
- Fast & slow pointers (Floyd)
- In-place reversal
- Gap of n between two pointers

## Template

```cpp
ListNode* prev = nullptr;
while (head) { ListNode* nxt = head->next; head->next = prev; prev = head; head = nxt; }
return prev;
```

## Pitfalls

- Losing the next pointer before rewiring
- Null checks on fast->next
- Memory leaks in demos (delete nodes)

## Complexity

O(n) traversal, O(1) extra space for most tricks.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`linked_list_cycle_detection.cpp`](linked_list_cycle_detection.cpp) | Linked list cycle detection using fast & slow pointers (Floyd's algorithm). | — |
| [`linked_list_reverse.cpp`](linked_list_reverse.cpp) | Iterative reversal of a singly linked list. | — |
| [`lru_cache.cpp`](lru_cache.cpp) | LRU Cache with std::list + std::unordered_map (O(1) get/put). | [link](https://leetcode.com/problems/lru-cache/) |
| [`merge_sorted_and_middle.cpp`](merge_sorted_and_middle.cpp) | Linked list classics: merge two sorted lists, middle node, remove N-th from end, | [link](https://leetcode.com/problems/merge-two-sorted-lists/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh linked_list` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [ ] [Middle Of The Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
- [ ] [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

**Medium**

- [ ] [Linked List Cycle Ii](https://leetcode.com/problems/linked-list-cycle-ii/)
- [ ] [Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [ ] [Lru Cache](https://leetcode.com/problems/lru-cache/)

**Hard**

- [ ] [Reverse Nodes In K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
- [ ] [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
