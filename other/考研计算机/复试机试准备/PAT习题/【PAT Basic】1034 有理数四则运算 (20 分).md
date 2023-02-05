# 【PAT Basic】1034 有理数四则运算 (20 分)

## 题目描述

本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照``` a1/b1 a2/b2 ```的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照``` 有理数1 运算符 有理数2 = 结果 ```的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式``` k a/b```，其中``` k ```是整数部分，```a/b ```是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出``` Inf```。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2

输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

输入样例 2：
5/3 0/6

输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

## 基本思路

需要写两个自函数才方便处理

1. 求最大公约数（我们知道化简一个分数需要先知道分子分母的最大公约数）
2. 化简函数（化简分数用的函数）

## 代码

### 我自己的代码

```c++
/*
* 1034题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这里需要用到绝对值函数abs
#include <math.h>

typedef struct number{
    long long k;
    long long numerator;  //分子
    long long denominator;    //分母
}number;

//求最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) 
        return a;
    else
        return gcd(b, a % b);
}

//化简函数
number Simplification(number n) {
    if (n.denominator == 0) {
        n.k = 0;
        n.numerator = 0;
        n.denominator = 0;
    }
    else if ( llabs(n.numerator) > llabs(n.denominator) ) {
        //分子绝对值大于分母
        n.k = n.numerator / n.denominator;
        n.numerator -= n.k * n.denominator;
        long long t = gcd(llabs(n.numerator) , n.denominator);
        n.numerator = llabs(n.numerator) / t;
        n.denominator /= t;
    }
    else if (llabs(n.numerator) == llabs(n.denominator)) {
        //分子绝对值等于分母
        if (n.numerator > 0)
            n.k = 1;
        else if (n.numerator == 0)
            n.k = 0;
        else 
            n.k = -1;
        n.numerator = 0;
        n.denominator = 0;
    }
    else {
        //分子绝对值小于分母
        n.k = 0;
        long long t = gcd(llabs(n.numerator) , n.denominator);
        n.numerator /= t;
        n.denominator /= t;
    }
    return n;
}

//输出分数的函数，调用前得先调用化简函数
void printf_number(number a) {
    if (a.k == 0 && a.denominator == 0) {
        printf("Inf");
        return ;
    }
    if (a.k < 0 || a.numerator < 0)
        printf("(");
    
    if (a.k != 0 && a.numerator != 0)
        printf("%lld %lld/%lld", a.k, a.numerator, a.denominator);
    else if (a.k != 0)
        printf("%lld", a.k);
    else if (a.numerator != 0) {
        printf("%lld/%lld", a.numerator, a.denominator);
    }
    else 
        printf("%d", 0);
    
    if (a.k < 0 || a.numerator < 0)
        printf(")");
}

//实现加法的函数
void add(number a, number b) {
    number re;
    re.k = 0;
    re.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    re.denominator = a.denominator * b.denominator;
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    
    //输出
    printf_number(a);
    printf(" + ");
    printf_number(b);
        
    printf(" = ");
    printf_number(re);
    printf("\n");
    
}

void minus(number a, number b) {
    number re;
    re.k = 0;
    re.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    re.denominator = a.denominator * b.denominator;
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    //输出
    printf_number(a);
    printf(" - ");
    printf_number(b);

    printf(" = ");
    printf_number(re);
    printf("\n");
}

void multiplication(number a, number b) {
    int minus_flag = 0;
    number re;
    re.k = 0;

    if (a.numerator < 0 && b.numerator > 0)
        minus_flag = 1;
    else if (a.numerator > 0 && b.numerator < 0)
        minus_flag = 1;
    
    re.numerator = llabs(a.numerator) * llabs(b.numerator);
    re.denominator = llabs(a.denominator) * llabs(b.denominator);

    if (minus_flag)
        re.numerator = -re.numerator;
    
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    //输出
    printf_number(a);
    printf(" * ");
    printf_number(b);
        
    printf(" = ");
    printf_number(re);
    printf("\n");
}

void Division(number a, number b) {
    int minus_flag = 0;
    number re;
    re.k = 0;

    if (a.numerator < 0 && b.numerator > 0)
        minus_flag = 1;
    else if (a.numerator > 0 && b.numerator < 0)
        minus_flag = 1;
    
    re.numerator = llabs(a.numerator) * llabs(b.denominator);
    re.denominator = llabs(a.denominator) * llabs(b.numerator);

    if (minus_flag) {
       if (re.k != 0)
            re.k = -re.k;            
        else 
            re.numerator = -re.numerator;
            
    }
    
    if (re.denominator != 0)
        re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    
    //输出
    printf_number(a);
    printf(" / ");
    printf_number(b);
        
    if (b.k == 0 && b.numerator == 0) {
        re.k = 0;
        re.numerator = 0;
    }

    printf(" = ");
    printf_number(re);
    printf("\n");
}

int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld%lld/%lld", &a1, &b1, &a2, &b2);
    //printf("%d/%d%d/%d", a1, b1, a2, b2);
    number a, b;
    a.k = 0;
    a.numerator = a1, a.denominator = b1;
    b.k = 0;
    b.numerator = a2, b.denominator = b2;

    /* ------ 计算结果 ------ */
    //加法
    add(a, b);
    //减法
    minus(a, b);
    //乘法
    multiplication(a, b);
    //除法
    Division(a, b);
    //输出结果
    return 0;
}
```

