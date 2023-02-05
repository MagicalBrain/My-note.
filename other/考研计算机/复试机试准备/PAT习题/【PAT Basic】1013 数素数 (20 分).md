# 【PAT Basic】1013 数素数 (20 分)

## 题目描述

令 $P_​$i表示第 $i$ 个素数。现任给两个正整数 $M \leqslant N \leqslant 10​^4$​​ ，请输出$ P_​M$​​  到 $P_​N$​​  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P​M​​  到 P​N​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

## 基本思路

## 代码

```c++
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
```

## 总结