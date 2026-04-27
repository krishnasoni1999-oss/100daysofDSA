#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Delete first occurrence of key
struct node* deleteKey(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
        return head;

    // Unlink and delete node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}