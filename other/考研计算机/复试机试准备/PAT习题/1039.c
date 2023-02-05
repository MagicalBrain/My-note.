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

