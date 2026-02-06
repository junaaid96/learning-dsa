// Lowest Common Ancestor (LCA) in a binary tree (not necessarily BST).
//
// Idea:
//   For nodes p and q:
//     - If current root is null -> return null.
//     - If root is p or q       -> return root.
//     - Recurse into left and right.
//     - If both sides return non-null, root is LCA.
//     - Otherwise return the non-null side.
//
// Compile: g++ -std=c++17 -O2 tree_lca_binary_tree.cpp -o tree_lca
// Run:     ./tree_lca

#include <iostream>

struct TreeNode {
    int value{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    explicit TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root;
    }
    return (left != nullptr) ? left : right;
}

int main() {
    // Build tree:
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode n3(3);
    TreeNode n5(5);
    TreeNode n1(1);
    TreeNode n6(6);
    TreeNode n2(2);
    TreeNode n0(0);
    TreeNode n8(8);
    TreeNode n7(7);
    TreeNode n4(4);

    n3.left = &n5;
    n3.right = &n1;
    n5.left = &n6;
    n5.right = &n2;
    n1.left = &n0;
    n1.right = &n8;
    n2.left = &n7;
    n2.right = &n4;

    TreeNode* root = &n3;

    TreeNode* p = &n5;
    TreeNode* q = &n1;
    TreeNode* lca1 = lowestCommonAncestor(root, p, q);
    std::cout << "LCA of " << p->value << " and " << q->value << " is "
              << (lca1 != nullptr ? lca1->value : -1) << "\n";

    p = &n6;
    q = &n4;
    TreeNode* lca2 = lowestCommonAncestor(root, p, q);
    std::cout << "LCA of " << p->value << " and " << q->value << " is "
              << (lca2 != nullptr ? lca2->value : -1) << "\n";

    return 0;
}

