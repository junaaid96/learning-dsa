// LCA with binary lifting (+ k-th ancestor, distance between nodes).
//
// Problem:
//   Many queries on a rooted tree: lowest common ancestor of a and b.
// Links: https://cses.fi/problemset/task/1688  (Company Queries II)
//        https://cses.fi/problemset/task/1687  (Company Queries I, k-th boss)
//        https://cses.fi/problemset/task/1135  (Distance Queries)
//
// Idea:
//   up[j][v] = 2^j-th ancestor of v. Lift the deeper node to equal depth, then
//   lift both together by decreasing powers while their ancestors differ.
//
// Time: O(n log n) build, O(log n) per query    Space: O(n log n)
//
// Compile: g++ -std=c++17 -Wall -Wextra tree_lca_binary_lifting.cpp -o lift && ./lift

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

struct LCA {
    int LOG = 1;
    std::vector<std::vector<int>> up;
    std::vector<int> depth;
    LCA(const std::vector<std::vector<int>>& g, int root) : depth(g.size(), 0) {
        const int n = static_cast<int>(g.size());
        while ((1 << LOG) < n) ++LOG;
        up.assign(LOG, std::vector<int>(n, root));
        std::vector<int> st{root};                    // iterative DFS sets parent + depth
        std::vector<bool> seen(n, false); seen[root] = true;
        while (!st.empty()) {
            int v = st.back(); st.pop_back();
            for (int u : g[v]) if (!seen[u]) {
                seen[u] = true; up[0][u] = v; depth[u] = depth[v] + 1; st.push_back(u);
            }
        }
        for (int j = 1; j < LOG; ++j)
            for (int v = 0; v < n; ++v) up[j][v] = up[j - 1][up[j - 1][v]];  // 2^j = 2^(j-1) twice
    }
    int kth(int v, int k) const {                     // k-th ancestor, -1 if none
        if (k > depth[v]) return -1;
        for (int j = 0; j < LOG; ++j) if (k >> j & 1) v = up[j][v];
        return v;
    }
    int lca(int a, int b) const {
        if (depth[a] < depth[b]) std::swap(a, b);
        a = kth(a, depth[a] - depth[b]);              // same depth now
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][a] != up[j][b]) { a = up[j][a]; b = up[j][b]; }
        return up[0][a];                              // parents are equal now
    }
    int dist(int a, int b) const { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};

int main() {
    // CSES 1688 sample: bosses of 2..5 are 1 1 3 3 (0-indexed below)
    std::vector<std::vector<int>> g(5);
    auto add = [&](int a, int b) { g[a].push_back(b); g[b].push_back(a); };
    add(0, 1); add(0, 2); add(2, 3); add(2, 4);
    LCA t(g, 0);
    assert(t.lca(3, 4) == 2);
    assert(t.lca(1, 4) == 0);
    assert(t.lca(2, 4) == 2);
    assert(t.kth(4, 2) == 0 && t.kth(4, 3) == -1);
    assert(t.dist(1, 3) == 3);
    std::cout << "tree_lca_binary_lifting: all tests passed\n";
    return 0;
}
