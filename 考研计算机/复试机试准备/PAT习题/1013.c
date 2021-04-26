/*
* 1013题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int m,n;
    scanf("%d%d", &m, &n);

    int num = 2;
    int flag = 1;
    int cnt = 0;
    while (num)
    {
        if (isPrime(num)) {
            cnt++;
            if (cnt >= m) {
                if (flag % 10 == 1)
                    printf("%d", num);
                else if (flag % 10 == 0)
                    printf(" %d\n", num);
                else 
                    printf(" %d", num);
                flag++;
            }
            if (cnt >= n)
                break;
        }
        num++;
    }
    return 0;
}