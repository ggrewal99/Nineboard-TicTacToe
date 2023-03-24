#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <map>

#include "TicTacToe.h"
#include "NineBoard.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "MiniMaxPlayer.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));

	/* Run the games n number of times
		int noOfGames = 1000;
		int wins = 0;
		int losses = 0;
		int draws = 0;
		for(int i = 0; i < 1000; i++) {
			Game game;
			char result = game.play();
			cout << result << endl;
			if(result == 'X') {
				wins++;
			}
			else if(result == 'O') {
				losses++;
			}
			else {
				draws++;
			}
		}
		cout << "Wins: " << wins << endl;
		cout << "Losses: " << losses << endl;
		cout << "Draws: " << draws << endl;
	*/

	Game game;
	game.play();

	return 0;
}
