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
        scanf("%s", s[i].name);
        scanf("%s", s[i].id);
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