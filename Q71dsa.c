#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// Insert (enqueue)
void insert(int val) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    // Shift elements to maintain sorted order
    while (i >= 0 && pq[i] > val) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = val;
    size++;
}

// Delete (remove highest priority = smallest)
int delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    return pq[--size]; // smallest is at front → but here we used reverse logic
}

// Display
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}