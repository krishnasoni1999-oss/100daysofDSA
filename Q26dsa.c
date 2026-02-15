#include <stdio.h>

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum = 0;

    for(int i=0;i<3;i++)
        sum += A[i][i];

    printf("%d", sum);
    return 0;
}