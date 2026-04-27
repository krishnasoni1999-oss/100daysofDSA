#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int n, int* returnSize) {
    int* result = (int*)calloc(n, sizeof(int)); // initialized to 0
    int* stack = (int*)malloc(n * sizeof(int)); // stack to store indices
    int top = -1;

    for (int i = 0; i < n; i++) {
        // Check if current temp is higher than stack top
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        // Push current index
        stack[++top] = i;
    }

    free(stack);
    *returnSize = n;
    return result;
}

// Driver code
int main() {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temps) / sizeof(temps[0]);
    int returnSize;

    int* ans = dailyTemperatures(temps, n, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);
    return 0;
}