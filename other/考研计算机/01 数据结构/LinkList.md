# LinkList.h 的使用

## 包含的文件

### List.h

```c
#pragma once

#include <iostream>

using namespace std;

#define ElemType int
#define Initsize 20
#define Addsize 10

typedef struct
{
	ElemType *elem;
	int length;
	int size;
} SqList;

//基础函数
/*
基本操作函数里可能会用到的功能函数
*/
void input(SqList &L, int n[], int l)
{
	L.elem = n;
	L.length = l;
}



void output(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl << L.length << endl;
}

////拷贝函数：
/*
	将一个线性表里的所有数据元素按顺序拷贝到另外一个同数据元素类型的动态数组里去
*/
ElemType* ListCopy(SqList* L)
{
	ElemType* p;
	if (L->length > 0)
	{
		p = (ElemType*)malloc(L->size * sizeof(ElemType));

		for (int i = 0; i < L->length; i++)
		{
			p[i] = L->elem[i];
		}
		return p;
	}
	else
		return NULL;
}

//基本操作
////1、初始化线性表
void InitList(SqList *L)
{
	
	L->elem = (ElemType*)malloc(Initsize*sizeof(ElemType));
	L->length = 0;
	L->size = Initsize;
}

////2、求表长
int Length(SqList* L)
{
	if (L->elem == NULL)
		return 0;
	return L->length;
}

////3、按键值查找操作

int LocateElem(SqList* L,int e)
{
	int add = 0,l = Length(L);
	if (l > 0)
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] == e)
				return i;
		}
	}
	return -1;
}

////4、按位置查找操作

ElemType GetElem(SqList* L,int loca)
{
	int l = Length(L);
	if (loca <= l)
	{
		return L->elem[loca];
	}
	return -1;
}

////5、插入操作
/*
在指定位置插入元素
*/
void ListInsert(SqList* L,int e,int i)
{
	//特殊情况
	if (L->length >= Initsize)
	{
		ElemType* p,*t;
		t = (ElemType*)malloc((L->size + Addsize) * sizeof(ElemType));
		p = ListCopy(L);
		if (p == NULL)
		{
			cout << "重分配内存失败！" << endl;
			return;
		}

		L->elem = t;
		L->size += Addsize;

		for (int i = 0; i < L->length; i++)
		{
			L->elem[i] = p[i];
			//cout << L->elem[i] << " ";
		}
		//cout << endl;
	}
	//第一种情况（这个是为了创建线性表的时候用插入函数才写的，正常不用）
	if (L->length == 0)
	{
		L->elem[L->length] = e;
		L->length++;
	}
	//第二种情况
	else if (i == L->length)
	{
		L->elem[L->length] = e;
		L->length++;
		
	}
	//第三种情况
	else if (i < L->length && i >= 0)
	{
		for (int j = L->length-1; j >= i; j--)
		{
			L->elem[j + 1] = L->elem[j];
		}

		L->elem[i] = e;
		L->length++;
	}
	//第四种情况
	else
	{
		cout << "插入位置不合理！" << endl;
	}
}

////6、删除操作
/*
删除指定位置的元素，并返回该元素
*/
ElemType ListDelete(SqList* L,int n)
{
	int l = Length(L);
	ElemType e;
	if (n < l)
	{
		e = L->elem[n];

		for (int i = n+1; i < l; i++)
		{
			L->elem[i - 1] = L->elem[i];
		}
		L->length--;
		return e;
	}

	return -1;
}

////7、输出操作

void PrintList(SqList* L)
{
	if (L == NULL)
	{
		cout << "输出失败，线性表为空" << endl;
		return;
	}
	if (L->length > 0)
	{
		for (int i = 0; i < L->length; i++)
		{
			cout << L->elem[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "输出失败，线性表为空" << endl;
	}
}

////8、判空操作

bool IsEmpty(SqList* L)
{
	if (L->elem == NULL)
		return true;
	else
		return false;
}

////9、销毁操作
/*
销毁失败VS会抛出异常
*/
void DestroyList(SqList* L)
{
	if (L != NULL)
	{
		if (L->elem != NULL)
		{
			free(L->elem);
			L->length = 0;
			L->size = 0;
			cout << "销毁成功！" << endl;
		}
	}
	else
		cout << "销毁失败，线性表已销毁。" << endl;
}
```

