# Hashing (hash maps & sets)

[← back to roadmap](../README.md)

## What it is

O(1) average lookup by key with `std::unordered_map` / `unordered_set` (or `std::map` for ordered keys).

## When to use it

- "Have I seen X before?"
- Counting frequencies
- Complement lookups (two sum, prefix sum = k)

## Intuition

Trade memory for time: store what you have seen so each new element asks one question instead of rescanning.

## Common patterns

- value → index (two sum)
- prefix sum → count (subarray sum = k)
- canonical key → group (anagrams)
- frequency map + bucket sort (top-k)

## Template

```cpp
std::unordered_map<long long, int> cnt{{0, 1}};
long long pre = 0, ans = 0;
for (long long x : a) { pre += x; ans += cnt[pre - k]; ++cnt[pre]; }
```

## Pitfalls

- `operator[]` inserts missing keys
- Anti-hash tests on Codeforces: use a custom hash or std::map
- Iteration order is unspecified

## Complexity

O(1) average per op, O(n) worst; O(n) space.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`group_anagrams.cpp`](group_anagrams.cpp) | Group Anagrams. | [link](https://leetcode.com/problems/group-anagrams/) |
| [`longest_consecutive_sequence.cpp`](longest_consecutive_sequence.cpp) | Longest Consecutive Sequence. | [link](https://leetcode.com/problems/longest-consecutive-sequence/) |
| [`subarray_sum_equals_k.cpp`](subarray_sum_equals_k.cpp) | Subarray Sum Equals K (prefix sum + hash map counting). | [link](https://leetcode.com/problems/subarray-sum-equals-k/) |
| [`top_k_frequent.cpp`](top_k_frequent.cpp) | Top K Frequent Elements (hash map + bucket sort). | [link](https://leetcode.com/problems/top-k-frequent-elements/) |
| [`two_sum_hashmap.cpp`](two_sum_hashmap.cpp) | Two Sum (unsorted array) using a hash map. | [link](https://leetcode.com/problems/two-sum/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh hashing` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Two Sum](https://leetcode.com/problems/two-sum/)
- [ ] [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [ ] [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

**Medium**

- [ ] [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
- [ ] [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [ ] [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
- [ ] [CSES 1640 – Sum of Two Values](https://cses.fi/problemset/task/1640)

**Hard**

- [ ] [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
- [ ] [Subarrays With K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)
