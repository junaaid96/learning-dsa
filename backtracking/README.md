# Backtracking

[← back to roadmap](../README.md)

## What it is

Build candidates one choice at a time and undo the choice after exploring it.

## When to use it

- "Generate all" permutations/combinations/subsets
- Constraint satisfaction (N-Queens, Sudoku)
- n small (≤ ~20)

## Intuition

A DFS over the decision tree; prune branches that cannot lead to a valid answer.

## Common patterns

- choose → recurse → un-choose
- start index to avoid duplicate combinations
- used[] array for permutations
- sort + skip duplicates

## Template

```cpp
void bt(int start) {
    res.push_back(cur);
    for (int i = start; i < n; ++i) {
        cur.push_back(a[i]); bt(i + 1); cur.pop_back();
    }
}
```

## Pitfalls

- Forgetting to undo
- Copying big state each call
- Missing pruning → TLE

## Complexity

Exponential: subsets O(2^n·n), permutations O(n!·n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`combination_sum.cpp`](combination_sum.cpp) | Combination Sum (unlimited reuse) and Combination Sum II (each used once). | [link](https://leetcode.com/problems/combination-sum/) |
| [`n_queens.cpp`](n_queens.cpp) | N-Queens (backtracking with column/diagonal markers). | [link](https://leetcode.com/problems/n-queens-ii/) |
| [`permutations.cpp`](permutations.cpp) | Permutations (backtracking with a "used" array) + unique permutations. | [link](https://leetcode.com/problems/permutations/) |
| [`subsets_and_word_search.cpp`](subsets_and_word_search.cpp) | Subsets II (with duplicates) and Word Search (grid backtracking). | [link](https://leetcode.com/problems/subsets-ii/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh backtracking` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Subsets](https://leetcode.com/problems/subsets/)
- [ ] [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)
- [ ] [CSES 1623 – Apple Division](https://cses.fi/problemset/task/1623)

**Medium**

- [ ] [Permutations](https://leetcode.com/problems/permutations/)
- [ ] [Combination Sum](https://leetcode.com/problems/combination-sum/)
- [ ] [Word Search](https://leetcode.com/problems/word-search/)
- [ ] [CSES 1622 – Creating Strings](https://cses.fi/problemset/task/1622)

**Hard**

- [ ] [N Queens Ii](https://leetcode.com/problems/n-queens-ii/)
- [ ] [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
- [ ] [CSES 1624 – Chessboard and Queens](https://cses.fi/problemset/task/1624)
