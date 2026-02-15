#include <stdio.h>

int main() {
    int arr[] = {0,1,0,3,12};
    int n = 5;

    int i = 0;
    for(int j = 0; j < n; j++) {
        if(arr[j] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    for(int k = 0; k < n; k++)
        printf("%d ", arr[k]);

    return 0;
}