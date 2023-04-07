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
#include "MiniMaxPlayer.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));
    Player* p1 = new HumanPlayer('X');
    Player* p2 = new RandomPlayer('O');
	Game game(p1, p2);
	game.play();

    delete p1;
    delete p2;
	return 0;
}
