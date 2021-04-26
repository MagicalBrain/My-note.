/*
* 1017题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char A[1001];
    int b;
    int *num;
    int i = 0, len, Q = 0, R = 0;

    scanf("%s%d", A, &b);
    len = strlen(A);
    num = (int*) malloc(len * sizeof(int));
    memset(num, 0, len * sizeof(int));

    for (int i = 0; i < len; i++)
    {
        if (i == 0) {
            int t = A[i] - '0';
            if (t - b >= 0) {
                num[i] = t / b;
                R = t % b;
            }
            else 
                R = t;
            continue;
        }

        int tmp = R * 10 + A[i] - '0';
        num[i] = tmp / b;
        R = tmp % b;
    }
    //输出商
    for (int i = 0; i < len; i++)
    {
        if (len == 1 && i == 0)
            printf("%d", num[i]);
        else if (i == 0 && num[i] == 0)
            continue;
        else if (i == 0)
            printf("%d",num[i]);
        else
            printf("%d",num[i]);
    }
    printf(" %d\n", R);
    return 0;
}