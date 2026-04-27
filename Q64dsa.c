#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// Evaluate RPN
int evalRPN(char* tokens[], int n) {
    for (int i = 0; i < n; i++) {

        // If operator
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = pop();
            int a = pop();

            if (strcmp(tokens[i], "+") == 0)
                push(a + b);
            else if (strcmp(tokens[i], "-") == 0)
                push(a - b);
            else if (strcmp(tokens[i], "*") == 0)
                push(a * b);
            else
                push(a / b);
        }
        else {
            // Operand
            push(atoi(tokens[i]));
        }
    }

    return pop();
}