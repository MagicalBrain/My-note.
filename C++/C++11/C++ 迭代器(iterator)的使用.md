# C++ 迭代器(iterator)的使用

支持迭代器的类型都有返回迭代器的成员函数。

begin

end
返回的迭代器通常被称为尾后迭代器，没有实际意义，仅仅是个标记，表示已经处理完容器里所有的元素了。

如果容器为空，则begin和end返回的是同一个迭代器。

## 迭代器运算符

```cpp
*iter   //返回迭代器iter所指元素的引用
iter->mem   //访问iter所指向元素的名为mem的成员，等价于(*iter).mem
++iter  //令iter指示容器中的下一个元素
--iter  //令iter指示容器中的上一个元素

iterl == iter2 
iterl != iter2
/*
判断两个迭代器是否相等（不相等），如果两个迭代器指示的是同一个元素或者
它们是同一个容器的尾后迭代器，则相等；反之，不相等
*/
```

## 迭代器的运算

### vector和string类支持的迭代器运算

```cpp
iter + n
iter -n
iter1 += n
iter1 -=n
iter1 - iter2
< > <= >=
```

迭代器加上一个整数值仍得一个迭代器，迭代器指示的新位置与原来相比向前移动了若干个元素。结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置
迭代器减去一个整数值仍得一个迭代器，迭代器指示的新位置与原来相比向后移动了若干个元素。结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置
迭代器加法的复合赋值语句，将iter1加n的结果赋给iter1
迭代器减法的复合赋值语句，将iter1减n的结果赋给iterl
两个迭代器相减的结果是它们之间的距离，也就是说，将运算符右侧的迭代器向前移动差值个元素后将得到左侧的迭代器。参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一位置
迭代器的关系运算符，如果某迭代器指向的容器位置在另一个迭代器所指位置之前，则说前者小于后者。参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一位置

### 迭代器算术运算

#### 使用迭代器运算完成二分搜索

```cpp
// text必须是有序的
// beg和end表示我们搜索的范围
auto beg = text.begin(), end =text.end();
auto mid = text.begin() + (end-beg) / 2; //初始状态下的中间点
//当还有元素尚未检查并且我们还没有找到sought时执行循环
while (mid != end && *mid != sought) {
    if (sought < *mid) //我们要找的元素在前半部分吗？
        end = mid；
    //如果是，调整搜索范围使得忽略掉后半部分
    else
    //我们要找的元素在后半部分
        beg = mid + 1; //在mid之后寻找
    mid = beg + (end － beg) / 2;   //新的中间点
}
```

### 3.4.2节 练习

#### 练习3.24:请使用迭代器重做3.3.3节（第94页）的最后一个练习。

原练习：
读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int num;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (auto i = v.begin(), j = v.end() - 1; i < j; i++, j--)
    {
        cout << *i + *j << " ";
    }
    cout << endl;
    
    return 0;
}
```

#### 练习3.25: 3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。

原程序：
```cpp
//以10分为一个分数段统计成绩的数量： 0~9， 10~19，. ..， 90 ~ 99， 1000 
vector<unsigned> scores(11, 0); // 11个分数段，全都初始化为0
unsigned grade;
while (cin >> grade) {  //读取成绩
    if (grade <= 100)
    //只处理有效的成绩
    ++scores[grade / 10];
    //将对应分数段的计数值加1
}
```

输入数据:
```
42 65 95 100 39 67 95 76 88 76 83 92 76 93
```

输出：
```
0 0 0 1 1 0 2 3 2 4 1
```

修改后的程序：
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    //以10分为一个分数段统计成绩的数量： 0~9， 10~19，. ..， 90 ~ 99， 1000 
    vector<unsigned> scores(11, 0); // 11个分数段，全都初始化为0
    unsigned grade;
    while (cin >> grade) {  //读取成绩
        auto i = scores.begin();
        if (grade <= 100)
        //只处理有效的成绩
        *(i + (grade / 10)) += 1;
        //++scores[grade / 10];
        //将对应分数段的计数值加1
    }

    for (auto i : scores)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
```

