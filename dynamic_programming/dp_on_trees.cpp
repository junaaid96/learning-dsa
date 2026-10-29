// DP on trees: Maximum independent set / Tree Matching style + subtree sizes.
//
// Problems:
//   (1) House Robber III: max sum of chosen nodes with no parent-child pair.
//       Link: https://leetcode.com/problems/house-robber-iii/
//   (2) Subordinates: size of every subtree.  Link: https://cses.fi/problemset/task/1674
//
// Idea:
//   Root the tree. For each node compute values from its children after
//   visiting them (post-order).
//   (1) take[v] = val[v] + sum skip[child]; skip[v] = sum max(take, skip)[child].
//   (2) sub[v] = 1 + sum sub[child].
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra dp_on_trees.cpp -o treedp && ./treedp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using Graph = std::vector<std::vector<int>>;

std::pair<long long, long long> robDfs(int v, int parent, const Graph& g, const std::vector<int>& val) {
    long long take = val[v], skip = 0;
    for (int c : g[v]) {
        if (c == parent) continue;                      // do not go back up
        auto [ct, cs] = robDfs(c, v, g, val);
        take += cs;                                     // v taken -> child must be skipped
        skip += std::max(ct, cs);                       // v skipped -> child free
    }
    return {take, skip};
}

void sizeDfs(int v, int parent, const Graph& g, std::vector<int>& sub) {
    sub[v] = 1;                                         // the node itself
    for (int c : g[v]) if (c != parent) { sizeDfs(c, v, g, sub); sub[v] += sub[c]; }
}

int main() {
    // tree: 0-1, 0-2, 1-3, 2-4 with values 3,2,3,3,1 (LeetCode sample [3,2,3,null,3,null,1])
    Graph g(5);
    auto addEdge = [&](int a, int b) { g[a].push_back(b); g[b].push_back(a); };
    addEdge(0, 1); addEdge(0, 2); addEdge(1, 3); addEdge(2, 4);
    auto [t, s] = robDfs(0, -1, g, {3, 2, 3, 3, 1});
    assert(std::max(t, s) == 7);
    std::vector<int> sub(5);
    sizeDfs(0, -1, g, sub);
    assert((sub == std::vector<int>{5, 2, 2, 1, 1}));
    std::cout << "dp_on_trees: all tests passed\n";
    return 0;
}
