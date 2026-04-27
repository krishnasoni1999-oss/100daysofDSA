#include <stdio.h>

#define MAX 1000  

int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0;
    int count = 0;

    int freq[MAX] = {0};

    // To handle prefix sum = 0 case
    freq[0] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum >= 0 && prefixSum < MAX) {
            count += freq[prefixSum];
            freq[prefixSum]++;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = 5;

    int result = countZeroSumSubarrays(arr, n);

    printf("Count = %d\n", result);

    return 0;
}