### 网上大佬的代码

```c++
#include <iostream>
#include <cmath>
 
using namespace std;
struct number
{
	long long int k, fenz, fenm;
};
long long int a1, b1, a2, b2;
long long int maxgongyueshu(long long int x,long long int y)
{
	long long int z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
void huajian(long long int afenz,long long int afenm)
{
	if (afenm == 0)
	{
		cout << "Inf";
		return;
	}
	if (afenz == 0)
	{
		cout << 0;
		return;
	}
	number tmp;
	long long int maxyue;
	if (abs(afenz) > abs(afenm))
	{
		tmp.k = afenz / afenm;
		if (abs(afenz)%abs(afenm) == 0)
		{
			tmp.fenz = 0;
			tmp.fenm = 0;
		}
		else
		{
			tmp.fenz = abs(afenz) - abs(tmp.k)*abs(afenm);
			maxyue = maxgongyueshu(abs(tmp.fenz), abs(afenm));
			tmp.fenz = tmp.fenz / maxyue;
			tmp.fenm = abs(afenm) / maxyue;
		}
	}
	else if (abs(afenz) == abs(afenm))
	{
		tmp.k = afenz / afenm;
		tmp.fenz = 0;
		tmp.fenm = 0;
	}
	else
	{
		tmp.k = 0;
		maxyue = maxgongyueshu(abs(afenz), abs(afenm));
		tmp.fenz = afenz / maxyue;
		tmp.fenm = afenm / maxyue;
	}
 
	///输出
	if (tmp.k == 0)
	{
		if (tmp.fenz * tmp.fenm < 0)
			cout << "(-" << abs(tmp.fenz) << "/" << abs(tmp.fenm) << ")";
		else
			cout << tmp.fenz << "/" << tmp.fenm;
	}
	else
	{
		if (tmp.fenz == 0 && tmp.fenm == 0)
		{
			if (tmp.k>0)
				cout << tmp.k;
			else
				cout << "(" << tmp.k << ")";
		}
		else
		{
			if (tmp.k>0)
				cout << tmp.k<<" "<<tmp.fenz<<"/"<<tmp.fenm;
			else
				cout << "(" << tmp.k << " " << tmp.fenz << "/" << tmp.fenm<<")";
		}
	}
}
 
void add()
{
	long long int m,n;
	m = a1*b2 + a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " + ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void mins()
{
	long long int m, n;
	m = a1*b2 - a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " - ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void multi()
{
	long long int m, n;
	m = a1*a2;
	n = b1*b2;
	huajian(a1, b1);
	cout << " * ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
void div()
{
	long long int m, n;
	m = a1*b2;
	n = b1*a2;
	huajian(a1, b1);
	cout << " / ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
int main()
{
	scanf("%lld/%lld", &a1, &b1);
	scanf("%lld/%lld", &a2, &b2);
	add();
	mins();
	multi();
	div();
	return 0;
}
```

当输入为两个负的真分数时，会出错，但是居然能够在平台上全部AC！？

