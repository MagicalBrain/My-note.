# CSharp如何调用C++

## 基本流程

1. 创建一个C++的动态库项目，将要引用的C++代码放进去
2. 创建一个C#工程，调用DLL库

## 创建一个C++动态库项目

**头文件**：
```cpp
#pragma once
#include <iostream>

extern "C" _declspec(dllexport) int Add(int a, int b);

class MyClass
{
public:	
	MyClass();
	~MyClass();

private:

};
```

**源文件**：

@import "./code/DLL4CSharp/Add.cpp"

## 创建一个C#工程

调用C++代码的类：

@import "./code/DLL4CSharp/Test.cs"

Main类：

@import "./code/DLL4CSharp/Program.cs"

**主要代码**：

```csharp
class Test
    {
        [DllImport("DLL-CPP.dll", CallingConvention = CallingConvention.Cdecl)]
        extern static int Add(int a, int b);

        public static void test()
        {
            try
            {
                int a = 42;
                int b = 119;
                int c = Add(a, b);

                Console.WriteLine(c);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"ex:{ex}");
            }
        }
    }
```

----

```csharp
[DllImport("Calculate.dll", CallingConvention = CallingConvention.Cdecl)]
    extern static int Sum(int a, int b);
    public static void Main(string[] args) {
        try {
            Console.WriteLine("请输入NumberA:");
            int numberA = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("请输入NumberB:");
            int numberB = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine($"the numberA is:{numberA};numberB is:{numberB},The Sum is:{Sum(numberA, numberB)}");
        }
        catch(Exception ex) {
            Console.WriteLine($"ex:{ex}");
        }

        Console.ReadLine();
    }
```

## 参考链接

https://www.cnblogs.com/skyfreedom/p/11773597.html
https://www.cnblogs.com/skyfreedom/p/11783629.html
