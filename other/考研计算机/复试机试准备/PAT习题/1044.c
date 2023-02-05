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