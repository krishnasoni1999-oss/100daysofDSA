#include <stdio.h>

int main() {
    int nums[100], n, val;
    int i, k = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);


    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter value to remove: ");
    scanf("%d", &val);

    for (i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }


    printf("Number of elements not equal to %d: %d\n", val, k);

    printf("Updated array:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}