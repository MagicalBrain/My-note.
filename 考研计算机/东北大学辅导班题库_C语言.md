# 东北大学 考研C语言题库

[toc]

## 1、从键盘输入一个整数，判断是否为素数

**基本思想**：

首先得搞明白什么是素数？

素数就是除了1和它自己，没有别的约数，也就是不能被别的数整除。**注意：**1不是素数，素数是从2开始的。

一般人都会想到：那就从2开始，挨个除，判断余数是否为0不就行了？

但是这样时间复杂度是$O(n)$，看上去不算太高，但是如果有其他操作的话，时间复杂度可能就会高得多。

假设n有除了1和它自己以外的约数，设为k，由$$k \times \frac{n}{k} = n$$可知，$\frac{n}{k}$也是n的一个约数。而且显然的有，$k$和$\frac{n}{k}$必定有一个大于零，另外一个小于零。

所以我们只要判断2到它们两个当中比较小的一个就可以减少时间复杂度了。

那么这个较小的数怎么判定呢？我们可以用开根号再下取整来解决。即$min = \lfloor\sqrt{n}\rfloor$

**代码实现**：

<details>
<summary>点击查看隐藏内容</summary>
```c
bool func01(int num)
/*输入一个整数，判断其是否是素数*/
{
	if (num > 1)
	{
		int sqr = sqrt(num), i;
		//第一步，取其开根号的值再下取整，赋给sqr
		for (i = 2; i <= sqr; i++)
			if (num % i == 0)
				return false;
		//第二步，循环除2到sqr，若能整除则不是素数
		return true;
	}
	return false;
}
```
</details>

## 2、求解从1到20000的所有水仙花数，水仙花数使每位数字的n次方之和等于本身，n是位数

**基本思想**：

首先我们得把这个数的每一位数都要确定下来，然后找出其位数n，最后计算每位数的n次方之和

**确定某一位的值**：
<details>
<summary>点击查看隐藏内容</summary>
```c
int i = 0, t, tmp = num;
	int w[5];

	while (tmp > 0)
	{
		w[i] = tmp % 10;
		i++;
		tmp /= 10;
	}
```
每一位的值都在数组w里了
</details>


**本质**：

$num \% 10$即把num最后一位取出

$num / 10$即把num最后一位去掉，为取下一位做准备

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void shuixian(int num)
{
	int i = 0, t, tmp = num;
	int w[5];	
	/*
	注意数组长度为5的话，当范围再大一点就会造成数组溢出，
	例如:范围大到200000
	*/

	while (tmp > 0)
	{
		w[i] = tmp % 10;
		i++;
		tmp /= 10;
	}

	int sum = 0;
	for ( t = 0; t < i; t++)
	{
		if (w[t])
			sum += (int)(pow(w[t], i));
	}
	if (sum == num)
		printf("%d\n", num);
}

void func02()
/*
打印1到20000的所有水仙花数
*/
{
	int i;
	for ( i = 1; i <= 20000; i++)
	{
		shuixian(i);
	}
}
```
</details>

### 09/05/2020改进

<details>
<summary>点击查看隐藏内容</summary>
```c
/*
* author:HRL
*
* date:09/04/2020
* 
* description:
* 2、求解从1到20000的所有水仙花数（narcissistic number），水仙花数使每位数字的n次方之和等于本身，n是位数
*
* consuming time:
real	0m0.045s
user	0m0.028s
sys	    0m0.014s
*/

#include<stdio.h>

int Is_NarcissisticNumber(int num)
{
    int sum = 0, x1 , x2 = 1, num0 = num, n = 5,max = 10000;
    
    if (num > 20000 || num < 1)
        return 0;
    else
    {
        while (num / max == 0)
        {
            n--;
            max /= 10;
        }
        
        while (num != 0)
        {
            x1 = num % 10;
            num /= 10;
            x2 = 1;
            for (int i = 0;i < n;i++)
                x2 *= x1;
            sum += x2;
        }
        if (sum == num0)
        {
            printf("%d 是水仙花数！\n",num0);
        }
        else
            return 0;      
    }
    
    return 1;
}

#define max_num 20000

