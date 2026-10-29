// Tree diameter (general tree, two BFS) and Binary Tree Maximum Path Sum.
//
// Problems:
//   (1) Longest path (edges) in an unweighted tree.
//       Links: https://cses.fi/problemset/task/1131  https://leetcode.com/problems/diameter-of-binary-tree/
//   (2) Maximum sum of any path in a binary tree (values may be negative).
//       Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
//
// Idea:
//   (1) BFS from any node -> farthest node a; BFS from a -> farthest distance
//       is the diameter.
//   (2) Post-order: gain(v) = v + max(0, gain(left), gain(right)) is the best
//       downward path; answer considers v + left gain + right gain at each node.
//
// Time: O(n)    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra tree_diameter_and_max_path_sum.cpp -o diam && ./diam

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// returns {farthest node, its distance} from src
std::pair<int, int> bfsFar(const std::vector<std::vector<int>>& g, int src) {
    std::vector<int> d(g.size(), -1);
    std::queue<int> q; q.push(src); d[src] = 0;
    int best = src;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (d[v] > d[best]) best = v;
        for (int u : g[v]) if (d[u] == -1) { d[u] = d[v] + 1; q.push(u); }
    }
    return {best, d[best]};
}

int diameter(const std::vector<std::vector<int>>& g) {
    int a = bfsFar(g, 0).first;          // one end of a diameter
    return bfsFar(g, a).second;          // farthest from it = diameter length
}

struct Node { int val; Node* left; Node* right; };

int gain(Node* v, int& best) {
    if (!v) return 0;
    int l = std::max(0, gain(v->left, best));    // drop negative branches
    int r = std::max(0, gain(v->right, best));
    best = std::max(best, v->val + l + r);       // path bending at v
    return v->val + std::max(l, r);              // only one side may continue upward
}

int main() {
    // CSES 1131 sample: edges 1-2 1-3 3-4 3-5 -> diameter 3
    std::vector<std::vector<int>> g(5);
    auto add = [&](int a, int b) { g[a].push_back(b); g[b].push_back(a); };
    add(0, 1); add(0, 2); add(2, 3); add(2, 4);
    assert(diameter(g) == 3);

    // [-10, 9, 20, null, null, 15, 7] -> 42 (15 + 20 + 7)
    Node n15{15, nullptr, nullptr}, n7{7, nullptr, nullptr};
    Node n20{20, &n15, &n7}, n9{9, nullptr, nullptr};
    Node root{-10, &n9, &n20};
    int best = INT_MIN;
    gain(&root, best);
    assert(best == 42);
    std::cout << "tree_diameter_and_max_path_sum: all tests passed\n";
    return 0;
}
