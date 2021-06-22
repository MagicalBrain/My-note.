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

## 使用例子

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