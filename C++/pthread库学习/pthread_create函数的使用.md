# pthread_create函数的使用

## 功能简述

它的功能是创建线程（实际上就是确定调用该线程函数的入口点），在线程创建以后，就开始运行相关的线程函数。
pthread_create的返回值表示成功，返回0；表示出错，返回表示-1。

## 用法

```cpp
#include <pthread.h>
int pthread_create(
    pthread_t* restrict tidp,   //新创建的线程ID指向的内存单元。
    const pthread_attr_t* restrict attr,  //线程属性，默认为NULL
    void* (*start_rtn)(void *), //新创建的线程从start_rtn函数的地址开始运行
    void* restrict arg //默认为NULL。若上述函数需要参数，将参数放入结构中并将地址作为arg传入。
);
```

**tidp**
类型：`pthread_t*` pthread_t 是线程的id，无符号整型

**attr**
`const pthread_attr_t*`
https://blog.csdn.net/houzijushi/article/details/80978345

**start_rtn**
`*void`
线程的入口函数，即该线程要做的工作都在这个函数里面了

**arg**
`void*`
线程的入口函数如果有参数的后，则通过这个指针来传参

**注意**：
restrict是C语言的限定符，用于告诉编译器，该指针指向的内容除了该指针外不允许访问和修改。

## 例子

```cpp
#include <iostream>
#include <pthread.h>

//定义了三个线程入口函数
void* func01(void* num) {
    std::cout << "Func01 is running." << std::endl;
    return NULL;
}

void* func02(void* num) {
    int n = *(int*) num;
    //std::cout << "----------" << std::endl;
    std::cout << "Func02 is running." << std::endl;
    std::cout << "Num is " << n << std::endl;
    return NULL;
}

void* func03(void* date) {
    int *num = (int*) date;
    //std::cout << "----------" << std::endl;
    std::cout << "Func03 is running." << std::endl;
    std::cout << "Sum is " << num[0] + num[1]  << std::endl;
    return NULL;
}

int main() {
    //创建3个线程
    pthread_t *id = new pthread_t[3];

    std::cout << "----------" << std::endl;
    std::cout << "Func01:" << std::endl;
    for (int i = 0; i < 3; i++)
        pthread_create(&id[i], NULL, func01, NULL);

    //结束线程
    for (int i = 0; i < 3; i++)
        pthread_join(id[i], NULL);

    std::cout << "----------" << std::endl;
    std::cout << "Func02:" << std::endl;

    for (int i = 0; i < 3; i++)
        pthread_create(&id[i], NULL, func02, &i);

    //结束线程
    for (int i = 0; i < 3; i++)
        pthread_join(id[i], NULL);

    std::cout << "----------" << std::endl;
    std::cout << "Func03:" << std::endl;

    for (int i = 0; i < 3; i++) {
        int *num = new int[2];
        for (int j = 0; j < 2; j++)
            num[j] = i + j;
        
        pthread_create(&id[i], NULL, func03, num);
        //delte
    }

    //结束线程
    for (int i = 0; i < 3; i++)
        pthread_join(id[i], NULL);

    delete id;
    return 0;
}
```

输出结果；
```
----------
Func01:
Func01 is running.
Func01 is running.
Func01 is running.
----------
Func02:
Func02 is running.
Num is 1
Func02 is running.
Num is 2
Func02 is running.
Num is 3
----------
Func03:
Func03 is running.
Sum is 1
Func03 is running.
Sum is 3
Func03 is running.
Sum is 5
```

这只是其中一种结果，结果本身是不可预测的，可能是乱序打印的：
```
----------
Func01:
Func01 is running.
Func01 is running.
Func01 is running.
----------
Func02:
Func02 is running.
Func02 is running.
Num is Num is 2
3
Func02 is running.
Num is 3
----------
Func03:
Func03 is running.
Sum is 1
Func03 is running.
Sum is 5
Func03 is running.
Sum is 3
```
