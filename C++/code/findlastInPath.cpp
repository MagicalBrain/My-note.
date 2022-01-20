/*
* callback 4-1
* 使用函数指针是最简单的实现回调函数的方式
*/
#include <stdio.h>
#include <string.h>

int main ()
{
    char* pName = "D:\\aa\\bb\\cc\\da.jpg";
    char *pName1 = "C:\hy\HinYeun-FS\robotplugin-fs\URRobotPlugin"
    char *p = strrchr(pName, '\\');

    printf ("%s\n", p+1);
    return 0;
}
