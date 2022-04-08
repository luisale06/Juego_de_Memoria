#include <iostream>

#ifndef SERVERPROYECTO1_CARD_H
#define SERVERPROYECTO1_CARD_H

using namespace std;

class Card {
public:
    string type;

    Card();
    string getType();
    void setType(string card_type);
};


#endif //SERVERPROYECTO1_CARD_H
