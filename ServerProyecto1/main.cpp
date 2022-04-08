#include <iostream>
#include <winsock2.h>
#include "Server.h"
#include "Card.h"
#include "Board.h"

using namespace std;

int main()
{
    Server Servidor = Server();
    Board board = Board();
    Card *card_list;

    card_list = board.randomBoard();

    for (int i = 0; i < 30; i++) {
        cout << i << " " << card_list[i].getType() << endl;
    }


    while(true)
    {
        Servidor.get();
    }
}
