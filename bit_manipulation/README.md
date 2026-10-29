# Bit Manipulation

[← back to roadmap](../README.md)

## What it is

Treat integers as bit vectors: XOR tricks, masks for subsets, popcount, per-bit reasoning.

## When to use it

- Pairs cancel (XOR)
- n ≤ 20 subsets as masks
- AND/OR/XOR maximisation – think per bit

## Intuition

Every bit is independent for AND/OR/XOR; decide the answer bit by bit, highest first.

## Common patterns

- x ^ x = 0
- x & -x lowest set bit
- iterate submasks: for (s = m; s; s = (s-1) & m)
- prefix XOR

## Template

```cpp
for (int mask = 0; mask < (1 << n); ++mask)
    for (int i = 0; i < n; ++i)
        if (mask >> i & 1) { /* element i chosen */ }
```

## Pitfalls

- `1 << 31` overflows int – use 1LL
- Operator precedence: wrap `(x & 1) == 0`
- __builtin_popcountll for 64-bit

## Complexity

O(1) per op; subset enumeration O(2^n·n); submasks of all masks O(3^n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`bit_tricks_single_number.cpp`](bit_tricks_single_number.cpp) | Bit tricks: single number (XOR), counting bits, power of two, missing number. | [link](https://leetcode.com/problems/single-number/) |
| [`subset_enumeration_bitmask.cpp`](subset_enumeration_bitmask.cpp) | Bitmask subset enumeration, submask iteration, max AND/OR/XOR patterns. | [link](https://leetcode.com/problems/subsets/) |
| [`xor_prefix_and_bit_counting.cpp`](xor_prefix_and_bit_counting.cpp) | XOR prefix queries and per-bit contribution counting. | [link](https://leetcode.com/problems/xor-queries-of-a-subarray/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh bit_manipulation` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Single Number](https://leetcode.com/problems/single-number/)
- [ ] [Number Of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)
- [ ] [Counting Bits](https://leetcode.com/problems/counting-bits/)

**Medium**

- [ ] [Subsets](https://leetcode.com/problems/subsets/)
- [ ] [Single Number Ii](https://leetcode.com/problems/single-number-ii/)
- [ ] [Xor Queries Of A Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/)
- [ ] [CF 1421A – XORwice](https://codeforces.com/problemset/problem/1421/A)

**Hard**

- [ ] [Maximum Xor Of Two Numbers In An Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
- [ ] [CF 1527A – And Then There Were K](https://codeforces.com/problemset/problem/1527/A)
