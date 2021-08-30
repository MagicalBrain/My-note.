#include <winsock2.h>
#include <stdio.h>

//链接Windows的socket库
#pragma comment(lib, "ws2_32.lib")

int main() {
    SOCKET sockSrv;
    SOCKADDR_IN addrSrv;
    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    char msg[] = "Hello, world!";

    //初始化socket库
    WORD wVersionRequest = MAKEWORD(2, 2);
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequest, &wsaData);
    if (err != 0)
        return 1;

    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2) {
            //WSACleanup();
            goto cleanup2;
            return 1;
        }

    //创建用于监听的socket
    sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    if (sockSrv == -1) {
        //WSACleanup();
        goto cleanup2;
        return 1;
    }

    
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(6000);

    //绑定socket，监听端口6000
    if (bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == -1) {
        //closesocket(sockSrv);
        goto cleanup1;
        //WSACleanup();
        goto cleanup2;
        return 1;
    }

    //启动监听，并准备接受客户端的请求
    if (listen(sockSrv, 15) == -1) {
        //closesocket(sockSrv);
        goto cleanup1;
        //WSACleanup();
        goto cleanup2;
        return 1;
    }

    
    

    while (true) {
        //等待客户端请求的到来
        SOCKET sockClient = accept(sockSrv, (SOCKADDR*) & addrClient, &len);
        if (sockClient == -1)
            break;
        
        //向客户端发送msg
        send(sockClient, msg, strlen(msg), 0);
        closesocket(sockClient);
    }

cleanup1:
    closesocket(sockSrv);
cleanup2:
    WSACleanup();
    return 0;
}
