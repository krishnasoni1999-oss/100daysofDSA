#include <stdio.h>

#define MAX 1000

int* maxSlidingWindow(int nums[], int n, int k, int* returnSize) {
    static int result[MAX];
    int dq[MAX];  // stores indices
    int front = 0, rear = -1;

    *returnSize = 0;

    for (int i = 0; i < n; i++) {

        // Remove out-of-window indices
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements
        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        // Add current index
        dq[++rear] = i;

        // Store result
        if (i >= k - 1) {
            result[(*returnSize)++] = nums[dq[front]];
        }
    }

    return result;
}