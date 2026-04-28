#include <stdio.h>
#include <stdlib.h>

// BST Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both values are greater → go right
    if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise, this is the split point → LCA
    return root;
}

// Driver code
int main() {
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */

    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    int p = 2, q = 8;

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", p, q, lca->val);

    return 0;
}