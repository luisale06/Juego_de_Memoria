#include <iostream>
#include <vector>

#ifndef SERVERPROYECTO1_CARD_H
#define SERVERPROYECTO1_CARD_H

using namespace std;

class Card {
public:
    string type, address;
    //vector<char> binary_type;

    Card();

    string getType();
    void setType(string card_type);

    //void set_binaryType(string card_type);
};


#endif //SERVERPROYECTO1_CARD_H
