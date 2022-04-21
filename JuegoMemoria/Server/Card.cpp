#include <iostream>
#include <fstream>
#include <vector>
#include "Card.h"

using namespace std;

Card::Card(){}

string Card::getType()
{
    return type;
}

string Card::getAddress()
{
    return address;
}

void Card::setType(string card_type)
{
    this->type = card_type;
}

void Card::setAddress(string card_type)
{
    if (card_type == "G")
    {
        this->address = "Photos//Green.jpeg";
    }

    else if (card_type == "B")
    {
        this->address = "Photos//Blue.jpeg";
    }

    else if (card_type == "R")
    {
        this->address = "Photos//Red.jpeg";
    }

    else if (card_type == "Y")
    {
        this->address = "Photos//Yellow.jpeg";
    }

    else if (card_type == "O")
    {
        this->address = "Photos//Orange.jpeg";
    }
}

/*void Card::set_binaryType(string card_type) {
    if (card_type == "G") {
        ifstream image("Photos//Green.jpeg", ios::in | ios::binary);
        char ch;
        while (!image.eof()) {
            ch = image.get();
            this->binary_type.push_back(ch);
        }
        image.close();

        ofstream image2("Photos//Green2.jpeg", ios::out | ios::binary);
        char ch2;
        int i;
        while (i < this->binary_type.size()) {
            ch2 = this->binary_type[i];
            image2.put(ch2);
            i++;
        }
        image2.close();
    }
    if (card_type == "B") {
        ifstream image("Photos//Blue.jpeg", ios::in | ios::binary);
        char ch;
        while (!image.eof()) {
            ch = image.get();
            this->binary_type.push_back(ch);
        }
        image.close();

        ofstream image2("Photos//Blue2.jpeg", ios::out | ios::binary);
        char ch2;
        int i;
        while (i < this->binary_type.size()) {
            ch2 = this->binary_type[i];
            image2.put(ch2);
            i++;
        }
        image2.close();
    }
    if (card_type == "R") {
        ifstream image("Photos//Red.jpeg", ios::in | ios::binary);
        char ch;
        while (!image.eof()) {
            ch = image.get();
            this->binary_type.push_back(ch);
        }
        image.close();

        ofstream image2("Photos//Red2.jpeg", ios::out | ios::binary);
        char ch2;
        int i;
        while (i < this->binary_type.size()) {
            ch2 = this->binary_type[i];
            image2.put(ch2);
            i++;
        }
        image2.close();
    }
    if (card_type == "Y") {
        ifstream image("Photos//Yellow.jpeg", ios::in | ios::binary);
        char ch;
        while (!image.eof()) {
            ch = image.get();
            this->binary_type.push_back(ch);
        }
        image.close();

        ofstream image2("Photos//Yellow2.jpeg", ios::out | ios::binary);
        char ch2;
        int i;
        while (i < this->binary_type.size()) {
            ch2 = this->binary_type[i];
            image2.put(ch2);
            i++;
        }
        image2.close();
    }
    if (card_type == "O") {
        ifstream image("Photos//Orange.jpeg", ios::in | ios::binary);
        char ch;
        while (!image.eof()) {
            ch = image.get();
            this->binary_type.push_back(ch);
        }
        image.close();

        ofstream image2("Photos//Orange2.jpeg", ios::out | ios::binary);
        char ch2;
        int i;
        while (i < this->binary_type.size()) {
            ch2 = this->binary_type[i];
            image2.put(ch2);
            i++;
        }
        image2.close();
    }
}*/
