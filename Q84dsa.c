#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);   // Left
    printf("%d ", root->data); // Root
    inorder(root->right);  // Right
}

// Driver code
int main() {
    /*
            1
           / \
          2   3
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}