int main()
{
    for (int i = 1;i <= max_num;i++)
        Is_NarcissisticNumber(i);
    return 0;
}
```
</details>

## 3、求解从2到20000的所有完数

完数：所有公因数的和等于本身的数

**基本思想**：

首先把该数的所有公因数求出来存到数组里，最后把数组里的所有的数求和，把和与该数进行比较，判断其是否为完数，是则输出

**代码实现**:
<details>
<summary>点击查看隐藏内容</summary>
```c++
void func03()
/*
求出2到20000的所有完数
*/
{
	int num, sum;
	for (int i = 2; i <= 20000; i++)
	{
		num = i;
		sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (num % j == 0)
				sum += j;
		}
		if (sum == num)
			printf("%d\n", num);
	}
}
```
</details>

### 09/05/2020 改进
<details>
<summary>点击查看隐藏内容</summary>
```c
/*
* author:HRL
*
* date:09/05/2020
* 
* description:
* 3、求解从2到20000的所有完数（Perfect Number）
完数：所有公因数的和等于本身的数
*
* consuming time:
real	0m0.045s
user	0m0.028s
sys	0m0.014s
*/

#include<stdio.h>
#include<math.h>

int Is_PerfectNumber(int num)
{
    int sqr = 0, sum = 0;

    sqr = sqrt(num);
    for (int i = 1; i <= sqr;i++)
        if (num % i == 0)
        {
            sum += i;
            sum += (num / (i));
        }
    if (sum - num == num)
        return 1;
    return 0;
}

int main()
{
    for (int i = 2;i <= 20000;i++)
    {
        if (Is_PerfectNumber(i))
            printf("%d是完数！\n",i);
    }
    return 0;
}
```
</details>

## 4、从键盘输入两个数，求解m和n的最小公倍数

**基本思想**：

设$lcm(m,n)$为其最小公倍数

设$gcd(m,n)$为其最大公因数

先求最大公因数，求出来后，我们可以马上得到最小公倍数为$mn / gcd(m,n)$

**求最大公因数**：

利用这样一个定理：

$gcd(m,n)=gcd(m,n \% m)$，一直递归下去，

直到（递归边界）：$gcd(m,0)=m$ (0和任意一个整数a的最大公因数都是a)

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
int gcd(int m, int n)
/*
求m，n的最大公因数
*/
{
	if (n == 0)
		return m;
	gcd(n, m % n);
}

int func04(int m,int n)
/*
求m和n的最小公倍数
*/
{
	return (m*n)/gcd(m,n);
}
```
</details>

## 5、一个小球从10m处落下，每次弹回之前高度的一半，请问小球在静止前走过来多少距离？

**易错点：**
求一半的一半……肯定涉及到浮点数的运算，凡是浮点数的运算首先要考虑的就是精度。

<details>
<summary>点击查看隐藏内容</summary>
```c
double func05()
/*
小球从10m高的地方掉下，每一次弹回之前高度的一半，问求静止后，走过的距离
*/
{
	double sc = 0.0000001;
	double h = 10;
	double sum = 10;
	h /= 2;
	while (h > sc)
	{
		sum += 2 * h;
		h /= 2;
	}
	return sum;
}
```
</details>

## 6、斐波那契数列(20191002)

**基本思想**：

法一：递归法，比较简单，只要弄清楚递归出口即可

法二：循环队列，也比较简单，就是出队的时候要小心（本质上如果使用数组处理也是一样的），该方法还可扩展到k阶斐波那契数列，详细看我另外一篇专门介绍斐波那契数列实现的文章

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
int func06(int num)
/*
输出指定序号的斐波那契数
*/
{
	if (num <= 2)
		return 1;
	else
		return func06(num - 2) + func06(num - 1);
}
```
</details>

## 7、输入一行英文，判断其中一共有多少个单词，不能包括冠词“a”，例如：“A pen drop from tree.”一共有4个单词

**基本思想**：
设置一个辅助字符串数组，随着输入字符串数组读入同步读取到辅助数组。并定义一个int变量为辅助字符串数组最后一个字符的下标。当输入字符数组读到空格的时候，判断刚读入的单词是否为冠词“a”，否则单词数re加1。

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
int func07(char str[])
/*
统计字符串中单词的个数
*/
{
	char tmp[20];
	int top = 0;
	int i = 0,re = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			if (str[i - 1] == 'a' || str[i - 1] == 'A')
			{
				if (top > 1)
					re++;
			}
			else
				re++;
			top = 0;
		}
		else
			tmp[top++] = str[i];
		i++;
	}
	return re+1;
}
```
</details>

