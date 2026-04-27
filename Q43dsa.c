#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Merge function
struct node* merge(struct node* a, struct node* b) {
    struct node *result = NULL, *temp;

    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

// Print list
void display(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}