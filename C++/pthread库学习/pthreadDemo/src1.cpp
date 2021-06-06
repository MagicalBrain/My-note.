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
        delete num;
    }

    //结束线程
    for (int i = 0; i < 3; i++)
        pthread_join(id[i], NULL);

    delete id;
    return 0;
}