# qDebug的用法

## 头文件

```cpp
#include <QDebug>
```

## 基础用法

qDebug是用来在控制台输出数据的，类似于`std::cout`

```cpp
QString s = "Jack";
qDebug() << "My name is " << s << ", nice to meet you!" << endl;
qDebug("My name is " + s.toLatin1() + ", nice to meet you!\n");
```
