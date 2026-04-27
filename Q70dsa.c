#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1, size = MAX;

// Check full
int isFull() {
    return ((front == 0 && rear == size - 1) ||
            (front == rear + 1));
}

// Check empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int x) {
    if (isFull()) {
        printf("Deque Full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }

    deque[front] = x;
}

// Insert at rear
void insertLast(int x) {
    if (isFull()) {
        printf("Deque Full\n");
        return;
    }

    if (rear == -1) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// Delete front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete rear
void deleteLast() {
    if (isEmpty()) {
        printf("Deque Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

// Get front
int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

// Get rear
int getRear() {
    if (isEmpty()) return -1;
    return deque[rear];
}