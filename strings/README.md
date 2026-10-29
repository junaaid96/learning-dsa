# String Algorithms

[← back to roadmap](../README.md)

## What it is

Pattern matching and structure in strings: frequency tricks, KMP/prefix function, Z-function, hashing and palindromes.

## When to use it

- Find a pattern in text fast
- Borders / periods
- Compare substrings in O(1)
- Longest palindrome

## Intuition

Reuse work: when a match fails, the prefix function tells you how far you can shift without rechecking.

## Common patterns

- Frequency array of 26
- Prefix function π
- Z-array
- Polynomial rolling hash (mod 2^61-1 or double mod)
- Manacher / expand around centre

## Template

```cpp
std::vector<int> pi(n);
for (int i = 1; i < n; ++i) {
    int k = pi[i - 1];
    while (k && s[i] != s[k]) k = pi[k - 1];
    if (s[i] == s[k]) ++k;
    pi[i] = k;
}
```

## Pitfalls

- Hash collisions: use big mod / two mods
- Separator char in "pattern#text"
- std::string concatenation in loops is O(n^2)

## Complexity

KMP / Z / Manacher O(n); hashing O(n) build, O(1) per compare.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`kmp_prefix_function.cpp`](kmp_prefix_function.cpp) | KMP / prefix function: find all occurrences of a pattern in O(n + m). | [link](https://cses.fi/problemset/task/1753) |
| [`palindromes_manacher.cpp`](palindromes_manacher.cpp) | Palindromes: expand-around-center and Manacher's O(n) algorithm. | [link](https://leetcode.com/problems/longest-palindromic-substring/) |
| [`rolling_hash.cpp`](rolling_hash.cpp) | Polynomial rolling hash: O(1) substring comparisons after O(n) precompute. | [link](https://leetcode.com/problems/repeated-dna-sequences/) |
| [`string_basics_anagram_freq.cpp`](string_basics_anagram_freq.cpp) | String basics: frequency arrays, valid anagram, first unique char, reverse words. | [link](https://leetcode.com/problems/valid-anagram/) |
| [`z_function.cpp`](z_function.cpp) | Z-function: z[i] = longest common prefix of s and s[i..]. | [link](https://cses.fi/problemset/task/2107) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh strings` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [ ] [Find The Index Of The First Occurrence In A String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

**Medium**

- [ ] [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- [ ] [Repeated Dna Sequences](https://leetcode.com/problems/repeated-dna-sequences/)
- [ ] [CSES 1753 – String Matching](https://cses.fi/problemset/task/1753)
- [ ] [CSES 1755 – Palindrome Reorder](https://cses.fi/problemset/task/1755)

**Hard**

- [ ] [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)
- [ ] [CSES 2107 – Finding Borders](https://cses.fi/problemset/task/2107)
- [ ] [CSES 1111 – Longest Palindrome](https://cses.fi/problemset/task/1111)
