#include <iostream>
#include <winsock2.h>

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


    return 0;
}




// g++ -Wall -Wextra -g3 server.cpp -o output\server.exe -lws2_32
