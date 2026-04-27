#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Reverse list
struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Create node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add two numbers
struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct node *head = NULL, *tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        struct node* newNode = createNode(sum % 10);
        carry = sum / 10;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return reverse(head);
}