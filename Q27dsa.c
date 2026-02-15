#include <stdio.h>

int main() {
    int A[3][3] = {{1,2,3},{4,0,6},{7,8,9}};
    int rows[3]={0}, cols[3]={0};

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(A[i][j]==0){
                rows[i]=1;
                cols[j]=1;
            }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(rows[i] || cols[j])
                A[i][j]=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

    return 0;
}