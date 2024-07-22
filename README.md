# Sockets

The goal of this project is to learn more about sockets with WSA (Windows sockets API)

## Windows Sockets API WSA
The Windows Sockets API WSA consists of a collection of functions, data structures and conventions. WSA provides standard access to the network services of an underlying protocol stack to any Windows application.

## OSI (Open Systems Interconnect)
The Open Systems Interconnect (OSI) is a network reference model that presents an overview of all network systems. It reduces the complex subject of networking into its essential components, and illustrates how these components interact with each other in a common framework.



![OSI](images/WinsockNetworkModel.jpg)


![OSI](images/osuLayer.png)

OSI - TEMPLATE

SOCKETS - EXPLATION

How will work

THE SERVER CODE EXPLATION - Each line

http://diranieh.com/SOCKETS/Concepts

## Server Functions

1. **Initialize WSA**: `WSAStartup()`
2. **Create a Socket**: `socket()`
3. **Bind the Socket**: `bind()`
4. **Listen for Connections**: `listen()`
5. **Accept a Connection**: `accept()`
6. **Send and Receive Data**: `send()`, `recv()`, `sendto()`, `recvfrom()`
7. **Disconnect**: `closesocket()`


## Client Functions

1. **Initialize Winsock**: `WSAStartup()`
2. **Create a Socket**: `socket()`
3. **Connect to the server**: `connect()`
4. **Send and Receive Data**: `send()`, `recv()`, `sendto()`, `recvfrom()`
5. **Disconnect**: `closesocket()`