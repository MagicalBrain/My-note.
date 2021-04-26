# C++ 计时函数

标签（空格分隔）： C++

---

## timeGetTime() 函数

### 头文件
```<Windows.h>```

**注意：**
include头文件后，还要在文件头加上
```c++
#pragma comment( lib,"winmm.lib" )
```

### 用法
```c++
    DWORD Start = timeGetTime();    //记录开始的时间
	Sleep(1000);    //等待1秒
	DWORD End = timeGetTime();      //记录结束时间
	cout << Start - End << endl;    //计算并输出
```

## 使用例子

比较递归与迭代的时间复杂度

```c++
#pragma comment( lib,"winmm.lib" )
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>

using namespace std;

#define Status int

#define OK 1


/**********
【题目】试写出求递归函数F(n)的非递归算法：
F(n) = n+1      当n=0
F(n) = nF(n/2)  当n>0
**********/
long F(long n)
/* 如果 n<0 则返回 -1 */
{
	//DWORD start = timeGetTime();
	if (n == 0)
		return n + 1;
	else if (n > 0)
		return (n*F(n / 2));
	else
		return -1;
}


long F0(long n)
/* 如果 n<0 则返回 -1 */
{
	int first, i, num,sum;
	int* f;
	f = (int*) malloc ((n) * sizeof(int));
	if (n < 0)
		return -1;
	if (n == 0)
		return n + 1;
	else
	{
		first = 1;
		num = 0;
		do
		{
			
			if ((num / 2) == 0)
			{
				num++;
				sum = first;
				f[num] = sum;
				
			}
			else
			{
				first = f[num / 2];
				sum = num * first;
				f[num] = sum;
			}
			num++;
		} while (num<=n);
	}
	return sum;
}

DWORD counttime()
{
	DWORD Start = timeGetTime();
	Sleep(1000);
	DWORD End = timeGetTime();
	cout << Start - End << endl;
	return Start - End;
}


int main()
{
	int fib_k(int a, int k);
	Status Fibonacci(int k, int m, int &f);
	DWORD s = counttime();
	int a = 20;
	int k = 3;
	DWORD start = timeGetTime();

	int re = fib_k(a, k);
	cout <<  re << endl;
	
	DWORD end01 = timeGetTime();
	cout << "用时："  << (double)(start - end01) / s << endl;

	int f;
	Fibonacci(a, k, f);
	cout << f << endl;

	DWORD end02 = timeGetTime();
	cout << "用时：" << (double)(start - end01 - end02) / s<<endl;
	
	

	return 0;
}  


int fib_k(int a, int k)
{
	int re = 0;
	if (a < k - 1)
		return 0;
	else if (a == k - 1)
		return 1;
	else
	{
		for (int i = 1; i <= k; i++)
			re += fib_k(a - i, k);
		return re;
	}
}

Status Fibonacci(int m, int k, int &f)
/* 求k阶斐波那契序列的第m项的值f */
{
	int i, j;
	if (k < 2 || m < 0)
		return	ERROR;

	if (m < k - 1)
	{
		f = 0;
		return OK;
	}
	if (m == k || m == k - 1)
	{
		f = 1;
		return OK;
	}
	else
	{
		int* l;
		l = (int*)malloc(k * sizeof(int));

		for (i = 0; i < k - 1; i++)
			l[i] = 0;

		l[k - 1] = 1;

		for (i = k; i < m; i++)
		{
			for (j = k - 1; j > 0; j--)
			{

				int tmp = l[j];
				l[j] = l[j - 1];
				l[j - 1] = tmp;
			}


			int v = 0;
			for (j = 0; j < k; j++)
				v += l[j];

			l[k - 1] = v;

			f = 0;
			for (j = 0; j < k; j++)
				f += l[j];

		}
	}
	return OK;
}
```


