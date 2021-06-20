# C++ vector容器的使用

vector是一个表示对象的集合，其中所有的对象的类型都是相同的。

## 包含的头文件

```cpp
#include <vector>
using std::vector;
```

## vector的相关描述

vector实质是一个类模板。模板的定义比较考验个人对C++的理解，但运用不难。

模板本身不是类或函数，它应该被看作是编译器生成类或函数的一份说明书。

编译器根据模板创建类或函数的过程称为**实例化**，即当使用模板的时候应当告诉编译器应把类模板或函数模板实例化为哪种类型。

**注意**：vector里的对象类型仍然可以是vector，例如：
```cpp
vector<vector<int>> x;
```

这个定义仍然是合法的。

## vector的定义和初始化对象

vector支持的初始化方式有：
1. 列表初始化
2. 值初始化

## 练习题

### 3.3.1节 练习

练习3.12:下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的描述其执行结果；对于不正确的，说明其错误的原因。

（a） ```vector<vector<int>> ivec;```
（b） ```vector<string> svec = ivec;```
（c） ```vector<string> svec (10,＂null＂);```

都是正确的。

练习3.13:下列的vector对象各包含多少个元素？这些元素的值分别是多少？

（a） vector<int> v1；
（b） vector<int> v2（10）；
（c） vector<int> v3 （10， 42）；
（d） vector<int> v4｛10｝；
（e） vector<int> v5｛10， 42｝；
（f） vector<string> v6（10｝；
（g） vector<string> v7｛10， ＂hi＂｝；
