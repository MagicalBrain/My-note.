/*
* 1016题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char A[11];
    char B[11];
    char m, n;
    int j, len1 = 1, len2 = 1, a = 0, b = 0;
    scanf("%s %c %s %c",A, &m, B, &n);
    
    j = 0;
    while (A[j] != '\0') {
        if (A[j] == m) {
            a += len1 * (m - '0');
            len1 *= 10;
        }
        j++;
    }

    j = 0;
    while (B[j] != '\0') {
        if (B[j] == n) {
            b += len2 * (n - '0');
            len2 *= 10;
        }
        j++;
    }

    printf("%d\n", a + b);
    return 0;
}