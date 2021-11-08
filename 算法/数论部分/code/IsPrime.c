#include <stdio.h>

int IsPrime(int num) {
    if (num < 2)
        return 0;
    if (num == 2)
        return 1;
    
    int tmp = 1;
    while (tmp * tmp < num) 
        tmp++;

    printf("%d\n", tmp);
    for (int i = 2; i <= tmp; i++)
    {
        printf("i = %d\n", i);
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int main() {
    int num;
    puts("请输入一个正整数：");

    scanf("%d", &num);
    if (IsPrime(num))
        puts("是素数！");
    else
        puts("不是素数！");
    return 0;
}