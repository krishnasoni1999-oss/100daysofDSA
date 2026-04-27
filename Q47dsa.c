#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Count occurrences of key
int countOccurrences(struct node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }

    return count;
}