#### 练习3.26:在100页的二分搜索程序中，为什么用的是mid=beg + （end-beg） / 2，而非mid= （beg + end） /2；?

## 使用迭代器的一个简单例子

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //使用迭代器来将字符串里的第一个单词转为大写
    string s;
    cin >> s;
    for (auto i = s.begin(); i != s.end() && !isspace(*i); i++)
    {
        *i = toupper(*i);
    }
    cout << s << endl;
    return 0;
}
```

## 迭代器的类型

一般来说我们在使用迭代器的过程中无需知道迭代器的类型。
所谓迭代器的类型有点类似`vector::size_type`的类型。

一般来说标准库定义的容器为了方便获取迭代器而无需考虑迭代器的类型，会有专门的`iterator`和`const_iterator`成员来表示迭代器的类型。

例如：
```cpp
vector<int> v;
v.begin();      //这个函数的返回的迭代器类型就是vector<int>::iterator 类型

const vector<int> v1;
v1.begin();     //这个函数的返回的迭代器类型就是vector<int>::const_iterator 类型
```

为了方便获取`const_iterator`类型的迭代器，有专门的`cbegin()`和`cend()`函数。

## 解引用和成员访问操作

解引用迭代器就可以访问迭代器指向的对象，如果该对象的类型是一个类，那么还可以访问其成员。

但是这里要小心：
```cpp
(*it).empty();      //对
*it.empty();        //错误
```

不加括号的时候，其实是访问it这一迭代器的名为empty的成员，可迭代器没有该成员。

有时候这种方式用起来不方便，为此C++还定义了剪头运算符，例如：
```cpp
it->empty();
```

注意：
凡事使用了迭代器的循环体，都不要向迭代器所属的容器添加元素。

## 3.4.1 节 练习

### 练习3.21:请使用迭代器重做3.3.3节（第94页）的第一个练习。

**iterator-checkVector.cpp**

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

static int cnt = 1;

bool vector_check(vector<int> v) {
    cout << "cnt: " << cnt++ << endl;
    if (v.size() < 1)
        return false;
    else {
        for (auto i = v.begin(); i != v.end(); i++)
            cout << *i << " ";
        cout << endl;
    }
    return true;
}

bool vector_check(vector<string> v) {
    cout << "cnt: " << cnt++ << endl;
    if (v.size() < 1)
        return false;
    else {
        for (auto i = v.begin(); i != v.end(); i++)
            cout << *i << " ";
        cout << endl;
    }
    return true;
}

int main() {
    //练习 3.13
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    //练习 3.21
    vector_check(v1);
    vector_check(v2);
    vector_check(v3);
    vector_check(v4);
    vector_check(v5);
    vector_check(v6);
    vector_check(v7);
    return 0;
}
```

输出结果：
```
cnt: 1
cnt: 2
0 0 0 0 0 0 0 0 0 0 
cnt: 3
42 42 42 42 42 42 42 42 42 42 
cnt: 4
10 
cnt: 5
10 42 
cnt: 6
          
cnt: 7
hi hi hi hi hi hi hi hi hi hi
```

### 练习3.22:修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后再输出它。

原程序：
```cpp
//依次输出text的每一行直至遇到第一个空白行为止
for (auto it = text.cbegin();
    it != text.cend () && !it->empty (); ++it) 
    cout << *it << endl;
```

修改后的完整可运行的程序：
**iterator-testToUpper.cpp**
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
using std::vector;
using std::string;

int main() {
    vector<string> text;
    string str;
    while (cin >> str) {
        text.push_back(str);
    }
    for (auto i = text.begin(); i != text.end() && !i->empty(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            *j = toupper(*j);
        }
        
    }
    cout << *text.begin() << endl;
    return 0;
}
```

### 练习3.23:编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main() {
    vector<int> v;
    int num;
    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    for (auto i = v.begin(); i != v.end(); i++)
    {
        *i = *i * 2;
    }
    
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;
    
    return 0;
}
```

