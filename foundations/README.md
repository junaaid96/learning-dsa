# Foundations (complexity, recursion, bits)

[← back to roadmap](../README.md)

## What it is

The toolkit everything else builds on: Big-O analysis, recursion with a base case, and basic bit operations.

## When to use it

- Before any topic: estimate whether an approach fits the limits (≈1e8 simple ops/sec).
- Any time a problem shrinks into a smaller copy of itself (recursion).

## Intuition

Read constraints first: n ≤ 20 → 2^n; n ≤ 500 → n^3; n ≤ 5000 → n^2; n ≤ 2e5 → n log n; n ≤ 1e7 → n.

## Common patterns

- Constraint → complexity table
- Recursion = base case + smaller subproblem + combine
- `n & (n-1)` clears the lowest set bit

## Template

```cpp
long long solve(int n) {
    if (n <= 1) return n;          // base case
    return solve(n - 1) + solve(n - 2); // smaller subproblems
}
```

## Pitfalls

- Missing base case → stack overflow
- int overflow: use long long when values exceed ~2e9
- Recursion depth > ~1e5 can crash; convert to iteration

## Complexity

Recursion depth d uses O(d) stack space.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`bit_manipulation_power_of_two.cpp`](bit_manipulation_power_of_two.cpp) | Bit manipulation: check if an integer is a power of two. | — |
| [`recursion_gcd_euclidean.cpp`](recursion_gcd_euclidean.cpp) | GCD using Euclidean algorithm: recursive and iterative versions. | — |
| [`time_space_complexity_demo.cpp`](time_space_complexity_demo.cpp) | Demonstration of different time complexities in simple loops. | — |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh foundations` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Power Of Two](https://leetcode.com/problems/power-of-two/)
- [ ] [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

**Medium**

- [ ] [Pow(x, n)](https://leetcode.com/problems/powx-n/)
- [ ] [CSES 1068 – Weird Algorithm](https://cses.fi/problemset/task/1068)

**Hard**

- [ ] [Count Good Numbers](https://leetcode.com/problems/count-good-numbers/)
