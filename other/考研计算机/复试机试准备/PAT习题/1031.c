/*
* 1031题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8 ,4, 2};
char check[] = {'1', '0', 'X', '9', '8', '7' ,'6' ,'5', '4', '3', '2'};

//检查校验位函数
int valueCheck(char n[], const int len) {
    char flag;
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        sum += weight[i] * (n[i] - '0');
    }
    sum = sum % 11;
    flag = check[sum];
    if (flag == n[len - 1])
        return 1;
    else 
        return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char str[19];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        if ( valueCheck(str, 18) == 0) {
            printf("%s\n", str);
            cnt++;
        }
    }
    if (cnt == 0)
        printf("All passed\n");
    return 0;
}