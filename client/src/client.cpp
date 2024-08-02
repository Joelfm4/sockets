#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")



int main() {
    WSADATA wsaData;  // WSADATA is a structure that contains information about the Windows Sockets implementation. It will be filled with data by the WSAStartup function.
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2); // The MAKEWORD(2, 2) macro call creates a 16-bit value representing the version of Winsock that the program is requesting (2.2 in this case)

    //  Initialize the Winsock library
    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    if (wsaerr != 0) {
        std::cout << "The Winsock dll not found! \n";
    }
    else {
        std::cout << "The Winsock dll found!\n";
        std::cout << "The status: " << wsaData.szSystemStatus << '\n';
    }

    // Creating the socket
    SOCKET clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // (adress family, SOCK_STREAM for TCP or SOCK_DGRAM for UTP, int protocol) - Return an object in tocket format

    if (clientSocket == INVALID_SOCKET) {
        std::cout << "Error at socket(): " << WSAGetLastError() << '\n';
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "socket() is OK!" << '\n';
    }

    // Connect
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    InetPton(AF_INET, "127.0.0.1", &clientService.sin_addr);
    clientService.sin_port = htons(55555);
    if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
        std::cout << "Client: connect() - Failed to connect. \n";
        WSACleanup();
        return 0;
    }
    else {
        std::cout << "Client: connect() is OK. \n";
        std::cout << "Client: Can start sending and receiving data... \n";
    }

    // Send Data
    char buffer[200];

    std::cout << "Enter your message: ";
    std::cin.getline(buffer, 200);

    int byteCount = send(clientSocket, buffer, 200, 0);

    if (byteCount > 0) {
        std::cout << "Message sent: " << buffer << '\n';
        
    }
    else {
        WSACleanup();

    }

    system("pause");
    WSACleanup();
	return 0;
}