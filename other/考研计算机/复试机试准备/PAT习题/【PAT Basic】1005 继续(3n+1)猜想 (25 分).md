# 【PAT Basic】1005 继续(3n+1)猜想 (25 分)

## 题目描述

卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对 n=3 进行验证的时候，我们需要计算 3、5、8、4、2、1，则当我们对 n=5、8、4、2 进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这 4 个数已经在验证3的时候遇到过了，我们称 5、8、4、2 是被 3“覆盖”的数。我们称一个数列中的某个数 n 为“关键数”，如果 n 不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：

每个测试输入包含 1 个测试用例，第 1 行给出一个正整数 K (<100)，第 2 行给出 K 个互不相同的待验证的正整数 n (1<n≤100)的值，数字间用空格隔开。

输出格式：

每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用 1 个空格隔开，但一行中最后一个数字后没有空格。

输入样例：

6
3 5 6 7 8 11

输出样例：

7 6

## 基本思路

## 代码

### 自己的代码

```c++
/*
* 1005题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int hash[101];
    memset(hash, 0, 101 * sizeof(int));
    int key[101];
    memset(key, 0, 101 * sizeof(int));
    int max = 0, min = 101;

    int *num;
    int len;
    scanf("%d", &len);
    num = (int*) malloc(len * sizeof(int));
    
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
        
        key[num[i]]++;

        int t = num[i];
        while (t != 1 )
        {
            if (t % 2 == 0)
                t /= 2;
            else 
                t = (3 * t + 1) / 2;
            if (t <= 100)
                hash[t] += 1;
        }        
    }

    int first = 1;
    for (int i = max; i >= min; i--)
    {
        if (hash[i] == 0 && key[i] == 1 && first == 1) {
            printf("%d", i);
            first = 0;
        }
        else if (hash[i] == 0 && key[i] == 1)
            printf(" %d",i);
    } 
    printf("\n");
    
    return 0;
}
```

### 别人的代码

```c++
// PAT BasicLevel 1005
// https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
#include <iostream>
#include <algorithm>
using namespace std;

#define N 310        // 数组大小
bool isKey[N];       // N个数字是否为关键数：isKey[i]==true，则i是关键数；否则i不是关键数
bool isValid[N];     // N个数字是否被用户输入：isValid[i]==true，则i已被用户输入；否则i未被用户输入
void callatz(int n); // 循环处理isKey[n]：n若被覆盖，则不必往下计算，函数结束；若n未被覆盖，则覆盖n并按规则更新n。循环以上过程

int main()
{
    // 默认N个数字都未被覆盖，即N个数字是关键数
    fill(isKey, isKey + N, true);

    // 记录k个正整数n；对于每个正整数n，调用callatz()函数（用户输入的正整数n，并不会被自己覆盖，所以传参时直接将n更新）
    int k, n;
    scanf("%d", &k); // k个整数
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &n);
        isValid[n] = true; // 记录用户输入的正整数n
        callatz(n % 2 == 0 ? n / 2 : (3 * n + 1) / 2);
    }

    // 输出结果
    bool isFirstKey = true;
    for (int i = N - 1; i >= 0; --i)
    {
        if (isValid[i] && isKey[i])
        {
            if (isFirstKey)
            {
                printf("%d", i);
                isFirstKey = false; // 输出第一个关键数后，之后输出的关键数就不是第一个关键数了
            }
            else
            {
                printf(" %d", i);
            }
        }
    }

    system("pause");
    return 0;
}

void callatz(int n)
{
    while (n != 1)
    {
        // n未被覆盖
        if (isKey[n])
        {
            // 将n覆盖
            isKey[n] = false;

            // 按照规则更新n
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = (3 * n + 1) / 2;
            }
        }
        // n已被覆盖，不必往下计算
        else
        {
            break;
        }
    }
}
```

## 总结

在使用memset函数初始化数组的时候要注意赋值的长度。
例如：
```c++
int num[100];
memset(num, 0, 100);
```
这样的写法是错误的，因为memset只修改了```100 / sizeof(int)```个元素的值，而没有把数组中所有元素的值赋给初值。

**正确的写法：**
```c++
int num[100];
memset(num, 0, 100 * sizeof(int));
```