### 网上大佬代码 版本二

```c++
#include <iostream>
#include <cmath>
 
using namespace std;
struct number
{
	long long int k, fenz, fenm;
};
long long int a1, b1, a2, b2;
long long int maxgongyueshu(long long int x,long long int y)
{
	long long int z = y;
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
void huajian(long long int afenz,long long int afenm)
{
	if (afenm == 0)
	{
		cout << "Inf";
		return;
	}
	if (afenz == 0)
	{
		cout << 0;
		return;
	}
	number tmp;
	long long int maxyue;
	if (abs(afenz) > abs(afenm))
	{
		tmp.k = afenz / afenm;
		if (abs(afenz)%abs(afenm) == 0)
		{
			tmp.fenz = 0;
			tmp.fenm = 0;
		}
		else
		{
			tmp.fenz = abs(afenz) - abs(tmp.k)*abs(afenm);
			maxyue = maxgongyueshu(abs(tmp.fenz), abs(afenm));
			tmp.fenz = tmp.fenz / maxyue;
			tmp.fenm = abs(afenm) / maxyue;
		}
	}
	else if (abs(afenz) == abs(afenm))
	{
		tmp.k = afenz / afenm;
		tmp.fenz = 0;
		tmp.fenm = 0;
	}
	else
	{
		tmp.k = 0;
		maxyue = maxgongyueshu(abs(afenz), abs(afenm));
		tmp.fenz = afenz / maxyue;
		tmp.fenm = afenm / maxyue;
	}
 
	///输出
	if (tmp.k == 0)
	{
		if (tmp.fenz * tmp.fenm < 0)
			cout << "(-" << abs(tmp.fenz) << "/" << abs(tmp.fenm) << ")";
		else
			cout << tmp.fenz << "/" << tmp.fenm;
	}
	else
	{
		if (tmp.fenz == 0 && tmp.fenm == 0)
		{
			if (tmp.k>0)
				cout << tmp.k;
			else
				cout << "(" << tmp.k << ")";
		}
		else
		{
			if (tmp.k>0)
				cout << tmp.k<<" "<<tmp.fenz<<"/"<<tmp.fenm;
			else
				cout << "(" << tmp.k << " " << tmp.fenz << "/" << tmp.fenm<<")";
		}
	}
}
 
void add()
{
	long long int m,n;
	m = a1*b2 + a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " + ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void mins()
{
	long long int m, n;
	m = a1*b2 - a2*b1;
	n = b1*b2;
	huajian(a1, b1);
	cout << " - ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
 
void multi()
{
	long long int m, n;
	m = a1*a2;
	n = b1*b2;
	huajian(a1, b1);
	cout << " * ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
void div()
{
	long long int m, n;
	m = a1*b2;
	n = b1*a2;
	huajian(a1, b1);
	cout << " / ";
	huajian(a2, b2);
	cout << " = ";
	huajian(m, n);
	cout << endl;
}
int main()
{
	scanf("%lld/%lld", &a1, &b1);
	scanf("%lld/%lld", &a2, &b2);
	add();
	mins();
	multi();
	div();
	return 0;
}
```

## 总结

注意：
1. 除了一些用来做标记的变量，所有参与计算的变量都必须是long long类型，否则会各种错误。
2. 在乘法和除法的计算中，要先通过分子分母的正负来判断最终结果的负号，否则可能会导致溢出而出错


## 测试程序

