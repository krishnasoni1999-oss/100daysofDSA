#include <stdio.h>

void rotate(int nums[], int n, int k) {
    int temp[n];

    k = k % n;

    for(int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }

    for(int i = k; i < n; i++) {
        temp[i] = nums[i - k];
    }

    for(int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    rotate(nums, n, k);

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}