### CreateFunction.h
```c
#pragma once
#include <iostream>
#include "List.h"
#include <time.h>
#include <windows.h>

using namespace std;

/*
TestFunction.h:
只放辅助测试函数
即用来测试的另外的一些操作，包括生成随机有序序列什么的
*/

//const int len = 80;

//生成随机数列函数
int* CreatRand(int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	cout << "输入随机数的个数" << endl;
	int n,len,tmp;
	cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n+1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n+1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n,int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int len, tmp;
	//cin >> n;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

int* CreatRand(int n,int len, int x)
/*
x:1，有序；0，无序。
输入数字n，生成n个随机元素的数组
*/
{
	int* p;
	//cout << "输入随机数的个数" << endl;
	int tmp;
	//cin >> n;
	//cout << "输入随机数的大小范围：" << endl;
	//cin >> len;

	p = (int*)malloc((n + 1) * sizeof(int));
	p[0] = n;

	cout << endl << "生成的随机数：" << endl;
	srand((unsigned int)time(0));
	for (int i = 1; i < n + 1; i++)
	{
		int re = rand();
		p[i] = re % len;
		cout << p[i] << " ";
	}
	cout << endl;

	if (x == 1)
	{
		for (int j = 1; j < p[0] + 1; j++)
		{
			for (int i = 1; i < p[0]; i++)
			{
				if (p[i] > p[i + 1])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}
			}
		}
		for (int i = 1; i <= p[0]; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}

	return p;
}

//创建线性表函数
void CreatList(SqList* L,int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p = NULL;
	switch (x)
	{
	case 1:
		p = CreatRand(1);
		break;
	case 0:
		p = CreatRand(0);
		break;
	default:
		p = NULL;
		break;
	}
	//p = CreatRand();

	int n = p[0];
	for (int i = 0; i < n; i++)
	{
		ListInsert(L, p[i+1], i);
	}
}

void CreatList(SqList* L1,SqList* L2,int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p1,* p2;
	switch (x)
	{
	case 1:
		p1 = CreatRand(1);
		p2 = CreatRand(1);
		break;
	case 0:
		p1 = CreatRand(0);
		p2 = CreatRand(0);
		break;
	default:
		p1 = NULL, p2 = NULL;
		break;
	}
	

	int n1 = p1[0],n2=p2[0];
	for (int i = 0; i < n1; i++)
	{
		ListInsert(L1, p1[i + 1], i);
	}
	for (int i = 0; i < n2; i++)
	{
		ListInsert(L2, p2[i + 1], i);
	}
}

void CreatList(SqList* L1,int l1, SqList* L2,int l2, int x)
/*
L:处理的线性表
x:1->有序；0->无序
*/
{
	int* p1, * p2,len;
	cout << "输入随机数的大小范围：" << endl;
	cin >> len;
	switch (x)
	{
	case 1:
		p1 = CreatRand(l1,len,1);
		Sleep(500);
		p2 = CreatRand(l2, 2*len, 1);
		break;
	case 0:
		p1 = CreatRand(l1, len, 0);
		Sleep(500);
		p2 = CreatRand(l2, 2*len, 0);
		break;
	default:
		p1 = NULL, p2 = NULL;
		break;
	}


	int n1 = p1[0], n2 = p2[0];
	for (int i = 0; i < n1; i++)
	{
		ListInsert(L1, p1[i + 1], i);
	}
	for (int i = 0; i < n2; i++)
	{
		ListInsert(L2, p2[i + 1], i);
	}
}



void CreatListF(SqList* L)
/*
L:处理的线性表
f: 重复元素的个数
*/
{
	int f;
	cout << "输入重复元素的个数：" << endl;
	cin >> f;

	if ( f > (L->length / 2))
	{
		int* p = NULL;

		p = CreatRand(0);

		int n = p[0];
		for (int i = 0; i < n; i++)
		{
			ListInsert(L, p[i + 1], i);
		}

		srand((unsigned int)time(0));
		int re = rand();
		int e = re % n;

		
		int k = p[e + 1];
		cout << k << endl;
		int loca;
		for (int i = 0; i < f; i++)
		{
			int re1 = rand();
			loca = re1 % n;
			ListInsert(L, k, loca);
		}
	}
	else
		cout << "参数错误！" << endl;
}
```

