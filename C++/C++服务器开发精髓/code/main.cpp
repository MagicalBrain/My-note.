#include <winsock2.h>
#include <stdio.h>

#include <iostream>

#include "include/ServerSocket.h"



int main() {
    ServerSocket serverSocket;
    if (!serverSocket.DoInit()) {
        return 0;
    }
    std::cout << "DoInit" << std::endl;

    if (!serverSocket.DoBind("0.0.0.0", 6000)) {
        return 0;
    }
    std::cout << "DoBind" << std::endl;

    if (!serverSocket.DoListen(15)) {
        return 0;
    }
    std::cout << "DoListen" << std::endl;

    if (!serverSocket.DoAccept()) {
        return 0;
    }
    std::cout << "DoAccept" << std::endl;
    return 0;
}
