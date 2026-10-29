# Stacks & Queues

[← back to roadmap](../README.md)

## What it is

LIFO (stack) and FIFO (queue/deque) containers for matching, undo, and order-preserving processing.

## When to use it

- Matching brackets / nested structure
- Evaluate expressions
- BFS order

## Intuition

A stack remembers the most recent unresolved item; a queue processes items in arrival order.

## Common patterns

- Bracket matching
- Min stack with paired values
- RPN evaluation
- Deque window maximum

## Template

```cpp
std::stack<char> st;
for (char c : s) {
    if (c == '(') st.push(c);
    else { if (st.empty()) return false; st.pop(); }
}
return st.empty();
```

## Pitfalls

- top()/pop() on an empty stack is UB
- Operand order for `-` and `/` in RPN

## Complexity

O(1) per operation.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`deque_sliding_window_maximum.cpp`](deque_sliding_window_maximum.cpp) | Monotonic deque: sliding window maximum in O(n). | — |
| [`min_stack_and_rpn.cpp`](min_stack_and_rpn.cpp) | Stack design + expression problems: Min Stack, Evaluate RPN, Daily Temperatures, | [link](https://leetcode.com/problems/min-stack/) |
| [`stack_valid_parentheses.cpp`](stack_valid_parentheses.cpp) | Valid parentheses using a stack. | — |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh stack_queue` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- [ ] [Implement Queue Using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

**Medium**

- [ ] [Min Stack](https://leetcode.com/problems/min-stack/)
- [ ] [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
- [ ] [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

**Hard**

- [ ] [Basic Calculator](https://leetcode.com/problems/basic-calculator/)
- [ ] [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
