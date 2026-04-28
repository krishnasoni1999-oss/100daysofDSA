#include <stdio.h>
#include <stdlib.h>

// Definition for BST node
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

// Search and return subtree
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// Inorder traversal (for verification)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Driver code
int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
    */

    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int val = 2;

    struct TreeNode* result = searchBST(root, val);

    if (result != NULL) {
        printf("Subtree rooted at %d (Inorder): ", val);
        inorder(result);
    } else {
        printf("Value not found in BST\n");
    }

    return 0;
}