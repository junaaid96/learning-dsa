# Math & Combinatorics

[← back to roadmap](../README.md)

## What it is

Counting (nCr, Pascal, stars and bars), digit manipulation and closed-form series.

## When to use it

- "How many ways…" without order constraints
- Digits of a number
- Arithmetic/geometric sums

## Intuition

Look for a formula before simulating: sums of 1..n, combinations, inclusion–exclusion.

## Common patterns

- Pascal triangle DP
- nCr mod p
- Digit extraction with % 10 and / 10
- Gauss sum n(n+1)/2

## Template

```cpp
std::vector<std::vector<long long>> C(N, std::vector<long long>(N));
for (int n = 0; n < N; ++n) { C[n][0] = 1; for (int k = 1; k <= n; ++k) C[n][k] = C[n-1][k-1] + C[n-1][k]; }
```

## Pitfalls

- Overflow in factorials
- Off-by-one in counting ranges
- Floating point for exact counts

## Complexity

Usually O(1)–O(n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`combinatorics_counting.cpp`](combinatorics_counting.cpp) | Counting: Pascal's triangle, Catalan numbers, stars and bars, derangements. | [link](https://leetcode.com/problems/pascals-triangle/) |
| [`math_basics_digits_series.cpp`](math_basics_digits_series.cpp) | Math basics: digit sums, palindrome number, sum formulas, ceil division, sqrt. | [link](https://leetcode.com/problems/palindrome-number/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh math_combinatorics` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Pascals Triangle](https://leetcode.com/problems/pascals-triangle/)
- [ ] [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
- [ ] [CSES 1068 – Weird Algorithm](https://cses.fi/problemset/task/1068)

**Medium**

- [ ] [Unique Paths](https://leetcode.com/problems/unique-paths/)
- [ ] [CSES 1071 – Number Spiral](https://cses.fi/problemset/task/1071)
- [ ] [CSES 1617 – Bit Strings](https://cses.fi/problemset/task/1617)

**Hard**

- [ ] [CSES 1715 – Creating Strings II](https://cses.fi/problemset/task/1715)
- [ ] [CSES 1716 – Distributing Apples](https://cses.fi/problemset/task/1716)
