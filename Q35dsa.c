#include <stdio.h>

// Kadane for max sum
int kadaneMax(int arr[], int n) {
    int maxSum = arr[0];
    int curr = 0;

    for(int i = 0; i < n; i++) {
        curr += arr[i];
        if(curr > maxSum)
            maxSum = curr;
        if(curr < 0)
            curr = 0;
    }
    return maxSum;
}

// Kadane for min sum
int kadaneMin(int arr[], int n) {
    int minSum = arr[0];
    int curr = 0;

    for(int i = 0; i < n; i++) {
        curr += arr[i];
        if(curr < minSum)
            minSum = curr;
        if(curr > 0)
            curr = 0;
    }
    return minSum;
}

int maxCircularSubarraySum(int arr[], int n) {
    int maxNormal = kadaneMax(arr, n);

    // If all numbers are negative
    if(maxNormal < 0)
        return maxNormal;

    int total = 0;
    for(int i = 0; i < n; i++)
        total += arr[i];

    int minSub = kadaneMin(arr, n);

    int maxCircular = total - minSub;

    return (maxNormal > maxCircular) ? maxNormal : maxCircular;
}

int main() {
    int nums[] = {5, -3, 5};
    int n = 3;

    int result = maxCircularSubarraySum(nums, n);

    printf("Maximum Circular Subarray Sum = %d\n", result);

    return 0;
}