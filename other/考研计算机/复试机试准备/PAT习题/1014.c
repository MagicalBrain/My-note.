/*
* 1014题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str1[61];
    char str2[61];
    char str3[61];
    char str4[61];

    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);

    int i = 0, flag = 0, hour = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == str2[i] && hour == 0 && flag != 0 && str1[i] >= '0' && str1[i] <= 'N') {
            int t1 = str1[i] - '0';
            if (t1 > 9)
                printf(" %d:", str1[i] - 'A' + 10);
            else 
                printf(" %.2d:", t1);
            break;
        }

        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'A' + 7 && flag == 0) {
            int t1 = str1[i] - 'A';
            printf("%s", day[t1]);
            flag++;
        }
        
        i++;
    }
    
    i = 0;
    while (str3[i] != '\0')
    {
        if (str3[i] == str4[i] && str3[i] >= 'A' && str4[i] <= 'z') {
            printf("%.2d\n", i);
            break;
        }
        i++;
    }
    
    return 0;
}