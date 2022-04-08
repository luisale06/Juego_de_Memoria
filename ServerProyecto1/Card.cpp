#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(){}

string Card::getType()
{
    return type;
}

void Card::setType(string card_type)
{
    this->type = card_type;
}