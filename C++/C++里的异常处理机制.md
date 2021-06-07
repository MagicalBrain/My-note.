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
