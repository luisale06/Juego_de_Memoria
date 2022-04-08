#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Card.h"
#include "Type.h"

using namespace std;

Board::Board()
{
    type0.setAmount(6);
    type1.setAmount(6);
    type2.setAmount(6);
    type3.setAmount(6);
    type4.setAmount(6);

    type0.setCategory("C0");
    type1.setCategory("C1");
    type2.setCategory("C2");
    type3.setCategory("C3");
    type4.setCategory("C4");
}

Card * Board::randomBoard()
{
    Type type_list[5] = {type0, type1, type2, type3, type4};
    int i = 0;
    srand(time(0));
    int random_number;

    while (i < 30)
    {
        random_number = (rand() % 5);
        //cout << "Random: " << random_number << endl;
        //cout << "Type Amount: " << type_list[random_number].getAmount() << endl;

        if (type_list[random_number].getAmount() != 0)
        {
            Card card = Card();
            card.setType(type_list[random_number].getCategory());
            this->card_list[i] = card;
            type_list[random_number].amount--;

            //cout << "Card" << i << " = " << card.getType() << endl;
            //cout << "Type" << random_number << " amount = " << type_list[random_number].getAmount() << endl;
            i++;
        }
    }

    return card_list;
}