### TestFunction.h

```c
#pragma once

#include <iostream>
#include "List.h"
#include "CreatFuntion.h"
#include "func.h"

using namespace std;

/*
TestFunction.h
只放测试函数
*/

//测试基本操作函数

void test_LocateElem(SqList* L)
{
	int n, loca;
	cin >> n;
	loca = LocateElem(L, n);
	if (loca > -1)
	{
		cout << "找到了！" << endl;
		cout << "Location:" << loca << endl;
	}
	else
		cout << "未找到!" << endl;
}

void test_GetElem(SqList* L)
{
	int n;
	cin >> n;
	ElemType e;
	e = GetElem(L, n);
	if (e > -1)
	{
		cout << e << endl;
	}
	else
		cout << "位置无效！" << endl;
}

void test_ListInsert(SqList* L)
{

}

void test_ListDelete(SqList* L)
{
	int n;
	cin >> n;
	ElemType e = ListDelete(L, n);
	if (~e)
	{
		cout << e << endl;
	}
	else
		cout << "删除失败！" << endl;
}



//测试辅助函数
////为第8题写的测试辅助函数
SqList* testForfunc08(int l1, int l2)
{
	//int l1,l2;
	SqList* L1, * L2, * re;
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));
	re = (SqList*)malloc(sizeof(SqList));

	InitList(L1);
	InitList(L2);
	InitList(re);

	CreatList(L1, l1, L2, l2, 0);

	//l1 = Length(L1), l2 = Length(L2);
	if (l1 > 1 && l2 > 1)
	{
		for (int i = 0; i < l1; i++)
		{
			ListInsert(re, L1->elem[i], i);
		}
		for (int i = 0; i < l2; i++)
		{
			ListInsert(re, L2->elem[i], l1 + i);
		}
	}

	if (re != NULL)
		return re;
	return NULL;
}



//测试对应题目的函数

int test11()
{
	//先分配内存
	SqList* L0, * L1, * L2;
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L0);
	InitList(L1);
	InitList(L2);

	CreatList(L1, L2, 1);

	L0 = func07(L1, L2);

	cout << "L0:" << endl;
	PrintList(L0);

	cout << L0->length << "	中位数：" << L0->elem[L0->length / 2 - 1] << endl;
	cout << "序号：" << L0->length / 2 << endl;

	cout << "中位数： " << func11(L1, L2) << endl;

	cout << "L1:" << endl;
	PrintList(L1);
	cout << L1->length << endl;

	cout << "L2:" << endl;
	PrintList(L2);

	return 1;
}

int test12()
{
	//先分配内存
	SqList* L0, * L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);
	InitList(L1);
	InitList(L0);

	CreatListF(L);
	
	
	PrintList(L);
	cout << L->length << endl;

	int re = 0;
	re = func12(L);
	cout << "主元素为：" << re << endl;

	PrintList(L);

	//DestroyList(L);

	return 1;
}


int test13()
{
	//先分配内存
	SqList* L;
	L = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);

	CreatList(L,0);

	PrintList(L);
	cout << L->length << endl;

	int re;
	re = func13(L);
	cout << "最小正整数：" << re << endl;

	PrintList(L);
	cout << L->length << endl;

	//DestroyList(L);

	return 1;
}
```

### func.h

