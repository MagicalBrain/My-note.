# C++ 如何获取文件目录的最后一级

这里的内容得结合boost库里的获取目录来看。

## strrchr

这个函数是C标准库函数里的

```cpp
#include <stdio.h>
#include <string.h>

int main ()
{
    char* pName = "D:\\aa\\bb\\cc\\da.jpg";
    char *p = strrchr(pName, '\\');

    printf ("%s\n", p+1);
    return 0;
}

```
