# cmd程序运行卡住的解决办法

win上如果一个程序没有GUI，或者其本身就是一个cmd程序，那么就只能在cmd里运行。

但是在cmd里运行，有时候运行多次以后，输出信息或者打印日志会卡住，必须要输入一个回车才会继续运行。

## 原因

由于命令行窗口的快速编辑模式导致的

## 解决办法

在主函数开头加入以下几行代码：

```cpp
HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
DWORD mode;

GetConsoleMode(hStdin, &mode);

// 关闭快速编辑模式
mode &= ~ENABLE_QUICK_EDIT_MODE;
// 关闭插入模式
mode &= ~ENABLE_INSERT_MODE;
// 关闭鼠标输入？
mode &= ~ENABLE_MOUSE_INPUT;

SetConsoleMode(hStdin, mode);
```