## 8、两个乒乓球队，甲队有a、b、c三名队员，乙队有d、e、f三名队员，a不愿意与d比赛，c不愿意与d、f比赛，求合适的比赛名单

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void func08()
{
	char a[] = {'a','b','c'};
	char b[] = { 'd','e','f' };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (a[i])
			{
			case 'a':
				if (b[j] == 'd')
					continue;
				break;
			case 'c':
				if (b[j] == 'd' || b[j] == 'f')
					continue;
			default:
				break;
			}
			printf("%c with %c\n", a[i], b[j]);
		}
		
	}
}
```
</details>

## 9、求三个字符串中的最大者

**基本思想**：

思路比较简单，先写一个函数能够进行两两比较的，然后再主功能函数里调用两次就好

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
char* CompareStr(char s1[], char s2[])
{
	int l1 = sizeof(s1) / sizeof(char);
	int l2 = sizeof(s2) / sizeof(char);

	int i = 0, l;
	char* re = NULL;
	while (i < l1 && i < l2)
	{
		if (s1[i] < s2[i])
		{
			re = s2;
			l = l2;
			break;
		}
		else if (s1[i] > s2[i])
		{
			re = s1;
			l = l1;
			break;
		}
		else
			i++;
	}
	if (NULL == re)
		if (l1 > l2)
		{
			re = s1;
			l = l1;
		}
		else
		{
			re = s2;
			l = l2;
		}
	return re;
}

char* func09(char s1[], char s2[],char s3[])
{
	char* t;
	t = CompareStr(s1, s2);
	t = CompareStr(t, s3);
	return t;
}
```
</details>

## 10、一篇文本中共有三行文字，每行不多于5个字符，要求分别统计出每行中的大写字母，小写字母，数字，空格以及其他字符的个数

**基本思想**：
首先利用C语言的文件输入部分的只是来解决这个问题。先用fopen函数来打开文件，并将返回值存到FILE类型指针。再使用fgets函数来获取每一行的字符串并存到一个字符数组中进行处理。

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void func10(char* str)
{
	int i = 0;
	int U = 0, D = 0, N = 0, S = 0, E = 0;
	//U大写，D小写，N数字，S空格，E其他
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			continue;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
			U++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			D++;
		else if (str[i] >= '0' && str[i] <= '9')
			N++;
		else if (str[i] == ' ')
			S++;
		else
			E++;
		i++;		
	}
	printf("大写字母：%d\n小写字母：%d\n数字：%d\n空格：%d\n其他字符：%d\n",U,D,N,S,E);
}
```
</details>

**注意**：
上述代码没有涉及到文件读取，我这里是直接用一个字符串来存三行文本的，如果题目有其他要求则还需变化。

**正确做法应为（09/10/2020修改）：**
<details>
<summary>点击查看隐藏代码</summary>
```c
/*
* author:HRL
*
* date:09/10/2020
* 
* description:
* 10、一篇文本中共有三行文字，每行不多于5个字符，
要求分别统计出每行中的大写字母，小写字母，数字，空格以及其他字符的个数
*
* consuming time:
real    0m0.043s
user    0m0.027s
sys     0m0.013s
*/

#include <stdio.h>
#include<stdlib.h>

///Users/hrlnoimac/Desktop/C_demo/东北大学考研题库/10.txt
#define line 3

int main()
{
    FILE* fp1;
    char filename[] = "/Users/hrlnoimac/Desktop/C_demo/东北大学考研题库/10.txt";
    char str[100];
    fp1 = fopen(filename,"r");
    if (fp1 == NULL)
    {
        printf("无法打开文件！\n");
        exit(0);
    }

    int n1 = 0,n2 = 0, n3 = 0, n4 = 0, n5 = 0, top = 0;;    
    for (int i = 0; i < line; i++)
    {
        fgets(str,100,fp1);
        puts(str);
        n1 = 0,n2 = 0, n3 = 0, n4 = 0, n5 = 0, top = 0;
        while (str[top] != '\n')
        {
            if (str[top] >= 'A' && str[top] <= 'Z')
                n1++;
            else if (str[top] >= 'a' && str[top] <= 'z')
                n2++;
            else if (str[top] >= '0' && str[top] <= '9')
                n3++;
            else if (str[top] == ' ')
                n4++;
            else
                n5++;
            top++;
        }
        printf("大写字母有%d个，小写字母有%d个，数字有%d个，空格有%d个，其他字符有%d个\n", 
        n1, n2, n3, n4, n5);
    }    

    return 0;
}
```
</details>

## 11、求出一个二维数组的鞍点。

**鞍点**：

行上最大，列上最小，可能有，也可能没有

**基本思想**：
1. 分别用动态数组存每一行的最大值、每一列的最小值、及行最大值对应的行数组的下标（列标）。
2. 对二维数组进行两次遍历，第一次遍历找每一行的最大值，并将找到的最大值的列下标存入数组；第二次遍历找每一列的最小值；
3. 最后同时对最大值数组和最小值数组进行遍历，判断二维数组中的```[i][max_c[i]]```位置（可能的最大值）与```min[j]```比较，如果相等就是一个鞍点。这样可以考虑到鞍点相同的情况。

**注意：**鞍点是可以有多个的。

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void func11(int **a,int r,int c)
{
	int* max = (int*)malloc(r * sizeof(int));
	//存的是每一行的最大值
	int* min = (int*)malloc(c * sizeof(int));
	//存的是每一列的最小值
	int* max_r = (int*)malloc(r * sizeof(int));
	//存的是最一行的最大值的下标
	//int* min_c = (int*)malloc(c * sizeof(int));
	
	for (int i = 0; i < r; i++)
	{
		max[i] = 0;
	}
	

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] > max[i])
			{
				max[i] = a[i][j];
				max_r[i] = j;
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		min[i] = a[0][i];
		for (int j = 0; j < r; j++)
		{
			if (a[j][i] < min[i])
			{
				min[i] = a[j][i];
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][max_r[i]] == min[j])
				printf("鞍点为：%d，（%d,%d）\n", max[i],i,j);
		}
	}
}
```
</details>

