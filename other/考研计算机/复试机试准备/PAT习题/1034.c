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