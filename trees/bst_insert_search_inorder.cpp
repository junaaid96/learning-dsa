// Basic Binary Search Tree (BST): insert, search, and inorder traversal.
//
// Properties:
//   For any node:
//     - all values in left subtree  < node->value
//     - all values in right subtree > node->value
//
// Inorder traversal of a BST yields values in sorted order.
//
// Compile: g++ -std=c++17 -O2 bst_insert_search_inorder.cpp -o bst_demo
// Run:     ./bst_demo

#include <iostream>
#include <vector>

struct TreeNode {
    int value{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    explicit TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        // Duplicate value: ignore in this demo.
    }
    return root;
}

bool searchNode(const TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }
    if (target == root->value) {
        return true;
    }
    if (target < root->value) {
        return searchNode(root->left, target);
    }
    return searchNode(root->right, target);
}

void inorderTraversal(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->value << ' ';
    inorderTraversal(root->right);
}

void freeTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;
    const std::vector<int> values{5, 3, 7, 2, 4, 6, 8};

    for (int v : values) {
        root = insertNode(root, v);
    }

    std::cout << "BST inorder traversal (should be sorted): ";
    inorderTraversal(root);
    std::cout << "\n";

    const std::vector<int> queries{4, 10};
    for (int q : queries) {
        std::cout << "Search " << q << ": "
                  << (searchNode(root, q) ? "found" : "not found") << "\n";
    }

    freeTree(root);
    return 0;
}

