#include <iostream>
#include <winsock2.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include "Card.h"
#include "Type.h"

using namespace std;

void originalBoard(string * original_cards);
string toNumber(string type);
void randomBoard(Card * card_list, string * original_cards, int total_cards, int card_selected1, int card_selected2, bool start);
void Verify(Card * card_list, string * original_cards, string * addresses, int card_selected1, int card_selected2);
void binaryCards();

int main() {
    //Socket Initialization
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5001);
    bind(server, (SOCKADDR *) &serverAddr, sizeof(serverAddr));
    listen(server, 0);
    char buffer[200000];
    int clientAddrSize = sizeof(clientAddr);
    srand(unsigned (time(nullptr)));
    int card1, card2, total = 30, turn = 1, scoreP1 = 0, scoreP2 = 0;
    string match, str_card1, str_card2;
    string original_cards[30];
    originalBoard(original_cards);


    while (true) {
        cout << "._._._._._._._._._._._._._._._._._._._._._._._._._._." << endl;
        if ((client = accept(server, (SOCKADDR *) &clientAddr, &clientAddrSize)) != INVALID_SOCKET) {

            (turn % 2 == 0) ? cout << "Player 2 Turn" << endl : cout << "Player 1 Turn" << endl;

            //Receive Info
            recv(client, buffer, sizeof(buffer), 0);
            card1 = buffer[0];
            card2 = buffer[1];
            memset(buffer, 0, sizeof(buffer));
            cout << original_cards[card1] << original_cards[card2] << endl;

            if (original_cards[card1] == original_cards[card2])
            {
                match = "1";
                if (turn % 2 == 0)
                {
                    scoreP2 += 1;
                }
                else
                {
                    scoreP1 += 1;
                }
                total -= 2;
            }
            else
            {
                match = "0";
            }

            cout << "Player 1 Points: " << scoreP1 << endl;
            cout << "Player 2 Points: " << scoreP2 << endl;
            str_card1 = toNumber(original_cards[card1]);
            str_card2 = toNumber(original_cards[card2]);
            buffer[0] = str_card1[0];
            buffer[1] = str_card2[0];
            buffer[2] = match[0];

            send(client, buffer, sizeof(buffer), 0);
            memset(buffer, 0, sizeof(buffer));

            //Close Socket
            closesocket(client);

            (turn % 2 == 0) ? cout << "Player 2 Turn Finished" << endl : cout << "Player 1 Turn Finished" << endl;
            turn += 1;

            if (total == 0)
            {
                (scoreP1 > scoreP2) ? cout << "Winner Player 1" << endl : cout << "Winner Player 2" << endl;
                exit(1);
            }
        }
    }
}

void originalBoard(string * original_cards)
{
    Type type0, type1, type2, type3, type4;

    type0.setAmount(6);
    type1.setAmount(6);
    type2.setAmount(6);
    type3.setAmount(6);
    type4.setAmount(6);

    type0.setCategory("G");
    type1.setCategory("B");
    type2.setCategory("R");
    type3.setCategory("Y");
    type4.setCategory("O");

    Type type_list[5] = {type0, type1, type2, type3, type4};

    int i = 0;
    int random_number;

    while (i < 30)
    {
        random_number = (rand() % 5);

        if (type_list[random_number].getAmount() != 0)
        {
            original_cards[i] = type_list[random_number].getCategory();
            type_list[random_number].amount--;
            i++;
        }
    }
}

string toNumber(string type)
{
    if (type == "G")
    {
        return "0";
    }

    else if (type == "B")
    {
        return "1";
    }

    else if (type == "R")
    {
        return "2";
    }

    else if (type == "Y")
    {
        return "3";
    }

    else if (type == "O")
    {
        return "4";
    }
}

void randomBoard(Card * card_list, string * original_cards, int total_cards, int card_selected1, int card_selected2, bool start)
{
    int memory_cards = total_cards / 3;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int random_number;
    int random_positions[memory_cards];
    int card_list_amount[30];
    Card card_list_tmp[30];

    while (cont1 < 30)
    {
        card_list_amount[cont1] = 1;
        cont1++;
    }

    while (cont2 < memory_cards)
    {
        random_number = (rand() % 30);

        if (card_list_amount[random_number] == 1)
        {
            random_positions[cont2] = random_number;
            card_list_amount[random_number] = 0;
            cont2 ++;
        }
    }

    if (!start)
    {
        original_cards[card_selected1] = "";
        original_cards[card_selected2] = "";
    }

    while (cont3 < memory_cards)
    {
        Card card = Card();
        card.setType(original_cards[random_positions[cont3]]);
        card_list_tmp[random_positions[cont3]] = card;
        cont3++;
    }

    for (int i; i < 30; i++)
    {
        card_list[i] = card_list_tmp[i];
    }
}

