#ifndef PROYECTO_1_CLIENT_H
#define PROYECTO_1_CLIENT_H

#include<iostream>
#include<winsock2.h>
//#include"messageReader.h"

using namespace std;

class Client {
public:
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
    char buffer[200000];

    Client();
    void send(string message);
    void get();
    void close();
};


#endif //PROYECTO_1_CLIENT_H
