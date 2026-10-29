# Matrices & 2D grids

[← back to roadmap](../README.md)

## What it is

Index manipulation on 2D arrays (rotation, spiral) and matrix multiplication for linear recurrences.

## When to use it

- Rotate / transpose / traverse in order
- Huge n linear recurrences (Fibonacci n = 1e18)

## Intuition

Rotation = transpose + reverse rows. A linear recurrence is a matrix power, computed in O(k^3 log n).

## Common patterns

- Layer-by-layer traversal with four bounds
- Transpose + reverse
- Matrix fast exponentiation

## Template

```cpp
Mat mul(const Mat& A, const Mat& B) { Mat C(k, std::vector<long long>(k));
    for (int i = 0; i < k; ++i) for (int l = 0; l < k; ++l) for (int j = 0; j < k; ++j)
        C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % MOD; return C; }
```

## Pitfalls

- Non-square matrices in rotate
- Bounds updates in spiral for single row/column

## Complexity

Traversal O(nm); matrix power O(k^3 log n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`matrix_exponentiation_fibonacci.cpp`](matrix_exponentiation_fibonacci.cpp) | Matrix exponentiation: n-th Fibonacci in O(log n) and counting paths of length k. | [link](https://cses.fi/problemset/task/1722) |
| [`matrix_rotate_spiral.cpp`](matrix_rotate_spiral.cpp) | Matrix manipulation: rotate 90 degrees in place, spiral order, set zeroes, search 2D. | [link](https://leetcode.com/problems/rotate-image/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh matrix_2d` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)
- [ ] [Flood Fill](https://leetcode.com/problems/flood-fill/)

**Medium**

- [ ] [Rotate Image](https://leetcode.com/problems/rotate-image/)
- [ ] [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [ ] [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

**Hard**

- [ ] [CSES 1722 – Fibonacci Numbers](https://cses.fi/problemset/task/1722)
- [ ] [CSES 1096 – Throwing Dice](https://cses.fi/problemset/task/1096)