## 12、有一行电文，译码规律为：a->z,b->y,c->x。即把第一个字母改成第26个字母，第i个字母换成第26-i+1个字母，非字母符号不变

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
char* func12(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'Z' - ((str[i] - 'A') % 26);
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - ((str[i] - 'a') % 26);
		i++;
	}
	return str;
}
```
</details>

## 13、将两个字符串连接起来，不能用strcat函数

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
char* func13(char* str1, char* str2)
{
	int i = 0, flag = 0;
	while (str1[i] != '\0')
		i++;

	flag = i; i = 0;
	while (str2[i] != '\0')
	{
		str1[flag + i] = str2[i];
		i++;
	}
	return str1;
}
```
</details>

## 14、将两个字符串s1、s2进行比较，如果s1大于s2则输出一个正数，相等则输出0，小于则输出一个负数，不能用strcmp函数。输出的正数或负数应该是比较两字符串对应字符的ASCII码的差值

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
int func14(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] > str2[i])
		{
			return str1[i] - str2[i];
		}
		else if (str1[i] < str2[i])
			return str1[i] - str2[i];	
		i++;
	}
	if (str1[i] != '\0')
		return 1;
	else if (str2[i] != '\0')
		return -1;
	return 0;
}
```
</details>

## 15、将字符串数组s2中全部字符复制到字符数组s1中，不用strcpy函数

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void func15(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
}
```
</details>

## 16、用时间最短的方法将负数全部排在正数前面。

比如：-1,-2,-1,0,1,3,2

**代码实现：**
<details>
<summary>点击查看隐藏内容</summary>
```c
void func16(int in[],int l)
{
	//int l = sizeof(in) / sizeof(int);
	int* fu = (int*)malloc(l * sizeof(int));
	int* zh = (int*)malloc(l * sizeof(int));
	int f = 0, z = 0;
	for (int i = 0; i < l; i++)
	{
		if (in[i] < 0)
			fu[f++] = in[i];
		if (in[i] > 0)
			zh[z++] = in[i];
		else if(in[i]==0)
			fu[f++] = in[i];
	}
	z = 0;
	for (int i = 0; i < l; i++)
	{
		if (i < f)
			in[i] = fu[i];
		else
			in[i] = zh[z++];
	}
}
```
</details>

## 17、数组a和b各有10个元素，将他们对应的逐个比较，如果a中元素大于b中相应的元素次数多于b数组中元素大于a的次数，则a大于b，并统计大于等于小于的次数

$\geq,\neq,\leq$

**代码实现：**
<details>
<summary>点击查看隐藏内容</summary>
```c
bool func17(int a[10],int b[10])
{
	int geq = 0, e = 0, leq = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > b[i])
			geq++;
		if (a[i] < b[i])
			leq++;
		if (a[i] == b[i])
			e++;
	}
	printf("大于次数：%d\n等于次数：%d\n小于次数：%d\n", geq, e, leq);
	if (geq > 5)
		return true;
	else 
		return false;
}
```
</details>

## 18、编写函数，使输入一个字符串按反序存放

**基本思想**：

**代码实现**：
<details>
<summary>点击查看隐藏内容</summary>
```c
void func18(char *str)
{
	int l = 0, mid;
	while (str[l] != '\0')
		l++;
	mid = l / 2;
	for (int i = 0; i < mid; i++)
	{
		char t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
	}
}
```
</details>

