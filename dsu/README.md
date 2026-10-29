# Disjoint Set Union (Union-Find)

[← back to roadmap](../README.md)

## What it is

Maintains a partition of elements with near-O(1) `find` and `unite` using path compression + union by size.

## When to use it

- Dynamic connectivity (edges only added)
- Kruskal MST
- Detect the edge that creates a cycle
- Grouping by equivalence (accounts merge)

## Intuition

Each set is a tree; its root is the representative. Compress paths so trees stay flat.

## Common patterns

- Count components
- Redundant edge
- Kruskal
- DSU with extra data (size, sum)

## Template

```cpp
struct DSU {
    std::vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) { a = find(a); b = find(b); if (a == b) return false;
        if (sz[a] < sz[b]) std::swap(a, b); p[b] = a; sz[a] += sz[b]; return true; }
};
```

## Pitfalls

- Comparing x instead of find(x)
- Cannot delete edges (offline reverse trick)
- 1-indexed vs 0-indexed nodes

## Complexity

O(α(n)) amortised per op.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`dsu_template_and_components.cpp`](dsu_template_and_components.cpp) | Disjoint Set Union (Union-Find) with path compression + union by size. | [link](https://leetcode.com/problems/number-of-provinces/) |
| [`redundant_connection_and_accounts.cpp`](redundant_connection_and_accounts.cpp) | DSU applications: Redundant Connection and Accounts Merge. | [link](https://leetcode.com/problems/redundant-connection/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh dsu` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Number Of Provinces](https://leetcode.com/problems/number-of-provinces/)
- [ ] [Find If Path Exists In Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)

**Medium**

- [ ] [Redundant Connection](https://leetcode.com/problems/redundant-connection/)
- [ ] [Accounts Merge](https://leetcode.com/problems/accounts-merge/)
- [ ] [CSES 1676 – Road Construction](https://cses.fi/problemset/task/1676)
- [ ] [CF 25D – Roads not only in Berland](https://codeforces.com/problemset/problem/25/D)

**Hard**

- [ ] [Number Of Islands Ii](https://leetcode.com/problems/number-of-islands-ii/)
- [ ] [CSES 1675 – Road Reparation](https://cses.fi/problemset/task/1675)
