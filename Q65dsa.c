#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node
struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push
void push(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop
int pop() {
    if (top == NULL) {
        printf("Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char to int
        }

        // If operator
        else {
            int b = pop();
            int a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    return pop();
}