## 19、求$s_n = a+aa+aaa+\cdots + aa\cdots a$，其中a为一个数字，一共有n项，a和n由键盘输入

**代码实现：**
<details>
<summary>点击查看隐藏内容</summary>
```c
void func19()
{
	int a, n;
	puts("输入a：");
	scanf("%d", &a);
	puts("输入n：");
	scanf("%d", &n);
	
	double l = 1;
	double* num = (double*)malloc(sizeof(double));
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			num[i] = num[i - 1] + (a * l);
		}
		else
			num[i] = a;
		l *= 10;
		//printf("%d, ", num[i]);
	}
	//printf("\n");
	double re = 0;
	for (int i = 0; i < n; i++)
	{
		re += num[i];
	}
	printf("%ld\n", re);
}
```
</details>

**小心溢出**

## 20、设计一个函数process，在你调用该函数的时候，每次实现不同的功能。输入a，b两个数，第一次找出a、b中最大的，第二次找出最小的，第三次求其和

**基本思路**：

利用static变量不会变的原理，这是关键！

<details>
<summary>点击查看隐藏内容</summary>
```c
void process(int a,int b)
{
	static int times = 0;
	
	switch (times)
	{
	case 0:
		if (a > b)
			printf("%d\n", a);
		else
			printf("%d\n", b);
		break;
	case 1:
		if (a > b)
			printf("%d\n", b);
		else
			printf("%d\n", a);
		break;
	case 2:
		printf("%d\n", a + b);
		break;
	}
	times++;
}
```
</details>

## 21、输入某年某月某日，判断这天是该年的第几天

**基本思想**：

**关键是怎么判断闰年**

1. 先判断是否能被4整除而又不能被100整除，是则是闰年
2. 不满足条件1的有些年份也是闰年，即再判断是否能被400整除，实则是闰年

<details>
<summary>点击查看隐藏内容</summary>
```c
void func21()
{
	int year, month, day;
	scanf("%d年%d月%d日", &year, &month, &day);

	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if ((year % 4) == 0 && (year % 100) != 0)
		months[1] = 29;
	else if (year % 400 == 0)
		months[1] = 29;

	int sum = 0;
	for (int i = 0; i < month-1; i++)
	{
		sum += months[i];
		printf("%d, ", months[i]);
	}
	printf("\n");
	//puts("")
	printf("%d\n", sum + day);
}
```
</details>

## 22、求一个字符串的长度

<details>
<summary>点击查看隐藏内容</summary>
```c
int func22(char* s)
{
	int l = 0;
	while (s[l] != '\0')
		l++;
	return l;
}
```
</details>

给这道题增加点难度，如果不允许使用任何全局变量和局部变量，如何实现strlen函数的功能？（当然，任何库函数也是不允许使用的）

<details>
<summary>点击查看隐藏内容</summary>
```c
int MyStrlen(char* str)
{
    if (!*str)
        return 0;
    else
        return 1+MyStrlen(++str);    
}
```
</details>

## 23、有n个正数，使得前面每个数依次向后移动m个位置，最后m个数变成前面个数

<details>
<summary>点击查看隐藏内容</summary>
```c
void func23(int* num, int n, int m)
{
	int* move = (int*)malloc(m * sizeof(int));
	int i = 0;
	for (i = 0; i < m; i++)
	{
		move[i] = num[i];
	}
	for (i = 0; i < n - m; i++)
		num[i] = num[i + m];
	for (int j = 0; i < n; i++, j++)
		num[i] = move[j];
}
```
</details>

## 24、有一个字符串，包含n个字符，编写一函数，将此字符串中第m个字符开始的全部字符复制成另外一个字符串

