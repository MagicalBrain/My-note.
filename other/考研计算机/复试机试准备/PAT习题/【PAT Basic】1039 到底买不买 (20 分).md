# 【PAT Basic】1039 到底买不买 (20 分)

## 题目描述

小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。
为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

![图片1](https://images.ptausercontent.com/b7e2ffa6-8819-436d-ad79-a41263abe914.jpg)

输入格式：
每个输入包含 1 个测试用例。每个测试用例分别在 2 行中先后给出摊主的珠串和小红想做的珠串，两串都不超过 1000 个珠子。

输出格式：
如果可以买，则在一行中输出 Yes 以及有多少多余的珠子；如果不可以买，则在一行中输出 No 以及缺了多少珠子。其间以 1 个空格分隔。

输入样例 1：
ppRYYGrrYBR2258
YrR8RrY

输出样例 1：
Yes 8

输入样例 2：
ppRYYGrrYB225
YrR8RrY

输出样例 2：
No 2

## 基本思路

## 代码

### 我自己写的代码

```c++
/*
* 1039题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1001];
    char need[1001];

    int num1[10] = {0};
    int c1[26] = {0};
    int C1[26] = {0};

    int num2[10] = {0};
    int c2[26] = {0};
    int C2[26] = {0};

    int lack = 0, redundant = 0;
    int no = 0;

    scanf("%s", str);
    scanf("%s", need);

    int i = 0;
    //扫描need字符串，得知需要的颜色
    while (need[i] != '\0')
    {
        if (need[i] >= '0' && need[i] <= '9')
            num1[ need[i] - '0' ] += 1;
        if (need[i] >= 'a' && need[i] <= 'z')
            c1[ need[i] - 'a' ] += 1;
        if (need[i] >= 'A' && need[i] <= 'Z')
            C1[ need[i] - 'A' ] += 1;
        i++;       
    }
    redundant -= i;

    i = 0;
    //扫描str字符串，得知有几个珠子
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            num2[ str[i] - '0' ] += 1;
        if (str[i] >= 'a' && str[i] <= 'z')
            c2[ str[i] - 'a' ] += 1;
        if (str[i] >= 'A' && str[i] <= 'Z')
            C2[ str[i] - 'A' ] += 1;
        i++;
    }
    redundant += i;

    for (int i = 0; i < 10; i++)
    {
        if (num1[i] != 0 && num2[i] == 0)
            no += 1;
        //计算
        if (num1[i] - num2[i] > 0)
            lack += num1[i] - num2[i];            
    }
    for (int i = 0; i < 26; i++) {
        if (c1[i] != 0 && c2[i] == 0)
            no += 1;
        //计算
        if (c1[i] - c2[i] > 0)
            lack += c1[i] - c2[i];
    }
    for (int i = 0; i < 26; i++) {
        if (C1[i] != 0 && C2[i] == 0)
            no += 1;
        //计算
        if (C1[i] - C2[i] > 0)
            lack += C1[i] - C2[i];
    }
    //判断是否可以买，并输出结果
    if (no) {
        printf("No %d\n", lack);
    }
    else 
        printf("Yes %d\n", redundant);
    
    return 0;
}
```

和柳婼的代码对比过了，还是不知道哪里有问题，居然有一个6分的测试用例过不了。

#### 根据柳婼的代码改的

```c++
/*
* 1039题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int book[256];

int main() {
    char a[1001], b[1001];
    scanf("%s %s", a, b);
    for (int i = 0; i < strlen(a); i++)
        book[a[i]]++;
    int result = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (book[b[i]] > 0)
            book[b[i]]--;
        else
            result++;
    }
    if(result != 0)
        printf("No %d\n", result);
    else
        printf("Yes %d\n", strlen(a) - strlen(b));
    return 0;
}
```

### 柳婼的代码

```c++
#include <iostream>
using namespace std;
int book[256];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        book[a[i]]++;
    int result = 0;
    for (int i = 0; i < b.length(); i++) {
        if (book[b[i]] > 0)
            book[b[i]]--;
        else
            result++;
    }
    if(result != 0)
        printf("No %d", result);
    else
        printf("Yes %d", a.length() - b.length());
    return 0;
}
```

## 总结
