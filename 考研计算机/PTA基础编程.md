
```c
void Print_Factorial ( const int N )
{
    if (N < 0)
    {
        printf("Invalid input\n");
        return ;
    }
    else if (N == 0)
    {
        printf("%d\n",1);
        return ;
    }
    int n = N,tmp;
    int num[1000]={0};
    num[0]=1;
    for (int i = 1;i<=N;i++)
    {
        num[i-1]=num[i-1]*i;
        tmp = num[i-1] / 10;
        num[i-1]=num[i-1]%10;
        num[i]=tmp; 
    }

    printf("%lf\n",re);
}
```