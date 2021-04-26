# 【PAT Basic】1009 说反话 (20 分)

## 题目描述

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。

输入样例：

Hello World Here I Come

输出样例：

Come I Here World Hello

## 基本思路

### 方法一：

类比上一题的逆序思想，先对整个字符串进行逆序操作，然后遍历字符串，利用双指针法获取单个单词，碰到空格就对单词进行逆序操作。

## 代码

### 方法一

```c++
/*
* 1009题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

void reverse(char *str, int l,int r) {
    if (NULL == str)
        return ;
    for (int i = l, j = r; i < j; i++, j--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

int main() {
    char in[81];
    int len = 0;
    int temp = 0;

    gets(in);
    while (in[len] != '\0')
    {
        len++;
    }
    
    reverse(in,0, len - 1);
    for (int i = 0; i <= len; i++)
    {
        if (in[i] == ' ' || i == len) {
            reverse(in, temp, i - 1);
            temp = i + 1;
        }
    }
    puts(in);
    return 0;
}
```

## 总结

还是老问题，题目里提到字符串最长为80位，应该用长度为81位的字符数组来存而不是80位的数组，因为最后一位要留给'\0'。