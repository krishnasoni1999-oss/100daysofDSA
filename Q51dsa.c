#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* getIntersectionNode(struct node* head1, struct node* head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;

    struct node* p1 = head1;
    struct node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1; // intersection node or NULL
}