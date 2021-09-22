# C++如何使用宏来区别程序运行的操作系统

## 系统宏

```cpp
int main()
{
	//系统宏
#ifdef __ANDROID__
	string port("/dev/ttyUSB1");
#elif __linux__
	string port("/dev/ttyUSB0");
#elif _WIN32
	string port("Com3");
#endif
}
```

## 编译器宏

```cpp
int main()
{
	//编译器宏
#ifdef _MSC_VER
	cout << "hello MSVC" << endl;
#elif __GNUC__
	cout << "hello gcc" << endl;
#elif __BORLANDC__
	cout << "hello Borland c++" << endl;
#endif
}
```

## 测试源代码

Macro
