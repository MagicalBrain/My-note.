# 【PAT Basic】1044 火星数字 (20 分)

## 题目描述

火星人是以 13 进制计数的：
地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam

输出样例：
hel mar
may
115
13

## 基本思路

如何判别输入的是地球文还是火星文？
判断第一个字符是否是字母即可。

## 代码

### 我自己的代码

```c++
/*
* 1044题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char number1[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
     "jly", "aug", "sep", "oct", "nov", "dec"};
    char number2[12][5] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei",
     "elo", "syy", "lok", "mer", "jou"};
    
    int num;
    
    scanf("%d", &num);
    getchar();
    
    while (num > 0)
    {
        char in[10];
        gets(in);
        //int i = 0;
        int re = 0;
        if (in[0] >= '0' && in[0] <= '9') {
            //地球文转火星文
            int t = atoi(in);
            if (t > 13) {
                for (int i = 1; i <= 12; i++)
                { 
                    if (t / 13 == i) {
                        printf("%s ", number2[i - 1]);
                        break;
                    }
                }
            }

            if (t == 13)
                printf("%s\n", number2[0]);
            else {
                for (int i = 0; i < 13; i++)
                {
                    if (t % 13 == i) {
                        printf("%s\n", number1[i]);
                        break;
                    }
                }
            }
            
        }
        else {
            //火星文转地球文
            char *tok;
            const char s[2] = " ";
            int re = 0;
            int two = 0;
            
            if (strcmp(in, "tam") == 0)
                printf("13\n");
            else {
                for (int i = 0; in[i] != '\0'; i++)
                {
                    if (in[i] == ' ') {
                        two = 1;
                        break;
                    }
                }
                //printf("two = %d\n", two);
                if (two == 1) {
                    //两位火星文的处理
                    tok = strtok(in, s);
                    //printf("tok = %s\n", tok);

                    for (int i = 0; i < 12; i++)
                    {
                        if (strcmp(tok, number2[i]) == 0) {
                            re += (i + 1) * 13;
                            break;
                        }
                    }
                    tok = strtok(NULL, s);
                    if (NULL == tok)
                        printf("\n");
                    else {
                        for (int i = 0; i < 13; i++)
                        {
                            if (strcmp(tok, number1[i]) == 0) {
                                re += i;
                                break;
                            }
                        }
                    }
                }
                else {
                    //一位火星文的处理
                    for (int i = 0; i < 13; i++)
                    {
                        if (strcmp(in, number1[i]) == 0) {
                            re = i;
                            break;
                        }
                    }
                    
                }
                printf("%d\n", re);   
            }
            
        }
        
        num--;
    }   
    return 0;
}
```

### 柳婼的代码

```c++
#include <iostream>
#include <string>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
int len;
void func1(int t) {
    if (t / 13) cout << b[t / 13];
    if ((t / 13) && (t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << a[t % 13];
}
void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}
```

## 总结