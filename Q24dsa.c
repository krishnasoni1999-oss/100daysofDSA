#include <stdio.h>

int main() {
    int A[2][2] = {{1,0},{0,1}};
    int flag = 1;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if((i==j && A[i][j]!=1) || (i!=j && A[i][j]!=0))
                flag = 0;

    if(flag) printf("Identity");
    else printf("Not Identity");

    return 0;
}