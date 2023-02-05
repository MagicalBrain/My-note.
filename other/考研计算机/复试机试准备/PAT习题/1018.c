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