#include <iostream>
#include "Card.h"
#include "Type.h"

#ifndef SERVERPROYECTO1_BOARD_H
#define SERVERPROYECTO1_BOARD_H


class Board {
public:
    Type type0, type1, type2, type3, type4;
    Card card_list[30];

    Board();
    Card * randomBoard();
};


#endif //SERVERPROYECTO1_BOARD_H
