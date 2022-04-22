#include <iostream>

#ifndef SERVERPROYECTO1_TYPE_H
#define SERVERPROYECTO1_TYPE_H

using namespace std;

class Type {
public:
    int amount;
    string category;

    Type();
    int getAmount();
    void setAmount(int card_amount);
    string getCategory();
    void setCategory(string card_category);
};


#endif //SERVERPROYECTO1_TYPE_H
