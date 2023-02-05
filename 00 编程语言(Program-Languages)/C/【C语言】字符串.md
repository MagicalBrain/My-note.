# C语言中的字符串

在C语言中，字符串是作为字符数组来处理的。

## 字符串的输入

### scanf

使用```scanf```函数来输入字符串数组
```c
char str[20];
for (int i = 0;i < 20; i++)
    scanf("%c",&str[i]);
```
以上是错误的做法，正确的做法应该是：
<details>
<summary>点击查看正确的做法<summary>
```c
char str[20];
scanf("%s",str);
```
其实scanf是将字符串数组当作字符串（字符指针）来处理的。
</details>

```c

```
### gets


## 字符串的输出

## 字符串结束标志

结束标志为```\0```

一般系统会自动添加结束标志。

```c
char str1[] = "I am a student.";
char str2[] = {'I',' ','a','m',' ','a', 's','t','u','d','e','n','t','.','\0'};

char str3[] = {'I',' ','a','m',' ','a', 's','t','u','d','e','n','t','.'};

//str1与str2是等价的，但是与str3是不等价的。
``` 

## 获取字符串的长度

### strlen函数

包含在```string.h```头文件里

1、如果我仅仅是给了一个字符串分配了空间，但未初始化，strlen函数还能够获取其长度吗？

代码：
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//如果我给了一个字符串分配了空间，但未初始化，strlen函数还能够获取其长度吗？
    char *s1;
    int n;
    puts("请输入正整数n：");
    scanf("%d",&n);

    printf("一个字符的大小是：%d\n",sizeof(char));
    s1 = (char*) malloc (n * sizeof(char));

    printf("输出字符串的长度:%d\n",strlen(s1));
    puts(s1);
	return 0;
}
```

输出结果：
macOS：
```
请输入正整数n：
10
一个字符的大小是：1
输出字符串的长度:0

```

ubuntu(Linux):
```
请输入正整数n：
10
一个字符的大小是：1
输出字符串的长度:0

```

二者运行结果一致，字符串长度均为0，即无法获取长度

2、初始化后就可以

代码
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//如果我给了一个字符串分配了空间，但未初始化，strlen函数还能够获取其长度吗？
    char *s1;
    int n;
    puts("请输入正整数n：");
    scanf("%d",&n);

    printf("一个字符的大小是：%d\n",sizeof(char));
    s1 = (char*) malloc (n * sizeof(char));

    gets(s1);
    printf("输出字符串的长度:%d\n",strlen(s1));
    puts(s1);
	return 0;
}
```