<details>
<summary>点击查看隐藏内容</summary>
```c
/*
* author:HRL
*
* date:09/17/2020
* 
* description:
* 24、有一个字符串，包含n个字符，编写一函数，
将此字符串中第m个字符开始的全部字符复制成另外一个字符串
*
* consuming time:
real    0m0.047s
user    0m0.030s
sys     0m0.015s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func24(char **str1,char *str2,int n,int m)
{
	int l1 = strlen(*str1),l2 = strlen(str2),l = l1 + l2 + 1;
	printf("字符串1的长度：%d\n",l1);	(*str1)[l1] = '\0';
	printf("字符串2的长度：%d\n",l2);	str2[l2] = '\0';
	if (m <= 0 || m > l1)
	{
		puts("请输入正确的m\n");
		return ;
	}

	if (m + l2 > n)
	{
		l = m + l2 + 1;
		char *re = (char*) malloc ( l * sizeof (char));
		*re = '\0';
		strcpy(re,*str1);
		*str1 = re;
	}
	char *s1 = *str1, *s2 = str2;
	
	int ri = 0;

	//puts(re);

	ri = m - 1;
	while (*s2 != '\0')
	{
		s1[ri] = *s2;
		//printf("%c ",s1[ri]);
		++s2;
		++ri;
	}
	s1[ri] = '\0';
}

int main()
{
	int m,n;
	printf("请输入n：\n");
	scanf("%d",&n);
	printf("请输入m：\n");
	scanf("%d",&m);

	printf("%d\n",n);
	printf("%d\n",m);

	char *str1 = (char*) malloc ((n + 1)  * sizeof(char));
	char *str2 = (char*) malloc ((n + 1)  * sizeof(char));
	
    puts("请输入第一个字符串：");
	scanf("%s",str1);
    puts("请输入第二个字符串：");
	scanf("%s",str2);

	puts(str1);
	puts(str2);
	
	char *s1 = str1,*s2 = str2;
	func24(&s1,s2,n,m);

	puts(s1);
	puts(str2);
	return 0;
}
```
</details>



## 25、编写一个函数，```void replace(char *str1,char* str2,int i, int j)```将字符串str1中的第i个字符开始到第j个字符结束的位置替换成str2

<details>
<summary>点击查看隐藏内容</summary>
```c
void replace(char* str1, char* str2, int i, int j)
{
	int k = 0, l = 0;
	k = j;
	char s0[100];
	while (str1[k] != '\0')
	{
		s0[l] = str1[k];
		k++, l++;
	}
	s0[l] = '\0';
	k = i - 1;
	l = 0;
	while (str2[l] != '\0')
	{
		str1[k] = str2[l];
		k++;
		l++;
	}
	l = 0;
	while (s0[l] != '\0')
	{
		str1[k] = s0[l];
		l++, k++;
	}
	str1[k] = '\0';
}
```
</details>

## 26、有一分数序列$\frac{2}{1},\frac{3}{2},\frac{5}{3},\frac{8}{5},\frac{13}{8},\cdots$求前20项之和

<details>
<summary>点击查看隐藏内容</summary>
```c
double func26()
{
	double n1 = 1.0, n2 = 2.0;
	double t, re = 0.0;
	for (int i = 0; i < 20; i++)
	{
		re += n2 / n1;
		//printf("%lf / %lf\n", n1, n2);
		t = n1;
		n1 = n2;
		n2 = n1 + t;
	}
	return re;
}
```
</details>

## 27、打印十行杨辉三角

<details>
<summary>点击查看隐藏内容</summary>
```c
void func27()
/*
打印10行杨辉三角
*/
{
	int n = 10;
	//行数
	int m = 2 * n + 1;
	//列数

	int** array = (int**)malloc(sizeof(int*));// [n] [m] = { 0 };
	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
		{
			array[i][j] = 0;
		}
	}

	//将每一行的两端元素值为1
	for (int i = 0; i < n; i++)
	{
		array[i][n + i + 1] = 1;
		array[i][n - i + 1] = 1;
	}

	//开始计算每一行的元素值
	for (int i = 2; i < n; i++)
	//第1、2行只有1，已经搞定了
	{
		for (int j = n-i+1; j < n +i+1; j+=2)
		{
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j + 1];
		}	
	}

	//输出语句
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (array[i][j])
			{
				if (array[i][j] / 100 != 0)
					printf("%d ", array[i][j]);
				else if (array[i][j] / 10 != 0)
					printf("%d  ", array[i][j]);
				else 
					printf("%d   ", array[i][j]);
			}
			else
				printf("    ");
		printf("\n");
	}
	printf("\n");
}
```
</details>

### 修改了一下格式

<details>
<summary>点击查看隐藏内容</summary>
```c
void func27()
/*
打印10行杨辉三角
*/
{
	int n = 10;
	//行数
	int m = 2 * n + 1;
	//列数

	int** array = (int**)malloc(sizeof(int*));// [n] [m] = { 0 };
	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
		{
			array[i][j] = 0;
		}
	}

	//将每一行的两端元素值为1
	for (int i = 0; i < n; i++)
	{
		array[i][n + i + 1] = 1;
		array[i][n - i + 1] = 1;
	}

	//开始计算每一行的元素值
	for (int i = 2; i < n; i++)
	//第1、2行只有1，已经搞定了
	{
		for (int j = n-i+1; j < n +i+1; j+=2)
		{
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j + 1];
		}	
	}

	//输出语句
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (array[i][j])
			{
				if (array[i][j] / 100 != 0)
					printf("%.3d", array[i][j]);
				else if (array[i][j] / 10 != 0)
					printf("%.3d", array[i][j]);
				else
					printf("%.3d", array[i][j]);
			}
			else
				printf("   ");
		printf("\n");
	}
	printf("\n");
	
}
```
</details>

