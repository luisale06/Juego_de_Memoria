#include"Server.h"
#include<iostream>
#include<winsock2.h>

using namespace std;

Server::Server()
{
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5001);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    cout << "Listening... " << endl;
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << "Client connected!" << endl;
    }
}

string Server::get()
{
    recv(client, buffer, sizeof(buffer), 0);
    cout << "Client says: " << buffer << endl;
    memset(buffer, 0, sizeof(buffer));
}

void Server::send(string message)
{
    for (int i = 0; i <= message.length(); i++)
    {
        this->buffer[i] = message[i];
    }
    ::send(client, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    cout << "Message sent!" << endl;
}

void Server::close()
{
    closesocket(client);
    cout << "Socket closed." << endl;
}