void Verify(Card * card_list, string * original_cards, string * addresses, int card_selected1, int card_selected2)
{
    int selected_cards[2] = {card_selected1, card_selected2};

    for (int i = 0; i < 2; i++)
    {
        Card *card_ptr;
        card_ptr = &card_list[selected_cards[i]];
        if (card_ptr == nullptr)
        {
            Card card = Card();
            card.setType(original_cards[selected_cards[i]]);
            card.setAddress(original_cards[selected_cards[i]]);
            card_list[selected_cards[i]] = card;
        }
    }

    addresses[0] = card_list[card_selected1].getAddress();
    addresses[1] = card_list[card_selected2].getAddress();
}

void binaryCards()
{
    ifstream imageG("Photos//Green.jpeg", ios::in | ios::binary);
    ofstream binaryG("Photos//Binary_Green.dat", ios::out | ios::binary);
    char chG;
    while (!imageG.eof())
    {
        chG = imageG.get();
        binaryG.put(chG);
    }
    imageG.close();
    binaryG.close();


    ifstream imageB("Photos//Blue.jpeg", ios::in | ios::binary);
    ofstream binaryB("Photos//Binary_Blue.dat", ios::out | ios::app);
    char chB;
    while (!imageB.eof())
    {
        chB = imageB.get();
        binaryB.put(chB);
    }
    imageB.close();
    binaryB.close();


    ifstream imageR("Photos//Red.jpeg", ios::in | ios::binary);
    ofstream binaryR("Photos//Binary_Red.txt", ios::out | ios::app);
    char chR;
    while (!imageR.eof())
    {
        chR = imageR.get();
        binaryR.put(chR);
    }
    imageR.close();
    binaryR.close();


    ifstream imageY("Photos//Yellow.jpeg", ios::in | ios::binary);
    ofstream binaryY("Photos//Binary_Yellow.txt", ios::out | ios::app);
    char chY;
    while (!imageY.eof())
    {
        chY = imageY.get();
        binaryY.put(chY);
    }
    imageY.close();
    binaryY.close();


    ifstream imageO("Photos//Orange.jpeg", ios::in | ios::binary);
    ofstream binaryO("Photos//Binary_Orange.txt", ios::out | ios::app);
    char chO;
    while (!imageO.eof())
    {
        chO = imageO.get();
        binaryO.put(chO);
    }
    imageO.close();
    binaryO.close();

    //______________________________________//

    ifstream binaryG2("Photos//Binary_Green.dat", ios::in | ios::binary);
    ofstream imageG2("Photos//Green2.jpeg", ios::out | ios::binary);
    char chG2;
    while (!binaryG2.eof())
    {
        chG2 = binaryG2.get();
        imageG2.put(chG2);
    }
    imageG2.close();
    binaryG2.close();


    ifstream binaryB2("Photos//Binary_Blue.dat", ios::in | ios::binary);
    ofstream imageB2("Photos//Blue2.jpeg", ios::out | ios::binary);
    char chB2;
    while (!binaryB2.eof())
    {
        chB2 = binaryB2.get();
        imageB2.put(chB2);
    }
    imageB2.close();
    binaryB2.close();


    ifstream binaryR2("Photos//Binary_Red.txt", ios::in | ios::binary);
    ofstream imageR2("Photos//Red2.jpeg", ios::out | ios::binary);
    char chR2;
    while (!binaryR2.eof())
    {
        chR2 = binaryR2.get();
        imageR2.put(chR2);
    }
    imageR2.close();
    binaryR2.close();

    ifstream binaryY2("Photos//Binary_Yellow.txt", ios::in | ios::binary);
    ofstream imageY2("Photos//Yellow2.jpeg", ios::out | ios::binary);
    char chY2;
    while (!binaryY2.eof())
    {
        chY2 = binaryY2.get();
        imageY2.put(chY2);
    }
    imageY2.close();
    binaryY2.close();

    ifstream binaryO2("Photos//Binary_Orange.txt", ios::in | ios::binary);
    ofstream imageO2("Photos//Orange2.jpeg", ios::out | ios::binary);
    char chO2;
    while (!binaryO2.eof())
    {
        chO2 = binaryO2.get();
        imageO2.put(chO2);
    }
    imageO2.close();
    binaryO2.close();
}