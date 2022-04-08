#include"Client.h"
#include<iostream>
#include<winsock2.h>

using namespace std;

Client::Client()
{
    cout << "Connecting to server... " << endl;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5001);
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
}

void Client::send(string message)
{
    for (int i = 0; i <= message.length(); i++)
    {
        this->buffer[i] = message[i];
    }

    ::send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    cout << "Message Sent!" << endl;
}

void Client::get()
{
    recv(server, buffer, sizeof(buffer), 0);
    cout << "Server says: " << buffer << endl;
    memset(buffer, 0, sizeof(buffer));
}

void Client::close()
{
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
}