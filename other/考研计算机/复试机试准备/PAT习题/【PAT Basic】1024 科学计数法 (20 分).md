# 【PAT Basic】1024 科学计数法 (20 分)

## 题目描述

科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。
现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03

输出样例 1：
0.00123400

输入样例 2：
-1.2E+10

输出样例 2：
-12000000000

## 基本思路

## 代码

### 我自己的代码

```c++
/*
* 1024题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str2num(char str[], int len) {
    int re = 0;
    int t = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        //printf("%d\n", re);
        re += (str[i] - '0') * t;
        t *= 10;
    }
    
    return re;
}

int main() {
    char flag1, flag2;
    char str[10000];
    
    char num[20000];
    int top = 0;
    int n;

    char exp[5];
    int top_e = 0;
    int exp_num;
    
    scanf("%s", str);
    //printf("%s\n", str);

    int i = 0;
    while (str[i] != 'E')
    {
        if (i == 0) 
            flag1 = str[i];
        else if (str[i] != '.')
            num[top++] = str[i];
        i++;
    }
    num[top] = '\0';

    flag2 = str[++i];
    i++;
    while (str[i] != '\0')
    {
        exp[top_e++] = str[i];
        i++;
    }
    exp[top_e] = '\0';
    
    exp_num = str2num(exp, top_e);

    int zero = str2num(num, top);
    if (zero == 0) {
        printf("%d\n", zero);
        return 0;
    }
    
    //如果是负数就打印负号  
    if (flag1 == '-')
        printf("-");
    //如果指数为0就打印原来的数不变
    if (exp_num == 0) {
        for ( i = top - 1; i > 0; i--)
        {
            num[i + 1] = num[i];
        }
        top++;
        num[top] = '\0';
        num[1] = '.';
        printf("%s",num);
    }
    //如果指数是负数就在前面加 0.0……
    else if (flag2 == '-') {
        printf("%d.",0);
        for (i = 0; i < exp_num - 1; i++)
        {
            printf("%d",0);
        }
        printf("%s",num);
    }
    //如果指数是正数就在后面添0
    else  {
        if (exp_num < top - 1) {
            for (i = top - 1; i > exp_num; i--)
            {
                num[i + 1] = num[i];
            }
            top++;
            num[exp_num + 1] = '.';
            num[top] = '\0';
            printf("%s",num);
        }
        else {
            printf("%s",num);
            for (i = top; i <= exp_num; i++)
            {
                printf("%d",0);
            }
            num[i] = '\0';
        }
    }
    printf("\n");
    //测试程序的时候可能用得到下面两句
    //printf("%s\n", num);
    //printf("%d\n", exp_num);   
    return 0;
}
```

最后一个用例跑不通，头疼啊

### 网上代码

```c++
#include<stdio.h>
#include<string.h>
 
int main()
{
	char ch[50000] = {};
	scanf("%s",ch);
	
	int count = 0;
	int len =strlen(ch);
	int move = 0;						//需移动
	int mark1 = 0;
	for(int i = len-1 ; i >= 0; i--)	//计算E后面的位数	
	{
		if('+' == ch[i])
			mark1 = 1;
		if('-' != ch[i] && '+' != ch[i])
		{
			count++;
			if(1 == count)
				move += ch[i] - '0';
			else
			{	
				int n = 1;
				for(int j = 1 ; j < count ; j++)
				{
					n *= 10;
				}
				move += (ch[i]-'0') * n;
			}
		}
		else
			break;
	}	
	char ch1[50000] = {};	//不带小数点
	char ch2[50000] = {};	//带小数点
	int n1 = 0,n2 = 0;
	for(int i = 1; i < len ; i++)	//提取值
	{
		ch2[n2++] = ch[i];
		if('.' != ch[i])
		{
			if('E' == ch[i])
			{
				ch2[n2-1] = '\0';
				ch1[n1] = '\0';
				break;
			}
			else
				ch1[n1++] = ch[i];
		}
 
	}
	int zero = 0;	//为0时直接输出0
	for(int i = 0 ; '\0' != ch1[i] ; i++)
	{
		if('0' != ch1[i])
			zero++;
	}
	if(0 == zero)
	{
		printf("0\n");
		return 0;
	}
 
	if('-' == ch[0])
		printf("-");
	char resu[50000] = {};
	if(0 == move)	//当指数为0
	{
		printf("%s",ch2);
		return 0;
	}
	else if(mark1)	//当指数为正
	{
		int l = strlen(ch1) - 1;
		if(move >= l)
		{
			int n = l+1;
			strcpy(resu,ch1);
			for(int i = 0 ; i < move - l ; i++)
			{
				resu[n++] = '0';
			}
			resu[n] = '\0';
		}
		else
		{
			for(int i = 0 ; move > 0 ; i++)
			{
				char temp = 0;
				if('.' == ch2[i])
				{
					temp = ch2[i];
					ch2[i] = ch2[i+1];
					ch2[i+1] = temp;
					move--;
				}
			}
			strcpy(resu,ch2);
		}
		int n = 0;
		for(int i = 0 ; '\0' != resu[i] ; i++)
		{
			if('0' == resu[i])
			{
				if('.' == resu[i+1] || '0' != resu[i])
					break;
				else
					n++;
			}
			else
				break;
		}
		for(int i = n ; '\0' != resu[i] ; i++)
			printf("%c",resu[i]);
	}
	else		//当指数为负
	{
		int n = 2;
		resu[0] = '0';
		resu[1] = '.';
		for(int i = 1 ; i < move ; i++)
		{
			resu[n++] = '0';
		}
		for(int i = 0 ; '\0' != ch1[i];i++)
		{
			resu[n++] = ch1[i];	
		}
		resu[n] = '\0';	
		printf("%s",resu);
		return 0;
	}
	return 0;	
}
```

写的太长了，注释太少if-else分支太多，可读性差。

### 利用了正则表达式

```c++
#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char sign1, dotright[10000], sign2;
	int dotleft, pow;
	int i;
	scanf_s("%c", &sign1, 1);   //读取第一个正负号
	scanf_s("%d", &dotleft);    //读取小数点左边的整数部分
	scanf_s("%*c");     //忽略小数点
	scanf_s("%[^E]", dotright, 10000);  //读取小数点右边的字符串直到'E'结束
	scanf_s("%*c");     //忽略字符'E'
	scanf_s("%c", &sign2, 1);   //读取第二个正负号，指数的正负号
	scanf_s("%d", &pow);    //读取指数
	int len = strlen(dotright);
	int zeroneed;
    //第一个符号如果是负号就打印出来
	if (sign1 == '-')
	{
		printf("-");
	}
	if (sign2 == '-')
	{
		printf("0.");
		while (pow > 1)
		{
			printf("0");
			pow--;
		}
		printf("%d", dotleft);
		for (i = 0; i < len; i++)
		{
			printf("%c", dotright[i]);
		}
	}
	else if (sign2 == '+')
	{
		printf("%d", dotleft);
		zeroneed = pow - len;
		for (i = 0; i < len; i++)
		{
			printf("%c", dotright[i]);
			if (i == pow - 1 && zeroneed != 0)
			{
				printf(".");
			}
		}
		if (zeroneed > 0)
		{
			for (i = 0; i < zeroneed; i++)
			{
				printf("0");
			}
		}
	}
    return 0;
}
```

非常好的思路，这个题我接触了这么久，第一次看到有人这么写的。

## 总结

还是老老实实搞懂第三种方法吧，借鉴了正则表达式的思想，处理起来简单多了。

