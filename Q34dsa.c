#include <stdio.h>
#include <stdlib.h>

// Function for qsort
int compare(const void *a, const void *b) {
    return ((int)a - (int)b);
}

void findClosestToZero(int arr[], int n) {

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = arr[left] + arr[right];
    int minL = left, minR = right;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            minL = left;
            minR = right;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Pair: %d and %d\n", arr[minL], arr[minR]);
    printf("Closest Sum = %d\n", minSum);
}

int main() {
    int arr[] = {-8, -3, 1, 2, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    findClosestToZero(arr, n);

    return 0;
}