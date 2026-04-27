#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

// Push to stack1
void push(int x) {
    s1[++top1] = x;
}

// Transfer elements
void transfer() {
    while (top1 != -1) {
        s2[++top2] = s1[top1--];
    }
}

// Pop (dequeue)
int pop() {
    if (top2 == -1)
        transfer();

    if (top2 == -1) {
        printf("Queue Empty\n");
        return -1;
    }

    return s2[top2--];
}

// Peek
int peek() {
    if (top2 == -1)
        transfer();

    if (top2 == -1)
        return -1;

    return s2[top2];
}

// Check empty
int empty() {
    return (top1 == -1 && top2 == -1);
}