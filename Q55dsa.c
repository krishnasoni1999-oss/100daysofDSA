#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* rotateRight(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct node* temp = head;
    int n = 1;

    // Step 1: Find length
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: Make circular
    temp->next = head;

    // Step 3: Optimize k
    k = k % n;

    // Step 4: Find new tail
    int steps = n - k;
    struct node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Step 5: Set new head
    struct node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}