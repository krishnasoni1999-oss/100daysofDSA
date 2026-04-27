#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Insert at end (circular)
struct node* insert(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct node* temp = head;

    // Go to last node
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Traverse circular linked list
void display(struct node* head) {
    if (head == NULL) return;

    struct node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}