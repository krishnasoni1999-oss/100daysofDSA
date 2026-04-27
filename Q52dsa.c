#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int removeCycle(struct node* head) {
    struct node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No cycle
    if (fast == NULL || fast->next == NULL)
        return 0;

    // Step 2: Find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Find last node of cycle
    struct node* temp = slow;
    while (temp->next != slow)
        temp = temp->next;

    // Break the cycle
    temp->next = NULL;

    return 1;
}