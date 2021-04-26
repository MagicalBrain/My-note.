/*
* 1024题 代码存档
*/
#include<stdio.h>
#include<string.h>
 
int main()
{
	char ch[50000] = {};
	scanf("%s",ch);
	
	int count = 0;
	int len =strlen(ch);
	int move = 0;						//需移动
	int mark1 = 0;
	for(int i = len-1 ; i >= 0; i--)	//计算E后面的位数	
	{
		if('+' == ch[i])
			mark1 = 1;
		if('-' != ch[i] && '+' != ch[i])
		{
			count++;
			if(1 == count)
				move += ch[i] - '0';
			else
			{	
				int n = 1;
				for(int j = 1 ; j < count ; j++)
				{
					n *= 10;
				}
				move += (ch[i]-'0') * n;
			}
		}
		else
			break;
	}	
	char ch1[50000] = {};	//不带小数点
	char ch2[50000] = {};	//带小数点
	int n1 = 0,n2 = 0;
	for(int i = 1; i < len ; i++)	//提取值
	{
		ch2[n2++] = ch[i];
		if('.' != ch[i])
		{
			if('E' == ch[i])
			{
				ch2[n2-1] = '\0';
				ch1[n1] = '\0';
				break;
			}
			else
				ch1[n1++] = ch[i];
		}
 
	}
	int zero = 0;	//为0时直接输出0
	for(int i = 0 ; '\0' != ch1[i] ; i++)
	{
		if('0' != ch1[i])
			zero++;
	}
	if(0 == zero)
	{
		printf("0\n");
		return 0;
	}
 
	if('-' == ch[0])
		printf("-");
	char resu[50000] = {};
	if(0 == move)	//当指数为0
	{
		printf("%s",ch2);
		return 0;
	}
	else if(mark1)	//当指数为正
	{
		int l = strlen(ch1) - 1;
		if(move >= l)
		{
			int n = l+1;
			strcpy(resu,ch1);
			for(int i = 0 ; i < move - l ; i++)
			{
				resu[n++] = '0';
			}
			resu[n] = '\0';
		}
		else
		{
			for(int i = 0 ; move > 0 ; i++)
			{
				char temp = 0;
				if('.' == ch2[i])
				{
					temp = ch2[i];
					ch2[i] = ch2[i+1];
					ch2[i+1] = temp;
					move--;
				}
			}
			strcpy(resu,ch2);
		}
		int n = 0;
		for(int i = 0 ; '\0' != resu[i] ; i++)
		{
			if('0' == resu[i])
			{
				if('.' == resu[i+1] || '0' != resu[i])
					break;
				else
					n++;
			}
			else
				break;
		}
		for(int i = n ; '\0' != resu[i] ; i++)
			printf("%c",resu[i]);
	}
	else		//当指数为负
	{
		int n = 2;
		resu[0] = '0';
		resu[1] = '.';
		for(int i = 1 ; i < move ; i++)
		{
			resu[n++] = '0';
		}
		for(int i = 0 ; '\0' != ch1[i];i++)
		{
			resu[n++] = ch1[i];	
		}
		resu[n] = '\0';	
		printf("%s",resu);
		return 0;
	}
	return 0;	
}