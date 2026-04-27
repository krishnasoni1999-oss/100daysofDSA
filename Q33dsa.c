#include <stdio.h>

void productExceptSelf(int nums[], int n, int answer[]) {
    int prefix = 1;


    for(int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    for(int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = 4;
    int answer[n];

    productExceptSelf(nums, n, answer);

    printf("Result: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}