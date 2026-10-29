# Trees, BSTs & Tries

[← back to roadmap](../README.md)

## What it is

Hierarchical data; most solutions are a DFS returning information from children to parent.

## When to use it

- Hierarchies, recursive structure
- Ordered sets (BST)
- Prefix queries on strings (trie)
- Ancestor queries (LCA)

## Intuition

Ask: "what does each subtree need to tell its parent?" — height, sum, validity range, best path.

## Common patterns

- Pre/in/post-order & level order
- Return-value DFS (diameter, max path sum)
- Pass bounds down (validate BST)
- Binary lifting for LCA / k-th ancestor
- Trie nodes with child arrays

## Template

```cpp
int height(Node* r) {
    if (!r) return 0;
    int L = height(r->left), R = height(r->right);
    best = std::max(best, L + R);  // diameter through r
    return 1 + std::max(L, R);
}
```

## Pitfalls

- Skewed trees → deep recursion
- BST validation must use ranges, not just parent
- Use long long bounds for INT_MIN/INT_MAX values

## Complexity

DFS O(n); binary lifting O(n log n) build, O(log n) query; trie O(L) per op.

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`bst_insert_search_inorder.cpp`](bst_insert_search_inorder.cpp) | Basic Binary Search Tree (BST): insert, search, and inorder traversal. | — |
| [`tree_diameter_and_max_path_sum.cpp`](tree_diameter_and_max_path_sum.cpp) | Tree diameter (general tree, two BFS) and Binary Tree Maximum Path Sum. | [link](https://cses.fi/problemset/task/1131) |
| [`tree_lca_binary_lifting.cpp`](tree_lca_binary_lifting.cpp) | LCA with binary lifting (+ k-th ancestor, distance between nodes). | [link](https://cses.fi/problemset/task/1688) |
| [`tree_lca_binary_tree.cpp`](tree_lca_binary_tree.cpp) | Lowest Common Ancestor (LCA) in a binary tree (not necessarily BST). | — |
| [`tree_traversals_basic.cpp`](tree_traversals_basic.cpp) | Basic binary tree traversals: preorder, inorder, postorder, and level order. | — |
| [`tree_validate_bst_and_views.cpp`](tree_validate_bst_and_views.cpp) | Validate BST, level-order traversal, right side view, max depth. | [link](https://leetcode.com/problems/validate-binary-search-tree/) |
| [`trie_prefix_tree.cpp`](trie_prefix_tree.cpp) | Trie (prefix tree) + maximum XOR of two numbers (binary trie). | [link](https://leetcode.com/problems/implement-trie-prefix-tree/) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh trees` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [Maximum Depth Of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [ ] [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
- [ ] [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

**Medium**

- [ ] [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [ ] [Lowest Common Ancestor Of A Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [ ] [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [ ] [Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [ ] [Diameter Of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

**Hard**

- [ ] [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
- [ ] [CSES 1688 – Company Queries II](https://cses.fi/problemset/task/1688)
- [ ] [Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
