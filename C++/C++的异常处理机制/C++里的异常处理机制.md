# C/C++里的异常处理机制

## cerr

```cpp
int a, b;

if (a != b)
    cerr << "Date must be refer to same value."<< endl;

cout << a + b << endl;
```

cerr与cout有点类似，只不过cerr在输出错误信息后就会终止程序。

## 使用throw直接抛出异常

```cpp
int a, b;

if (a != b)
    throw runtime_error("Date must be refer to same value.");

cout << a + b << endl;
```

解释：
如果a和b的值不一样，则会抛出`runtime_error`类型的异常，这是标准库异常类型的一种，定义在`stdexcept`头文件里

## 使用try语句捕获异常

```cpp
try {
    //todo
}
catch () {
    //headle
}
```

例如：
```cpp

```

## 5.6.3节 练习

练习5.23:编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

```cpp
int n, m;
cin >> n >> m;
cout << n / m << endl;
```

练习5.24:修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？

```cpp
int n, m;
try
cin >> n >> m;
if
cout << n / m << endl;
```


练习5.25:修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。
