# C++ 文件输入输出

## 输出文本到文件

```c++
#include <iostream>
#include <fstream>

using namespace std;

ofstream Tree;
Tree.open("二叉树.dot");
Tree << "digraph G{" << endl;
```

## 从文本输入

```c++
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
fin.open("二叉树.dot");

if (!fin.is_open())
cout<<"文件打开失败！"<<endl;   //检查文件是否打开成功

fin >> num; //要输入的变量
```