```c
#pragma once
#include <iostream>
#include "List.h"
#include "CreatFuntion.h"

using namespace std;

/*
func.h
对应于2020王道书上的P18页的习题的解决函数
*/

int func01(SqList* L)
/*
王道书 P18 第二章第二节 综合题1
*/
{
	int min, loca = 0, l = Length(L);

	if (l == 0)
	{
		cout << "该线性表为空，无法删除！（fun01）" << endl;
		return 0;
	}
	else
	{
		min = L->elem[0];

		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] < min)
			{
				min = L->elem[i];
				loca = i;
			}
		}

		ListDelete(L, loca);
		ListInsert(L, L->elem[l - 1], loca);
		L->length--;
		return 1;
		//cout<<""
	}
}

int func02(SqList* L)
/*
王道书 P18 第二章第二节 综合题2
*/
{
	int t;
	if (Length(L) < 1)
	{
		cout << "线性表为空！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < (Length(L) / 2); i++)
		{
			t = L->elem[i];
			L->elem[i] = L->elem[Length(L) - 1 - i];
			L->elem[Length(L) - 1 - i] = t;
		}
		return 1;
	}

}

int func03(SqList* L)
/*
王道书 P18 第二章第二节 综合题3
*/
{
	//int l = Length(L), t;
	int e;
	cout << "输入要删除的键值：" << endl;
	cin >> e;
	if (Length(L) < 1)
	{
		cout << "线性表为空！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < Length(L); i++)
		{
			if (L->elem[i] == e)
				ListDelete(L, i);
		}
		return 1;
	}
}

int func04(SqList* L)
/*
王道书 P18 第二章第二节 综合题4
*/
{
	int s, t, l = Length(L), p;
	cout << "输入要删除的元素值的范围：" << endl;
	cin >> s >> t;

	if (l < 1)
	{
		cout << "线性表长度不合理！" << endl;
		return 0;
	}
	else if (s >= t)
	{
		cout << "输入数值范围不合理！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] > s && L->elem[i] < t)
			{
				p = L->elem[i + 1];
				int n = 0;
				while (p > s && p < t)
				{
					ListDelete(L, i + 1 + n);
					n++;
					p = L->elem[i + 1 + n];
				}
				ListDelete(L, i);
			}
		}
	}
	return 1;
}

int func05(SqList* L)
/*
王道书 P18 第二章第二节 综合题5
*/
{
	int s, t, l = Length(L), p;
	cout << "输入要删除的元素值的范围：" << endl;
	cin >> s >> t;

	if (l < 1)
	{
		cout << "线性表长度不合理！" << endl;
		return 0;
	}
	else if (s >= t)
	{
		cout << "输入数值范围不合理！" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			if (L->elem[i] >= s && L->elem[i] <= t)
			{
				p = L->elem[i + 1];
				int n = 0;
				while (p >= s && p <= t)
				{
					ListDelete(L, i + 1 + n);
					n++;
					p = L->elem[i + 1 + n];
				}
				ListDelete(L, i);
			}
		}
	}
	return 1;
}

int func06(SqList* L)
/*
王道书 P18 第二章第二节 综合题6
*/
{
	int l = Length(L), num = 0, flag = 0;
	ElemType* p;

	if (l < 1)
	{
		cout << "线性表长度不合理" << endl;
		return 0;
	}
	else
	{
		p = (ElemType*)malloc(l * sizeof(ElemType));
		p[0] = L->elem[0];
		num = 1;


		for (int i = 1; i < l; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (L->elem[i] != p[j])
				{
					flag++;
				}
			}
			if (flag == num)
			{
				p[num] = L->elem[i];
				num++;
			}
			flag = 0;
		}


		for (int i = 0; i < num; i++)
		{
			L->elem[i] = p[i];
		}
		L->length = num;
	}
	return 1;
}

SqList* func07(SqList* L1, SqList* L2)
/*
王道书 P18 第二章第二节 综合题7
*/
{
	int l1 = Length(L1), l2 = Length(L2), num = 0;
	SqList* re;
	re = (SqList*)malloc(sizeof(SqList));

	InitList(re);

	if (l1 >= 1 && l2 >= 1)
	{
		int i = 0, j = 0;
		while (i < l1 && j < l2)
		{
			if (L1->elem[i] < L2->elem[j])
			{
				ListInsert(re, L1->elem[i], num);
				i++;
			}
			else
			{
				ListInsert(re, L2->elem[j], num);
				j++;
			}
			num++;
		}
		if (i < l1)
		{
			for (int k = i; k < l1; k++)
			{
				ListInsert(re, L1->elem[k], num);
				num++;
			}
		}
		else if (j<l2)
		{
			for (int k = j; k < l2; k++)
			{
				ListInsert(re, L2->elem[k], num);
				num++;
			}
		}

		return re;
	}

	return NULL;
}

int func08(SqList*L,int m,int n)
/*
王道书 P18 第二章第二节 综合题8
备注：算法逻辑应该是没问题的，但是不知道哪里出问题了，
一到main函数的return 0程序就会崩溃。
*/
{
	SqList* re;
	re = (SqList*)malloc(sizeof(SqList));
	InitList(re);

	if (L->length > 0 && m > 0 && n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			re->elem[i] = L->elem[m + i];
		}
		for (int i = 0; i < m; i++)
		{
			re->elem[n+i] = L->elem[i];
		}
		L = re;
		return 1;
	}

	return 0;
}

int func09(SqList* L,int e)
/*
王道书 P18 第二章第二节 综合题9
备注：
*/
{
	int l = Length(L),mid,flag=1;
	ElemType tmp;
	if (l > 0)
	{
		if (e > L->elem[l - 1])
		{
			ListInsert(L, e, l);
		}
		else if (e < L->elem[0])
		{
			ListInsert(L, e, 0);
		}
		else
		{
			mid = l / 2;
			while (flag)
			{
				if (e < L->elem[mid])
				{
					l = mid;
					mid = l / 2;
				}
				else if (e > L->elem[mid])
				{
					mid = (l + mid) / 2;
				}
				else if(e == L->elem[mid])
				{
					//flag = 0;
					tmp = L->elem[mid];
					L->elem[mid] = L->elem[mid + 1];
					L->elem[mid + 1] = tmp;
					break;
				}
				if (flag == Length(L))
				{
					ListInsert(L, e, l);
					break;
				}
				flag++;
				//break;
			}
			
		}
		return 1;
	}
	return 0;
}

int func10(SqList* L)
/*
王道书 P18 第二章第二节 综合题10
备注：
*/
{
	int l = Length(L),n,t;
	cout << "输入左移的位数：" << endl;
	cin >> n;
	if (l>0 && n>0)
	{
		for (int i = 0; i < n; i++)
		{
			t = ListDelete(L, l - 1);
			ListInsert(L, t, 0);
		}
		return 1;
	}
	cout << "左移失败！" << endl;
	return 0;
}

int func11(SqList* L1,SqList*L2)
/*
王道书 P18 第二章第二节 综合题11
备注：
*/
{
	int l1 = Length(L1), l2 = Length(L2);
	int re = 0, num = 0;

	if (l1 > 0 && l2 > 0)
	{
		int i = 0, j = 0;
		while (num<l1)
		{
			if (L1->elem[i] < L2->elem[j])
			{
				re = L1->elem[i];
				i++;
			}
			else
			{
				re = L2->elem[j];
				j++;
			}
			num++;
		}

		i--; j--;

		if (L1->elem[i]  < L2->elem[j])
		{
			re = L2->elem[j];
		}
		else
		{
			re = L1->elem[i];
			
		}
		
		return re;
	}

	return 0;
}

int func12(SqList* L)
/*
王道书 P18 第二章第二节 综合题12
备注：
*/
{
	int l = Length(L), num = 0, flag = 0;
	ElemType* p;

	if (l < 1)
	{
		cout << "线性表长度不合理" << endl;
		return 0;
	}
	else
	{
		p = (ElemType*)malloc(l * sizeof(ElemType));
		p[0] = L->elem[0];
		num = 1;

		for (int i = 1; i < l; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (L->elem[i] != p[j])
				{
					flag++;
				}
			}
			if (flag == num)
			{
				p[num] = L->elem[i];
				num++;
			}
			flag = 0;
		}

		for (int i = 0; i < num; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;

		ElemType* n = (ElemType*)malloc(num*sizeof(ElemType));
		//SqList* re = (SqList*)malloc(sizeof(SqList));

		for (int i = 0; i < num; i++)
		{
			n[i] = 0;
			for (int j = 0; j < l; j++)
			{
				if (p[i] == L->elem[j])
				{
					n[i]++;
				}
			}
			if (n[i] > l/2)
			{
				return p[i];
			}
		}
	}

	return -1;
}

int func13(SqList* L)
{
	int l = Length(L);

	if (l>0)
	{
		int min = 1, flag = 0;
		while (flag==0)
		{
			for (int i = 0; i < l; i++)
			{
				if (L->elem[i] == min)
				{
					flag++;
				}
			}
			if (flag)
			{
				min++;
				flag = 0;
			}
			else
				return min;
		}
		
		
		return 1;
	}
	return 0;
}

//有序顺序表求交集的函数 (该函数存在问题，输出结果不对！)
/*
SqList Jiao(SqList n1,SqList n2)
{
	SqList* re;
	ElemType* w;
	int n;
	if (n1.length > n2.length)
		n = n2.length;
	else
		n = n1.length;

	int k = 0;
	w = (ElemType*)malloc(n * sizeof(ElemType));

	re = (SqList*)malloc(sizeof(SqList));
	re->elem = w;
	//re->size = n;

	for (int i = 0; i < n1.length; i++)
	{
		for (int j = 0; j < n2.length; j++)
		{
			if (n1.elem[i] == n2.elem[j])
			{
				w[k] = n1.elem[i];
				k++;
				//re->length++;
			}

		}
	}

	re->length = k;

	return *re;
}

void test(int n1[],int n2[])
{
	//cout << sizeof(n1) / sizeof(int) << endl;
	SqList* L1, * L2;
	L1 = (SqList*)malloc(sizeof(SqList));
	L2 = (SqList*)malloc(sizeof(SqList));

	input(*L1, n1, sizeof(n1) / sizeof(int));
	input(*L2, n2, sizeof(n2) / sizeof(int));



	output(*L1);
	output(*L2);

	//Inv(*L);
	SqList re = Jiao(*L1, *L2);
	output(re);
}

int n1[] = {1,2,3,4,5,6,8,10,11};
int n2[] = { 1,2,3,4,5,7,9,10,11,12,13 };
*/
```