## 28、求解n阶多项式的值，多项式公式如下：

$$P_n(x)=
\left\{  
\begin{array}{lr}  
1, & n=0 \\ x, & n = 1\\ (2n-1)xP_{n-1}(x)-(n-1)P_{n-2}(x), & n >1  
\end{array}  
\right.$$



**注意**：小心溢出！

<details>
<summary>点击查看隐藏内容</summary>
```c
double func28(int n, double x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	return (2 * n - 1) * x * func28(n - 1, x) - (n - 1) * func28(n - 2, x);
}
```
</details>

## 【重难点题目】29、n个人围成一圈并按顺序编号，从第一个人开始报数，凡是报到3的人退出圈子，下一个人从1开始报数，求解最后退出圈子的成员的编号。

<details>
<summary>点击查看隐藏内容</summary>
```c
void func29(int n)
/*

*/
{
    //先创建和一个相同长度的动态数组用于遍历
	int* h = (int*)malloc(n * sizeof(int));
	
	//使用两个指针遍历数组，flag用于统计每三次报数遍历时已经退出的人数
	int i = 0, flag = 0, j = 1;
	
	//对这个数组进行初始化，每个元素的值值为编号（下标+1）
	for ( i = 0; i < n; i++)
	{
		h[i] = i+1;
	}
	
	//遍历指针初始化
	i = 0; j = 0;
	
	//当退出的人数不等于全部人数（即还有人在圈内未退出就继续遍历）
	while (flag != n)
	{
	   //当元素被置为0，表明已退出，flag指针+1
		if (h[i] == 0)
			flag++;
		//当遇到的第一个元素值不为0，则有人还未退出，flag指针置为0；开始报数遍历，j指针遍历报数
		if (h[i] != 0)
		{
			j++;
			flag = 0;
		}
		//报数遍历到第三个时，且判断是未退出的元素，再将其退出（置为0）
		//不判断一下元素值不为0的话会陷入死循环
		if (j % 3 == 0  && h[i] != 0)
		{
			printf("%d\n", h[i]);
			h[i] = 0;
			flag = 0;
			j = 0;
		}
		
		i++;
		i = i % n;
	}
}
```
</details>

## 30、设计算法求解$S_n=1-\frac{1}{2}+\frac{1}{3}-\frac{1}{4}+\frac{1}{5}\cdots+\frac{1}{n}$，求解当n=100时的值

<details>
<summary>点击查看隐藏内容</summary>
```c
void func30()
{
	int n = 100;
	double re = 1.0;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			re -= (1.0 / i);
		else
			re += (1.0 / i);
	}
	printf("%lf\n", re);
}
```
</details>

## 31、将字符串str1中下标为偶数的元素赋值给另外一个字符数组str2

<details>
<summary>点击查看隐藏内容</summary>
```c
void func31(char str1[],char str2[])
{
	int i = 1, j = 0;
	while (str1[i]!='\0')
	{
		str2[j] = str1[i];
		i += 2;
		j++;
	}
	str2[j] = '\0';
}
```
</details>

## 32、输入5个国家的英文名，按字母顺序排序

<details>
<summary>点击查看隐藏内容</summary>
```c
#include <stdio.h>
#include <string.h>

#define Number 5
#define Max_len 20

//如有必要自己写一个字符串比大小函数
//
//字符串交换函数

void func32(char n[][Max_len])
{
	for (int i = Number;i > 0;i--)
	{
		for (int j = 0;j < i-1;j++)
		if (strcmp(n[j],n[j+1]) > 0)
		{
			char tmp[Max_len];
			strcpy(tmp,n[j]);
			strcpy(n[j],n[j+1]);
			strcpy(n[j+1],tmp);
		}
	}
}

int main()
{
	char nation[Number][Max_len];
	
	printf("请一次输入%d个国家的英文名：\n",Number);
	for (int i = 0;i < Number;i++)
	{
		gets(nation[i]);
	}	

	puts("");
	func32(nation);
	for (int i = 0;i < Number;i++)
		puts(nation[i]);

	return 0;
}

```
</details>

## 33、有8个学生，每个学生选修了3门课程。学生的选修课分数记录为如些的结构体

```c
typedef struct CourseScore
{
	int ChineseScore;
	int MathScore;
	int EnglishScore;
	char StudentName[10];
}CourseScore,CourseScoreRecords[8];
```

计算每个学生的平均分，总分，每门课程的总分，最后根据每个学生的总分进行排名，输出总成绩前三的学生的信息。

**易错点：**
题目所给的CourseRecords类型是CourseScore这个结构的数组类型，所以在定义的时候不用加方括号，因为已经是一个长度为8的数组类型了。

<details>
<summary>点击查看隐藏内容</summary>
```c
void func33(CourseScoreRecords &stu, int sum_score[])
/*
最后根据总分对8名学生进行排名，且输出前三名的信息
*/
{
	for (int i = 0; i < stuNum; i++)
	{
		sum_score[i] = stu[i].ChineseScore + stu[i].EnglishScore + stu[i].MathScore;
	}
	for (int i = 0; i < stuNum-1; i++)
	{
		for (int j = 0; j < stuNum-i-1; j++)
		{
			if (sum_score[j] > sum_score[j + 1])
			{
				int tmp;
				CourseScore t;
				
				tmp = sum_score[j];
				sum_score[j] = sum_score[j + 1];
				sum_score[j + 1] = tmp;

				t = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = t;
			}
		}
	}
	int k = 0;
	while (k < 3)
	{
		printf("%d,学生信息：\n", k + 1);
		printf("语文成绩：%d\n", stu[stuNum - k - 1].ChineseScore);
		printf("数学成绩：%d\n", stu[stuNum - k - 1].MathScore);
		printf("英语成绩：%d\n", stu[stuNum - k - 1].EnglishScore);
		printf("总成绩：%d\n", sum_score[stuNum - k - 1]);
		k++;
	}
}
```
</details>	

采用了封装技术的写法：
<details>
<summary>点击查看封装类后的写法</summary>
```c
#include <stdio.h>

typedef struct CourseScore
{
	int ChineseScore;
	int MathScore;
	int EnglishScore;
	char StudentName[10];
}CourseScore,CourseScoreRecords[8];

typedef struct StudentScore
{
	CourseScore course_score;
    int sum_score;
    double average_score;
}StudentScore,StudentScoreRecords[8];

#define Number_Stu 8
#define Number_Course 3

void stu_sumScore(StudentScoreRecords stu)
{
    for (int i = 0;i < Number_Stu;i++)
    {
        stu[i].sum_score = 0.0;
        stu[i].sum_score += stu[i].course_score.ChineseScore;
        stu[i].sum_score += stu[i].course_score.EnglishScore;
        stu[i].sum_score += stu[i].course_score.MathScore;
    }
    
    return ;
}

void stu_average(StudentScoreRecords stu)
{
    for (int i = 0;i<Number_Stu;i++)
    {
        stu[i].average_score = stu[i].sum_score;
        stu[i].average_score /= Number_Course;
    }
    return ;
}

void sort_stu(StudentScoreRecords stu)
{
    //只需要前三个，故排序只需要前三趟
    for (int i = Number_Stu - 1;i > Number_Stu - 4;i--)
    {
        for (int j = 0;j < i;j++)
            if (stu[j].sum_score > stu[j+1].sum_score)
            {
                StudentScore tmp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = tmp;
            }
    }   
}

int main()
{
    StudentScoreRecords record = {{90,85,83,"Stu_1",0,0},{87,86,90,"stu_2",0,0}
    ,{98,99,95,"stu_3",0,0},{88,85,80,"stu_4",0,0},{81,80,83,"stu_5",0,0}
    ,{88,95,80,"stu_6",0,0},{98,95,80,"stu_7",0,0},{88,75,80,"stu_7",0,0}};
    
    stu_sumScore(record);
    stu_average(record);
    sort_stu(record);

    for (int i = Number_Stu - 1; i > Number_Stu - 4;i--)
    {
        printf("%d\n",i);
        printf("学生姓名：%s\n",record[i].course_score.StudentName);
        printf("总分：%d\n",record[i].sum_score);
        printf("三科平均分：%lf\n",record[i].average_score);
        printf("语文成绩：%d\n",record[i].course_score.ChineseScore);
        printf("英语成绩：%d\n",record[i].course_score.EnglishScore);
        printf("数学成绩：%d\n",record[i].course_score.MathScore);
    }
    
    return 0;
}
```
</details>