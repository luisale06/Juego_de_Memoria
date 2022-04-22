#include <iostream>
#include "Type.h"

using namespace std;

Type::Type(){}

int Type::getAmount()
{
    return amount;
}

void Type::setAmount(int card_amount)
{
    this->amount = card_amount;
}

string Type::getCategory()
{
    return category;
}

void Type::setCategory(string card_category)
{
    this->category = card_category;
}
