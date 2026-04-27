#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isValid(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // Closing brackets
        else {
            char topChar = pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; // false
            }
        }
    }

    return (top == -1); // valid if stack empty
}