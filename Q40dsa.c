#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Helper to create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create list: 10 -> 20 -> 30
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    int result = countNodes(head);

    printf("Total nodes = %d\n", result);

    return 0;
}