```c++
/*
* 1034题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这里需要用到绝对值函数abs
#include <math.h>

typedef struct number{
    long long k;
    long long numerator;  //分子
    long long denominator;    //分母
}number;

//求最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) 
        return a;
    else
        return gcd(b, a % b);
}

//化简函数
number Simplification(number n) {
    if (n.denominator == 0) {
        n.k = 0;
        n.numerator = 0;
        n.denominator = 0;
    }
    else if ( llabs(n.numerator) > llabs(n.denominator) ) {
        //分子绝对值大于分母
        n.k = n.numerator / n.denominator;
        n.numerator -= n.k * n.denominator;
        long long t = gcd(llabs(n.numerator) , n.denominator);
        n.numerator = llabs(n.numerator) / t;
        n.denominator /= t;
    }
    else if (llabs(n.numerator) == llabs(n.denominator)) {
        //分子绝对值等于分母
        if (n.numerator > 0)
            n.k = 1;
        else if (n.numerator == 0)
            n.k = 0;
        else 
            n.k = -1;
        n.numerator = 0;
        n.denominator = 0;
    }
    else {
        //分子绝对值小于分母
        n.k = 0;
        long long t = gcd(llabs(n.numerator) , n.denominator);
        n.numerator /= t;
        n.denominator /= t;
    }
    return n;
}

//输出分数的函数，调用前得先调用化简函数
void printf_number(number a) {
    if (a.k == 0 && a.denominator == 0) {
        printf("Inf");
        return ;
    }
    if (a.k < 0 || a.numerator < 0)
        printf("(");
    
    if (a.k != 0 && a.numerator != 0)
        printf("%lld %lld/%lld", a.k, a.numerator, a.denominator);
    else if (a.k != 0)
        printf("%lld", a.k);
    else if (a.numerator != 0) {
        printf("%lld/%lld", a.numerator, a.denominator);
    }
    else 
        printf("%d", 0);
    
    if (a.k < 0 || a.numerator < 0)
        printf(")");
}

//实现加法的函数
void add(number a, number b) {
    number re;
    re.k = 0;
    re.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    re.denominator = a.denominator * b.denominator;
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    
    //输出
    printf_number(a);
    printf(" + ");
    printf_number(b);
        
    printf(" = ");
    printf_number(re);
    printf("\n");
    
}

void minus(number a, number b) {
    number re;
    re.k = 0;
    re.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    re.denominator = a.denominator * b.denominator;
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    //输出
    printf_number(a);
    printf(" - ");
    printf_number(b);

    printf(" = ");
    printf_number(re);
    printf("\n");
}

void multiplication(number a, number b) {
    int minus_flag = 0;
    number re;
    re.k = 0;

    if (a.numerator < 0 && b.numerator > 0)
        minus_flag = 1;
    else if (a.numerator > 0 && b.numerator < 0)
        minus_flag = 1;
    
    re.numerator = llabs(a.numerator) * llabs(b.numerator);
    re.denominator = llabs(a.denominator) * llabs(b.denominator);

    if (minus_flag)
        re.numerator = -re.numerator;
    
    re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    //输出
    printf_number(a);
    printf(" * ");
    printf_number(b);
        
    printf(" = ");
    printf_number(re);
    printf("\n");
}

void Division(number a, number b) {
    int minus_flag = 0;
    number re;
    re.k = 0;

    if (a.numerator < 0 && b.numerator > 0)
        minus_flag = 1;
    else if (a.numerator > 0 && b.numerator < 0)
        minus_flag = 1;
    
    re.numerator = llabs(a.numerator) * llabs(b.denominator);
    re.denominator = llabs(a.denominator) * llabs(b.numerator);

    if (minus_flag) {
       if (re.k != 0)
            re.k = -re.k;            
        else 
            re.numerator = -re.numerator;
            
    }
    
    if (re.denominator != 0)
        re = Simplification(re);
    
    a = Simplification(a);
    b = Simplification(b);
    
    //输出
    printf_number(a);
    printf(" / ");
    printf_number(b);
        
    if (b.k == 0 && b.numerator == 0) {
        re.k = 0;
        re.numerator = 0;
    }

    printf(" = ");
    printf_number(re);
    printf("\n");
}

int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld%lld/%lld", &a1, &b1, &a2, &b2);
    //printf("%d/%d%d/%d", a1, b1, a2, b2);
    number a, b;
    a.k = 0;
    a.numerator = a1, a.denominator = b1;
    b.k = 0;
    b.numerator = a2, b.denominator = b2;

    //首先要对两个有理数进行化简
    /* ------ 检查化简函数 ------ */
    /*
    a = Simplification(a);
    b = Simplification(b);
    printf_number(a);
    printf("\n");
    printf_number(b);
    */

    /* ------ 计算结果 ------ */
    //加法
    add(a, b);
    //减法
    minus(a, b);
    //乘法
    multiplication(a, b);
    //除法
    Division(a, b);
    //输出结果
    return 0;
}
```