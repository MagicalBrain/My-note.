/*
* 求最大公约数 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}