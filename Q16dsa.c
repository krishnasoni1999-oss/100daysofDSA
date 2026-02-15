#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "hello";
    int n = strlen(s);

    for(int i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }

    printf("%s", s);
    return 0;
}