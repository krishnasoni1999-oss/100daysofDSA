#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluate(char* s) {
    int num = 0;
    char op = '+';

    for (int i = 0; s[i] != '\0'; i++) {

        // Build number
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // If operator or end
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {

            if (op == '+') push(num);
            else if (op == '-') push(-num);
            else if (op == '*') push(pop() * num);
            else if (op == '/') push(pop() / num);

            op = s[i];
            num = 0;
        }
    }

    // Sum all values in stack
    int result = 0;
    while (top != -1) {
        result += pop();
    }

    return result;
}