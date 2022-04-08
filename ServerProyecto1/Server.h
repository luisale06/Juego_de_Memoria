#ifndef SERVERPROYECTO1_SERVER_H
#define SERVERPROYECTO1_SERVER_H
#include <iostream>
#include <winsock2.h>

using namespace std;

class Server {
public:
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    string message = " ";
    string *messageptr = &message;
    char buffer[200000];

    Server();
    string get();
    void send(string message);
    void close();
};




#endif //SERVERPROYECTO1_SERVER_H