#include <stdio.h>
#define MAX 100

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

// Push
void push(int x) {
    stack[++top] = x;

    if (minTop == -1 || x <= minStack[minTop]) {
        minStack[++minTop] = x;
    }
}

// Pop
void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    }

    if (stack[top] == minStack[minTop]) {
        minTop--;
    }
    top--;
}

// Top
int topElement() {
    if (top == -1) return -1;
    return stack[top];
}

// Get Min
int getMin() {
    if (minTop == -1) return -1;
    return minStack[minTop];
}