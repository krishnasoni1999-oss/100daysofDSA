#include <stdio.h>

// Simple sort (Bubble Sort for clarity)
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double findMedian(int arr[], int n) {
    sort(arr, n);

    if (n % 2 != 0) {
        return arr[n / 2];
    } else {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    }
}

int main() {
    int arr[] = {3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Median = %.2f\n", findMedian(arr, n));
    return 0;
}