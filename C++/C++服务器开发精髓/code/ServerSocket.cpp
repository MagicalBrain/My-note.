#include "../include/ServerSocket.h"

ServerSocket::ServerSocket()
{
	m_bInit = false;
	m_ListenSocket = -1;
}

ServerSocket::~ServerSocket()
{
	if (m_ListenSocket != -1)
		::closesocket(m_ListenSocket);
	if (m_bInit)
		::WSACleanup();
}

//初始化winsocket库
bool ServerSocket::DoInit()
{
    
    WORD wVersionRequest = MAKEWORD(2, 2);
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequest, &wsaData);
    if (err != 0)
        return false;

    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2) {
        
        return false;
    }

    m_bInit = true;

    //创建用于监听的socket
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    if (sockSrv == -1) {
        
        return false;
    }
	
    return true;
}

//绑定socket，监听端口6000
bool ServerSocket::DoBind(const char* ip, short port)
{
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(port);

    
    if (bind(m_ListenSocket, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == -1) {
        
        return false;
    }
	
    return true;
}

bool ServerSocket::DoListen(int backlog)
{
    //启动监听
    if (listen(m_ListenSocket, backlog) == -1) {
        
        return false;
    }
	
    return true;
}

//准备接受客户端的请求
bool ServerSocket::DoAccept()
{
    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    char msg[] = "Hello, world!";

    while (true) {
        //等待客户端请求的到来
        printf("waiting ... \n");
        SOCKET sockClient = accept(m_ListenSocket, (SOCKADDR*)&addrClient, &len);
        if (sockClient == -1)
            break;

        //向客户端发送msg
        send(sockClient, msg, strlen(msg), 0);
        closesocket(sockClient);
    }
	return false;
}
