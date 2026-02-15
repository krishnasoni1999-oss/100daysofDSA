#include <stdio.h>

int main() {
    int n = 16;

    if(n > 0 && (n & (n-1)) == 0)
        printf("True");
    else
        printf("False");

    return 0;
}