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

// LCA function
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root; // split point
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

    struct TreeNode* p = root->left;        // 2
    struct TreeNode* q = root->right;       // 8

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca)
        printf("LCA: %d\n", lca->val);

    return 0;
}
