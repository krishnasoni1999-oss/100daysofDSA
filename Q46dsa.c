#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* removeElements(struct node* head, int val) {
    struct node* temp;

    // Remove matching nodes from beginning
    while (head != NULL && head->data == val) {
        temp = head;
        head = head->next;
        free(temp);
    }

    struct node* current = head;

    // Traverse rest of list
    while (current != NULL && current->next != NULL) {
        if (current->next->data == val) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}