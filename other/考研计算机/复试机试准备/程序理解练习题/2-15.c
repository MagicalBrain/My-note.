#include <stdio.h>

int main()
{
    char *s = "12134211";
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, k;
    for (k = 0; s[k]; k++)
    {
        switch (s[k])
        {
        case '1':
            v1++;
        case '3' :
            v3++;
        case '2':
            v2++;
        default:
            v4++;
        }
    }
    printf("v1 = %d, v2 = %d, v3 = %d, v4 = %d\n", v1, v2, v3, v4);
    return 0;
}