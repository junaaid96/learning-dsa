# DSA Patterns Cheatsheet

[← back to roadmap](README.md)

## Constraints → target complexity

| n up to | Acceptable | Typical technique |
|---|---|---|
| 10–12 | O(n!) | permutations / backtracking |
| 20–25 | O(2^n · n) | bitmask, meet-in-the-middle (≤ 40) |
| 100–500 | O(n^3) | Floyd-Warshall, interval DP |
| 5 000 | O(n^2) | 2D DP, all pairs |
| 2·10^5 – 10^6 | O(n log n) | sort, binary search, heap, segment tree |
| 10^7 – 10^8 | O(n) | two pointers, prefix sums, sieve |
| 10^18 | O(log n) / O(1) | math, binary exponentiation, matrix power |

## "If the problem says … think …"

| Signal in the statement | Pattern | Folder |
|---|---|---|
| contiguous subarray/substring, longest/shortest with a condition | sliding window | `two_pointers_sliding_window/` |
| sorted array, pair/triple with target sum | two pointers | `two_pointers_sliding_window/` |
| subarray sum = k (negatives allowed), count subarrays | prefix sum + hash map | `hashing/`, `prefix_sum_difference/` |
| many range sums, no updates | prefix sums | `prefix_sum_difference/` |
| many "add v on [l, r]" | difference array | `prefix_sum_difference/` |
| range queries **with** updates | Fenwick / segment tree | `range_queries/` |
| minimise the maximum / maximise the minimum | binary search on answer | `binary_search/` |
| next greater / previous smaller / histogram | monotonic stack | `monotonic_stack_queue/` |
| sliding window max/min | monotonic deque | `monotonic_stack_queue/` |
| top k, k-th largest, merge k sorted | heap | `heaps/` |
| intervals: merge, overlap, max simultaneous | sort + sweep | `intervals_sweep_line/` |
| choose max non-overlapping, schedule | greedy by end time | `greedy/` |
| all subsets / permutations / combinations | backtracking or bitmask | `backtracking/`, `bit_manipulation/` |
| XOR, pairs cancel, AND/OR maximise | bit tricks, per-bit reasoning | `bit_manipulation/` |
| count ways / min cost with overlapping choices | DP | `dynamic_programming/` |
| two strings: common / edit | 2D string DP | `dynamic_programming/` |
| grid, shortest steps, unweighted | BFS | `graphs/` |
| weighted shortest path ≥ 0 | Dijkstra | `graphs/` |
| negative weights / negative cycle | Bellman-Ford | `graphs/` |
| dependencies, ordering | topological sort | `graphs/` |
| connect everything with min cost | MST (Kruskal + DSU) | `graphs/`, `dsu/` |
| "are x and y connected" with edges added | DSU | `dsu/` |
| ancestors, distance in tree | LCA / binary lifting | `trees/` |
| prefix of words, autocomplete | trie | `trees/` |
| find pattern in text, borders, periods | KMP / Z-function / hashing | `strings/` |
| answer mod 1e9+7, nCr | modpow, inverse factorials | `number_theory/` |
| primes / divisors up to 1e7 | sieve | `number_theory/` |
| linear recurrence with huge n | matrix exponentiation | `matrix_2d/` |
| left/right turn, intersections | cross product | `geometry/` |

## Templates at a glance

```cpp
// lower_bound style binary search on answer
long long lo = L, hi = R;
while (lo < hi) { long long mid = lo + (hi - lo) / 2; if (ok(mid)) hi = mid; else lo = mid + 1; }

// variable sliding window
for (int l = 0, r = 0; r < n; ++r) { add(r); while (bad()) remove(l++); best = std::max(best, r - l + 1); }

// monotonic stack: previous smaller
for (int i = 0; i < n; ++i) { while (!st.empty() && a[st.back()] >= a[i]) st.pop_back(); prv[i] = st.empty() ? -1 : st.back(); st.push_back(i); }

// BFS
std::queue<int> q; q.push(s); dist[s] = 0;
while (!q.empty()) { int u = q.front(); q.pop(); for (int v : adj[u]) if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); } }

// fast power mod
long long pw(long long b, long long e, long long m) { long long r = 1; b %= m; while (e) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
```

## Debug checklist before submitting

- `long long` for sums/products? Overflow in `mid`, `a * b`, `INF + w`?
- Off-by-one on inclusive/exclusive ranges and 0/1 indexing?
- Empty input, n = 1, all equal, all negative, duplicates?
- Multiple test cases: did you reset global arrays?
- Fast IO: `std::ios::sync_with_stdio(false); std::cin.tie(nullptr);`
