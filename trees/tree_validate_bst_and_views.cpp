// Validate BST, level-order traversal, right side view, max depth.
//
// Links: https://leetcode.com/problems/validate-binary-search-tree/
//        https://leetcode.com/problems/binary-tree-level-order-traversal/
//        https://leetcode.com/problems/binary-tree-right-side-view/
//        https://leetcode.com/problems/maximum-depth-of-binary-tree/
//
// Idea:
//   Validate: every node must lie in an (low, high) window inherited from its
//   ancestors - checking only the direct children is the classic bug.
//   Level order: BFS processing queue.size() nodes per level.
//   Right view: last node of each level.
//
// Time: O(n)    Space: O(h) for DFS, O(width) for BFS
//
// Compile: g++ -std=c++17 -Wall -Wextra tree_validate_bst_and_views.cpp -o bst && ./bst

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct Node { int val; Node* left; Node* right; };

bool valid(Node* v, long long lo, long long hi) {
    if (!v) return true;
    if (v->val <= lo || v->val >= hi) return false;              // outside allowed window
    return valid(v->left, lo, v->val) && valid(v->right, v->val, hi);
}
bool isValidBST(Node* root) { return valid(root, LLONG_MIN, LLONG_MAX); }

std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> out;
    if (!root) return out;
    std::queue<Node*> q; q.push(root);
    while (!q.empty()) {
        out.emplace_back();
        for (int s = static_cast<int>(q.size()); s > 0; --s) {   // exactly one level
            Node* v = q.front(); q.pop();
            out.back().push_back(v->val);
            if (v->left) q.push(v->left);
            if (v->right) q.push(v->right);
        }
    }
    return out;
}

std::vector<int> rightSideView(Node* root) {
    std::vector<int> view;
    for (const auto& level : levelOrder(root)) view.push_back(level.back());
    return view;
}

int maxDepth(Node* v) { return v ? 1 + std::max(maxDepth(v->left), maxDepth(v->right)) : 0; }

int main() {
    Node a{1, nullptr, nullptr}, c{3, nullptr, nullptr};
    Node good{2, &a, &c};
    assert(isValidBST(&good));
    // [5,1,4,null,null,3,6] is NOT a BST (3 < 5 sits in the right subtree)
    Node n3{3, nullptr, nullptr}, n6{6, nullptr, nullptr}, n1{1, nullptr, nullptr};
    Node n4{4, &n3, &n6};
    Node bad{5, &n1, &n4};
    assert(!isValidBST(&bad));
    assert((levelOrder(&bad) == std::vector<std::vector<int>>{{5}, {1, 4}, {3, 6}}));
    assert((rightSideView(&bad) == std::vector<int>{5, 4, 6}));
    assert(maxDepth(&bad) == 3 && maxDepth(nullptr) == 0);
    std::cout << "tree_validate_bst_and_views: all tests passed\n";
    return 0;
}