### main.cpp

```c++
#include <iostream>
#include "List.h"
#include "CreatFuntion.h"
#include "func.h"
#include "TestFunction.h"

using namespace std;

/*
main.cpp
只放测试函数和主函数
*/

int test()
{
	//先分配内存
	SqList* L0, * L, * L1;
	L = (SqList*)malloc(sizeof(SqList));
	L0 = (SqList*)malloc(sizeof(SqList));
	L1 = (SqList*)malloc(sizeof(SqList));

	//初始化线性表
	InitList(L);
	InitList(L1);
	InitList(L0);

	CreatList(L,L1,1);
	//CreatList(L,0);

	//cout << endl;
	//CreatRand1();
	//PrintList(L);
	//PrintList(L1);
	//PrintList(L1);
	//创建线性表并打印，结束

	//int l = Length(L);
	//cout << l << endl;

	//test_LocateElem(L);
	//test_GetElem(L);
	//test_ListDelete(L);
	
	/*
	int l1, l2;
	cout << "输入两线性表长度:" << endl;
	cin>>l1>>l2;
	L = testForfunc08(l1,l2);
	*/
	

	//func01(L);
	//func02(L);
	//func03(L);
	//func04(L);
	//func05(L);
	//func06(L);
	L0 = func07(L, L1);

	PrintList(L0);
	cout << L0->length << "	中位数：" << L0->elem[L0->length / 2 - 1] << endl;
	cout<<"序号："<< L0->length / 2 << endl;

	//func08(L, l1, l2);

	/*
	int n;
	cout << "输入查找键值：" << endl;
	cin >> n;
	func09(L, n);
	*/
	//func10(L);
	cout << "中位数： "<<func11(L, L1) << endl;

	cout << "L1:" << endl;
	PrintList(L);
	cout << L->length << endl;
	cout << "L2:" << endl;
	PrintList(L1);
	
	//DestroyList(L);

	return 1;
}

int main()
{
	test13();
	return 0;
}
```