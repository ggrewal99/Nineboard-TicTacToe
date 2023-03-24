#ifndef GAME_H
#define GAME_H

#include "TicTacToe.h"

using namespace std;

class Game {
    private: 
        TicTacToe board;
    public:
        char play();
        bool checkWin(char player, TicTacToe board);
};

char Game::play() {
	MiniMaxPlayer p1('X');
	HumanPlayer p2('O');
    board.displayBoard();
    bool done = false;
    char player = 'X';
    while(!done) {
    	int x = -1;
		int y = -1;
		if (player == 'X') {
			p1.getMove(board, x, y);
			board.addMove(player, x, y);
			cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
			board.displayBoard();
			done = checkWin(player, board);
			player = 'O';
		} else {
			if(checkWin(player, board)) {
				done = true;
				continue;
			}
			p2.getMove(board, x, y);
			board.addMove(player, x, y);
			cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
			board.displayBoard();
			done = checkWin(player, board);
			player = 'X';
		}
    }
    return board.gameStatus();
}

/*********************************
Author: Prof. Dongmo Zhang (Western Sydney University)
Date: unknown
*/
bool Game::checkWin(char player, TicTacToe board) {
	char gStatus = board.gameStatus();
	if (gStatus == player) {
		cout << "Player " << player<< " wins!" << endl;
		return true;
	} else if (gStatus == 'D') {
		cout << "This game is a draw!" << endl;
		return true;
	} else if (gStatus != 'C') {
		return true;
	} else
		return false;
}
/*
*************************************/

#endif
