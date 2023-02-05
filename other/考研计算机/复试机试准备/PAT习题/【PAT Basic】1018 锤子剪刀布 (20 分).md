# 【PAT Basic】1018 锤子剪刀布 (20 分)

## 题目描述

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

![](https://images.ptausercontent.com/724da598-b37f-4f1f-99b4-71459654ce3a.jpg)

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第 1 行给出正整数 $N（≤10​^5​​ ）$，即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：

输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：

5 3 2
2 3 5
B B

## 代码

### 我自己的代码

```c++
/*
* 1018题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isWin(char a,char b) {
    //int re = 0;
    if (a == 'B') {
        //int t = a - b;
        if (b == 'C')
            return 1;
        else if (b == 'B')
            return 0;
        else 
            return -1;
    }
    if (a == 'C') {
        //int t = a - b;
        if (b == 'B')
            return -1;
        else if (b == 'J')
            return 1;
        else
            return 0;
    }
    if (a == 'J') {
        //int t = a - b;
        if (b == 'B')
            return 1;
        else if (b == 'C')
            return -1;
        else
            return 0;
        
    }
    return 0;
}

int main() {
    int n;
    int a_win[3] = {0};
    int a_hand[3] = {0};
    int b_win[3] = {0};
    int b_hand[3] = {0};

    char a, b;
    char ch[4] = "BCJ";

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c %c", &a, &b);
        //printf("a=%c b=%c\n",a,b);
        getchar();
        if (isWin(a,b) == 1) {
            a_win[0]++;
            b_win[2]++;
            if (a == 'B')
                a_hand[0]++;
            else if (a == 'C')
                a_hand[1]++;
            else 
                a_hand[2]++;
        }
        else if (isWin(a,b) == -1) {
            a_win[2]++;
            b_win[0]++;
            if (b == 'B')
                b_hand[0]++;
            else if (b == 'C')
                b_hand[1]++;
            else 
                b_hand[2]++;
        }
        else {
            a_win[1]++, b_win[1]++;
        }
    }
    
    int max_a = 0, max_b = 0;
    char hand1, hand2;
    for (int i = 0; i < 3; i++)
    {
        if (max_a < a_hand[i]) {
            max_a = a_hand[i];
            hand1 = ch[i];
        }
        if (max_b < b_hand[i]) {
            max_b = b_hand[i];
            hand2 = ch[i];
        }
    }
    if (max_a == 0)
        hand1 = ch[0];
    if (max_b == 0)
        hand2 = ch[0];
    
    //输出结果
    printf("%d %d %d\n", a_win[0], a_win[1], a_win[2]);
    printf("%d %d %d\n", b_win[0], b_win[1], b_win[2]);
    printf("%c %c\n", hand1, hand2);
    
    return 0;
}
```

之前一直无法全部AC的原因终于找到了：
如果某一方一直都是输的话，那它的赢得最多的手势一定是'B'！

### 别人的代码

```c++
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    char jia, yi;
    int jiaWin = 0;
    int jiaPing = 0;
    int jiaLost = 0;
    int jiaWinB = 0;
    int jiaWinC = 0;
    int jiaWinJ = 0;
    int jiaWinMax;
    char jiaMaxChar;

    int yiWin = 0;
    int yiPing = 0;
    int yiLost = 0;
    int yiWinB = 0;
    int yiWinC = 0;
    int yiWinJ = 0;
    int yiWinMax;
    int yiMaxChar;

    for (int i = 0; i < N; i++) {
        getchar();
        scanf("%c %c", &jia, &yi);
        if (jia == 'B') {
            if (yi == 'C') {
                jiaWin++;
                jiaWinB++;
                yiLost++;
            } else if (yi == 'J') {
                jiaLost++;
                yiWin++;
                yiWinJ++;
            } else {
                jiaPing++;
                yiPing++;
            }
        } else if (jia == 'C') {
            if (yi == 'J') {
                jiaWin++;
                jiaWinC++;
                yiLost++;
            } else if (yi == 'B') {
                jiaLost++;
                yiWin++;
                yiWinB++;
            } else {
                jiaPing++;
                yiPing++;
            }
        } else if (jia == 'J') {
            if (yi == 'B') {
                jiaWin++;
                jiaWinJ++;
                yiLost++;
            } else if (yi == 'C') {
                jiaLost++;
                yiWin++;
                yiWinC++;
            } else {
                jiaPing++;
                yiPing++;
            }
        }
    }

    printf("%d %d %d\n", jiaWin, jiaPing, jiaLost);
    printf("%d %d %d\n", yiWin, yiPing, yiLost);

    jiaWinMax = jiaWinB;
    jiaMaxChar = 'B';
    if (jiaWinC > jiaWinMax) {
        jiaWinMax = jiaWinC;
        jiaMaxChar = 'C';
    }
    if (jiaWinJ > jiaWinMax) {
        jiaWinMax = jiaWinJ;
        jiaMaxChar = 'J';
    }

    yiWinMax = yiWinB;
    yiMaxChar = 'B';
    if (yiWinC > yiWinMax) {
        yiWinMax = yiWinC;
        yiMaxChar = 'C';
    }
    if (yiWinJ > yiWinMax) {
        yiWinMax = yiWinJ;
        yiMaxChar = 'J';
    }

    printf("%c %c", jiaMaxChar, yiMaxChar);
    return 0;
}
```

## 总结

在写代码之前一定要多想想**特殊解**的情况
想不出特殊解，或者想的不够全面就一定无法AC的。
