#include <stdio.h>

int main() {
    int a[] = {1,2,2,1};
    int b[] = {2,2};
    int n1 = 4, n2 = 2;

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(a[i] == b[j]) {
                printf("%d ", a[i]);
                b[j] = -1; 
                break;
            }
        }
    }
    return 0;
}