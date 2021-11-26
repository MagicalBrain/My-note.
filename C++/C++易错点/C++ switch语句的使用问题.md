# C++ switch语句的使用问题

`case:`后面定义变量编译不通过问题

解决方案：
加花括号

```cpp
switch () {
    case :
    {
        int a = 1;
        break;
    }
}
```
