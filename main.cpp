#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <map>
#include <cstdlib>

#include "TicTacToe.h"
#include "BoardCoordinate.h"
#include "NineBoard.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"
#include "Game.h"

using namespace std;

const char P1_SYMBOL = 'X';
const char P2_SYMBOL = 'O';

Player *selectPlayer(char symbol)
{
    int player;
    do
    {
        cout << "Select player ('1' for HumanPlayer, '2' for RandomPlayer, '3' for SmartPlayer): " << endl;
        cin >> player;

        switch (player)
        {
        case 1:
            return new HumanPlayer(symbol);
        case 2:
            return new RandomPlayer(symbol);
        case 3:
            return new SmartPlayer(symbol);
        default:
            cout << "Invalid input. Please try again!" << endl;
        }
    } while (true);
}

int main()
{
    srand(time(0));

    Player *p1 = selectPlayer(P1_SYMBOL);
    Player *p2 = selectPlayer(P2_SYMBOL);

    Game game(p1, p2);
    game.play();

    delete p1;
    delete p2;
    return 0;
}
