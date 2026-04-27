#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Merge two sorted lists (simple version)
struct Node* merge(struct Node* l1, struct Node* l2) {
    // If one list is empty
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    // Pick smaller node
    if(l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Helper to create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    // List1: 1->3->5
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    // List2: 2->4->6
    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    struct Node* result = merge(l1, l2);

    printList(result);

    return 0;
}