# C++ 其它基本类型转char*

## float转char*

近日有需求将`cv::Point2f`转成char*

`cv::Point2f`其实就是一个特殊的数据结构

```cpp
cv::Point2f point;
point.x, point.y // 就是float类型的
```

### 测试代码

```cpp
// OpenCV-BasicType.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <typeinfo>

#include <opencv2/opencv.hpp>

int main()
{
    char str1[20], str2[20];
    
    std::cout << "Hello World!\n";
    cv::Point2f a(123, 456);

    std::cout << a.x << ", " << a.y << "\n";

    std::cout << sizeof(a.x) << ", " << sizeof(a.y) << "\n";

    std::cout << typeid(a.x).name() << ", " << typeid(a.y).name() << "\n";

    // 将float转为char*
    sprintf(str1, "%f", a.x);
    sprintf(str2, "%f", a.y);
    std::cout << str1 << ", " << str2 << "\n";

    //const char cstr1[20] = str1, cstr2[20] = str2;
    //char buffer[1024];
    //snprintf("%s%s", sizeof(buffer), str1, str2);

    std::string s1 = str1;
    std::string s2 = str2;

    std::stringstream ss;
    ss << s1 << "," << s2;
    std::cout << ss.str().c_str() << std::endl;

    char delims[] = ",";
    char* tmp = NULL;
    //do
    //{
    //    tmp = strtok(const_cast<char*>(ss.str().c_str()), delims);
    //    std::cout << tmp << std::endl;
    //} while (tmp == NULL);

    tmp = strtok(const_cast<char*>(ss.str().c_str()), delims);
    while (tmp != NULL) {
        printf("%s\n", tmp);
        tmp = strtok(NULL, delims);
    }

    return 0;
}

```
