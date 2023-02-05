/*
* 1025题 代码存档
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node {
    int address;
    int data;
    int next;
} Node;
//改自大佬解法
int main() {
    int beginAddr, N, K;
    scanf("%d %d %d", &beginAddr, &N, &K);
    int beginIndex = 0;

    Node node[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &node[i].address, &node[i].data, &node[i].next);
        if (node[i].address == beginAddr) {
            beginIndex = i;
        }
    }

    //交换第一个节点
    if (beginIndex != 0) {
        Node tmp = node[0];
        node[0] = node[beginIndex];
        node[beginIndex] = tmp;
    }

//    连接剩余节点
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (node[j].address == node[i - 1].next) {
                Node c;
                c = node[i];
                node[i] = node[j];
                node[j] = c;
                break;
            }
        }
//        为何不加此句 会错一个用例？ 因为如果next为-1 ，则与后面的节点断开连接的，所以实际有效的节点数就变成了N=i+1
        if (node[i].next == -1) {
            N = i + 1;
//            printf("N=%d\n", N);
        }
    }

    int m = 0, n = 0;
    //反转链表 , 只交换节点位置，不去改变其中的next值，否则就把简单问题复杂化了，而且时间复杂度也会增加
    for (int i = 0; i < N / K; i++) {
        for (int j = 0; j < K / 2; j++) {
            Node c;
            m = K * i + j;
            n = K * (i + 1) - j - 1;
            c = node[m];
            node[m] = node[n];
            node[n] = c;
        }
    }
    //printf("-----\n");
    for (int i = 0; i < N - 1; i++) {
        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
    }
    printf("%05d %d -1\n", node[N - 1].address, node[N - 1].data);
    return 0;
}