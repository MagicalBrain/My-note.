#pragma once
#include <winsock2.h>
#include <stdio.h>

//链接Windows的socket库
#pragma comment(lib, "ws2_32.lib")

class ServerSocket
{
public:
    ServerSocket();
    ~ServerSocket();

    //初始化winsocket库
    bool DoInit();

    bool DoBind(const char* ip, short port = 6000);

    bool DoListen(int backlog = 15);

    bool DoAccept();

private:
    bool m_bInit;
    SOCKET m_ListenSocket;
};

