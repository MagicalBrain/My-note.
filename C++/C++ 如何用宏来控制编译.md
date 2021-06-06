# C++ 如何用宏来控制编译

目前在公司的代码中看到了一个有意思的应用，就是定义了一个宏来控制某个类的实现代码是否编译进库里面被调用

例子：
```cpp
class Is_Open TypeX {
public:
    int num;

    void TypeX() {}
}
```

随便写的一个简单的类的定义，我们可以通过在编译的时候定义`Is_Open`来控制是否添加这个类的定义进编译。

```
gcc src.cpp -o src -DIs_Open
```

利用`-DIs_Open`命令来定义`Is_Open`宏，使得`TypeX`的定义和实现被添加进编译。
