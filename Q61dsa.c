#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
        printf("%d pushed into stack\n", val);
    }
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

// Display
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main (verification)
int main() {
    push(10);
    push(20);
    push(30);
    display();     // Expected: 30 20 10

    pop();
    display();     // Expected: 20 10

    pop();
    pop();
    pop();         // Underflow check

    return 0;
}