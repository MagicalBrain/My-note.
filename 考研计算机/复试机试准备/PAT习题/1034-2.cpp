/*
* 1034题 网上大佬代码 版本二 代码存档
*/
#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;
int quyu(long long a,long long b){
	if(b==0)
		return abs(a);//返回a的绝对值 
	quyu(b,a%b);
}//求最大公因数
string chan(long a,long b){
	string s;
	if(a==0)
		return "0";//如果分子为0，则返回数组0 
	long yu=quyu(a,b);//求最大公因 
	a/=yu;
	b/=yu;//化简到最简 
	stringstream ss;
	int flag=1;
	if(a<0){
		flag=-1;
		a=-a;
		ss<<"(-";
	}//如果小于0输出负号 
	long inte=a/b;
	long a0=a%b;
	if(inte!=0){
		ss<<inte;		
	}//输出整数 
	if(a0!=0){
		if(inte!=0)
			ss<<' ';
		ss<<a0;
		ss<<'/';
		ss<<b;
	}//输出分数 
	if(flag==-1){
		ss<<")";
	}//如果是负数，输出括号 
	getline(ss,s);//getline()函数用于读取文本中的一行内容
	return s;
}
int main()
{		
		long long a1,b1,a2,b2;//核心，以后没给取值范围的，全都写long long
		scanf("%lld/%lld%lld/%lld",&a1,&b1,&a2,&b2);//%ll为long long型输入 
		string s1,s2;
		long long yu;	
		if(a1!=0){
			yu=quyu(a1,b1);
			a1/=yu;
			b1/=yu;
		}//化简第一个数组 
		if(a2!=0){
			yu=quyu(a2,b2);
			a2/=yu;
			b2/=yu;
		}//化简第二个数组 
		s1=chan(a1,b1);
		s2=chan(a2,b2);
		string s3;
		long long a3,b3;
		a3=a1*b2+a2*b1;
		b3=b1*b2;
		s3=chan(a3,b3);
		cout<<s1<<" + "<<s2<<" = "<<s3<<endl;
		a3=a1*b2-a2*b1;
		b3=b1*b2;
		s3=chan(a3,b3);
		cout<<s1<<" - "<<s2<<" = "<<s3<<endl;
		a3=a1*a2;
		b3=b1*b2;
		s3=chan(a3,b3);
		cout<<s1<<" * "<<s2<<" = "<<s3<<endl;
		a3=a1*b2;
		b3=b1*a2;
		if(b3<0){
			a3=-a3;
			b3=-b3;
		}
		if(b3==0){
			cout<<s1<<" / "<<s2<<" = Inf"<<endl;	
		}else{
			s3=chan(a3,b3);
			cout<<s1<<" / "<<s2<<" = "<<s3<<endl;
		}
	return 0;
}

