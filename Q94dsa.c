#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to check if node is leaf
int isLeaf(struct TreeNode* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Function to compute sum of left leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check left child
    if (isLeaf(root->left))
        sum += root->left->val;

    // Recur for subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Driver code
int main() {
    /*
            3
           / \
          9   20
             /  \
            15   7
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Sum of Left Leaves: %d\n", sumOfLeftLeaves(root));

    return 0;
}