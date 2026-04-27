#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;
int size = 0;

// Get value at index
int get(int index) {
    if (index < 0 || index >= size) return -1;

    struct Node* temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

// Add at head
void addAtHead(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    size++;
}

// Add at tail
void addAtTail(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

// Add at index
void addAtIndex(int index, int val) {
    if (index < 0 || index > size) return;

    if (index == 0) {
        addAtHead(val);
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = temp->next;
    temp->next = newNode;

    size++;
}

// Delete at index
void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;

    struct Node* temp = head;

    if (index == 0) {
        head = temp->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    size--;
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}