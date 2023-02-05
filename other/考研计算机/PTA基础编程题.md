## 6-1 简单输出正整数


```c
void PrintN(int n)
{
    for (int i=0;i<n;i++)
    printf("%d\n",i+1);
}
```

## 6-2 多项式求值（得小心）

```c
double f( int n, double a[], double x )
{
    double re=0.0,t=x;;
    for (int i=1;i<= n;i++)
    {
        re+=a[i]*t;
        t*=x;
    }
    re+=a[0];
    return re;
}
```

## 6-3 简单求和

```c
int Sum ( int List[], int N )
{
    int re=0;
    for (int i=0;i<N;i++)
    re+=List[i];
    return re;
}
```

## 6-4 求自定类型元素的平均值

```c
ElementType Average( ElementType S[], int N )
{
    ElementType re=0.0;
    for (int i=0;i<N;i++)
    re+=S[i];
    re/=N;
    return re;
}
```

## 6-5 **求自定类型元素的最大值**

```c
ElementType Max( ElementType S[], int N )
{
    ElementType max=S[0];
    for (int i=1;i<N;i++)
        if (max<S[i])
        max=S[i];
    return max;
}
```

## **6-6** **求单链表结点的阶乘和**（值得关注）

```c
int FactorialSum( List L )
{
    int n=0,re=0,t;
    while(L != NULL)
    {
        t=1;
        for (int i=1;i<=L->Data;i++)
            t*=i;
        re+=t;
        L=L->Next;
    }
    return re;
}
```

## **6-7** **统计某类完全平方数**（值得关注）

```c
int IsTheNumber ( const int N )
{
    int t = sqrt(N);
    int num[10];
    int i=0,flag=0,n=N;
    if (t*t == N)
    {
        t=10;
        while (n / t)
        {
            num[i++]=n%t;
            n/=t;
        }
        num[i]=n;
        for (int j=0;j<=i;j++)
        {
            flag = 0;
            for (int k=j+1;k<=i;k++)
                if (num[j] == num[k])
                flag++;
            if (flag == 1)
            {
                return 1;
            }
        }
    }
    return 0;       
}
```

## **6-8** **简单阶乘计算**

```c
int Factorial( const int N )
{
    if (N == 0)
    return 1;
    else if (N<0)
    return 0;
    int re = 1;
	for (int i = 1; i <= N; i++)
		re *= i;
	return re;
}
```

## **6-9** **统计个位数字**

```c
int Count_Digit ( const int N, const int D )
{
    int num=N;
    if (num < 0)
    num*=-1;
    int t=10;
    int n[10];
    int i=0,flag=0;
    while(num / t)
    {
        n[i]=num%t;
        num/=t;
        i++;
    }
    n[i]=num;
    for (int j=0;j<=i;j++)
    if(n[j] == D)
        flag++;
    return flag;
}
```

## **6-10** **阶乘计算升级版**（重视）

涉及到大数计算的方面

```c
typedef struct bign
{
	int num[1000] = { 0 };
	int len = 0;
}bign;

bign BIGN_mult(bign a, int b)
{
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int tmp = a.num[i] * b + carry;
		c.num[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0)
	{
		c.num[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void Print_Factorial(const int N)
{
	if (N < 0)
	{
		printf("Invalid input\n");
		return;
	}
	else if (N == 0)
	{
		printf("%d\n", 1);
		return;
	}
	int t1,t2;
	bign n,re;
	n.num[0] = 1;
	n.len = 1;
	for (int i = 1; i <= N; i++)
	{
		re = BIGN_mult(n, i);
		n = re;
	}

	while (re.len > 0)
	{
		printf("%d", re.num[--re.len]);
	}
	printf("\n");
}
```

**改进**：

```c
#define Length 10000

int* BIGN_mult(int* a, int b,int *len,int *len0)
{
	int *c, lenc = 0;
	c = (int*)malloc( Length * sizeof(int));
	int carry = 0;
	for (int i = 0; i < *len; i++)
	{
		int tmp = a[i] * b + carry;
		c[lenc++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0)
	{
		c[lenc++] = carry % 10;
		carry /= 10;
	}
	*len0 = lenc;
	return c;
}

void Print_Factorial(const int N)
{
	if (N < 0 || N > 1000)
	{
		printf("Invalid input\n");
		return;
	}
	else if (N == 0)
	{
		printf("%d\n", 1);
		return;
	}
    
	int t1,t2;
	int n[ Length],re[ Length],*re1,*n1;
	memset(n, 0, sizeof(n));
	n1 = n;
	n1[0] = 1;
	
	memset(re, 0, sizeof(re));
	re1 = re;
	int len1 = 1, len2 = 0;
	int* l1 = &len1, * l2 = &len2;
	for (int i = 1; i <= N; i++)
	{
		re1 = BIGN_mult(n1, i,l1,l2);
		n1 = re1;
		len1 = *l2;
	}
	len2 = *l2;
	while (len2 > 0)
	{
		printf("%d", re1[--len2]);
	}
	printf("\n");
}
```

## **6-11** **求自定类型元素序列的中位数**

```c

```