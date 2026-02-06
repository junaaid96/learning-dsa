// Basic binary tree traversals: preorder, inorder, postorder, and level order.
//
// Compile: g++ -std=c++17 -O2 tree_traversals_basic.cpp -o tree_traversals
// Run:     ./tree_traversals

#include <iostream>
#include <queue>

struct TreeNode {
    int value{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    explicit TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

void preorder(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    std::cout << root->value << ' ';
    inorder(root->right);
}

void postorder(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->value << ' ';
}

void levelOrder(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const TreeNode* node = q.front();
        q.pop();
        std::cout << node->value << ' ';
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    // Build a simple tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    const TreeNode* root = &n1;

    std::cout << "Preorder:   ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Inorder:    ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Postorder:  ";
    postorder(root);
    std::cout << "\n";

    std::cout << "Level order:";
    std::cout << ' ';
    levelOrder(root);
    std::cout << "\n";

    return 0;
}

