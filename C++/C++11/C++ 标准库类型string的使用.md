# C++ 标准库类型string的使用

string是一种顺序容器，同vector很像，区别在于string专门用于保存字符。

## 包含的头文件

```cpp
#include <string>
using std::string;
```

## 定义和初始化string对象

```cpp
string s1;  //默认初始化，初始化一个空串
string s2(s1);  //s2是s1的一个副本
string s2 = s1;     //等价于s2(s1)
string s3("value");     //s3是字面值“value”的副本，除了最后的空字符外
string s3 = "value";    //等价于上面的语句，s3
string s4(n, 'c');      //s4初始化为由连续的n个字符'c'组成的串
```

## 直接初始化和拷贝初始化

**拷贝初始化**：
即使用`=`，将等号右侧的变量的值拷贝到新创建的对象中去。

**直接初始化**：
除了使用`=`的都是直接初始化

## string对象的操作

```cpp
os<<s              //将s写到输出流os当中，返回os
is>>s              //从is中读取字符串赋给s，字符串以空白分隔，返回is
getline (is, s)     //从is中读取一行赋给s，返回is
s.empty ()          //s为空返回true，否则返回false
s.size ()           //返回s中字符的个数
s[n]                //返回s中第n个字符的引用，位置n从0计起
sl+s2               //返回s1和s2连接后的结果
s1=s2               //用s2的副本代替s1中原来的字符
s1==s2              //如果s1和s2中所含的字符完全一样，则它们相等； string对象的相等性判断对字母的大小写敏感
s1!=s2              
<, <=, >,>=         //利用字符在字典中的顺序进行比较，且对字母的大小写敏感
```

### 读写string的操作

使用cin、cout

使用getline()读取一整行

**注意**：
触发getline()函数返回的换行符实际上被丢弃了，得到的string对象中并不包含该换行符。

### empty()和size()

### 比较string

可直接用`==` or `!=`运算符

### string的赋值

### string的相加

```cpp
string s4 = s1 + ", ";//正确：把一个string对象和一个字面值相加
string s5 ="hello" + "， "; //错误：两个运算对象都不是string
string s6 = sl + "， " + "world";   //正确：每个加法运算符都有一个运算对象是string
string s7 = ("hello" + "， ") + s2; //错误：不能把字面值直接相加
```

### 3.2.2节 练习

练习3.2:编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读）一个词。

练习3.3:请说明string类的输入运算符和getline函数分别是如何处理空白字符 的

练习3.4:编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串

练习3.5:编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。

## 处理string对象中的字符

```cpp
#include <cctype>
isalnum(c) //当c是字母或数字时为真
isalpha(c) //当c是字母时为真
iscntrl(c) //当c是控制字符时为真
isdigit(c) //当c是数字时为真
isgraph(c) //当c不是空格但可打印时为真
islower(c) //当c是小写字母时为真
isprint(c) //当c是可打印字符时为真（即c是空格或c具有可视形式）
ispunct(c) //当c是标点符号时为真（即c不是控制字符、数字、字母、可打印空白中的一种）
isspace(c) //当c是空白时为真（即c是空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种）
isupper(c) //当c是大写字母时为真
isxdigit(c) //当c是十六进制数字时为真
tolower(c)  //如果c是大写字母，输出对应的小写字母；否则原样输出c
toupper(c)  //如果c是小写字母，输出对应的大写字母；否则原样输出c
```

## 构造string的其他方法

```cpp
string cp, s2;
unsigned int n, len2, pos2;

string s(cp, n)             //s是cp指向的数组中前n个字符的拷贝。此数组至少应该包含n个字符
string s(s2, pos2)          //s是string s2从下标pos2开始的字符的拷贝。若pos2>s2.size （），构造函数的行为未定义
string s(s2, pos2, len2)    //s是string s2从下标pos2开始len2个字符的拷贝。若pos2>s2.size （） ，构造函数的行为未定义。不管len2的值是多少，构造函数至多拷贝s2.size （）-pos2个字符
```

## string格式化

格式化目前有3种方式：
1. C语言的标准输入输出库里的`snprintf()`
2. C++里的sstream库里的`stringstream`
3. boost库的`format`

### snprintf()

`snprintf()`是包含在`stdio.h`里的

代码如下：

```cpp
#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;
using std::string;

void test4snprintf(string input) {
    // 准备数据
    //string haha("haha");
    int num = 3;
    // 准备格式
    string fmt("test string: %s. test number: %d");
    char targetString[1024];
    // 格式化，并获取最终需要的字符串
    int realLen = snprintf( targetString, 
						sizeof(targetString), 
						fmt.c_str(), 
						input.c_str(), 
						num );
    cout << targetString << endl;
}
```

输入为：
```bash
hello,world
```

输出为：
```bash
test string: hello,world. test number: 3
```

### sstream

这种用法类似与cout那种输入输出流，只不过这里是格式化流
除了sstream，还可以用osstream，作用是一样的。

```cpp
#include <stdio.h>

#include <iostream>
#include <string>

#include <sstream>

using namespace std;

using std::stringstream;
using std::string;

void test4sstream(string input) {
    // 准备数据
    //string haha("haha");
    int num = 3;
    // 准备根据格式造字符串流
    stringstream fmt;                       /* 或者使用 ostringstream */
    // 造字符串流
    fmt << input << num;
    // 获取最终需要的字符串
    string targetString = fmt.str();
    cout << targetString << endl;
}

void test4osstream(string input) {
    int num = 3;
    // 准备根据格式造字符串流
    ostringstream fmt;
    // 造字符串流
    fmt << input << num;
    // 获取最终需要的字符串
    string targetString = fmt.str();
    cout << targetString << endl;
}
```
