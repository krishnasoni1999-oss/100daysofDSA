#include <stdio.h>

int main() {
    int A[2][2] = {{1,2},{2,1}};
    int flag = 1;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(A[i][j] != A[j][i])
                flag = 0;

    if(flag) printf("Symmetric");
    else printf("Not Symmetric");

    return 0;
}
