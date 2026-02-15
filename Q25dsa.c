#include <stdio.h>

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 3;

    // Transpose
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }

    // Reverse each row
    for(int i=0;i<n;i++)
        for(int j=0;j<n/2;j++) {
            int temp = A[i][j];
            A[i][j] = A[i][n-1-j];
            A[i][n-1-j] = temp;
        }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    return 0;
}