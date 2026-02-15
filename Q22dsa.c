#include <stdio.h>

int main() {
    int A[3][3] = {{1,2,3},{4,1,2},{5,4,1}};
    int flag = 1;

    for(int i = 1; i < 3; i++)
        for(int j = 1; j < 3; j++)
            if(A[i][j] != A[i-1][j-1])
                flag = 0;

    if(flag) printf("Toeplitz");
    else printf("Not Toeplitz");

    return 0;
}