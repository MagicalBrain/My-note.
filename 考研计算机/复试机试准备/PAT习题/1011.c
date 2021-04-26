/*
* 1011题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld",&a ,&b ,&c);
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else 
            printf("Case #%d: false\n", i);
    }
    
    return 0;
}