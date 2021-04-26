# 【PAT Basic】1004 成绩排名 (20 分)

## 题目描述

读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：

每个测试输入包含 1 个测试用例，格式为

第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
  ... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩

其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：

对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。

输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112

## 基本思路

使用结构题来进行存储并比较

## 代码

```c++
/*
* 1004题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
    char name[11];
    char id[11];
    int grade;
}stu;

int main() {
    int n;
    stu *s, max, min;
    
    max.grade = 0;
    min.grade = 100;
    
    scanf("%d", &n);       //输入学生的个数
    
    s = (stu*) malloc(n * sizeof(stu));
    for (int i = 0; i < n; i++)
    {
        //scanf("%s", s[i].name);
        //scanf("%s", s[i].id);
        gets(s[i].name);
        gets(s[i].id);
        scanf("%d", &s[i].grade);
        if (s[i].grade > max.grade)
            max = s[i];
        if (s[i].grade < min.grade)
            min = s[i];
    }
    
    printf("%s %s\n", max.name, max.id);
    printf("%s %s\n", min.name, min.id);
    return 0;
}
```

## 总结

这题比较简单，但是还是要注意字符串输入和其他输入的不同。
尤其是使用scanf函数进行输入，只有字符串是在变量名前不加&，其它类型的变量前都要加&
如果想要避免在这个问题上出错，可以用gets函数替代scanf函数来进行字符串的输入
