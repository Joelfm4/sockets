#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


int main(){
    WSADATA wsaData;  // WSADATA is a structure that contains information about the Windows Sockets implementation. It will be filled with data by the WSAStartup function.
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2); // The MAKEWORD(2, 2) macro call creates a 16-bit value representing the version of Winsock that the program is requesting (2.2 in this case)

    //  Initialize the Winsock library
    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    if(wsaerr != 0){
        std::cout << "The Winsock dll not found! \n";
    }else{
        std::cout << "The Winsock dll found!\n";
        std::cout << "The status: " << wsaData.szSystemStatus << "\n";
    }

    // Creating the socket
    SOCKET serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // (adress family, SOCK_STREAM for TCP or SOCK_DGRAM for UTP, int protocol) - Return an object in tocket format

    if(serverSocket == INVALID_SOCKET){
        std::cout << "Error at socket(): " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }else{
        std::cout << "socket() is OK!" << "\n";
    }

    // Bind the socket
    sockaddr_in service;
    service.sin_family = AF_INET;

    InetPton(AF_INET, "127.0.0.1", &service.sin_addr);

    int port = 5555;
    service.sin_port = htons(port);


    if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR){
        std::cout << "bind() failed: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }else{
        std::cout << "bind() is OK!\n";
    }



    WSACleanup();
    closesocket(serverSocket);

    return 0;
}


// cmake .. -G "MinGW Makefiles"

// g++ -Wall -Wextra -g3 server.cpp -o output\server.exe -lws2_32
