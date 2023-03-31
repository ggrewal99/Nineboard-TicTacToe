#ifndef GAME_H
#define GAME_H

#include "TicTacToe.h"

using namespace std;

class Game
{
private:
	TicTacToe board;
	NineBoard nBoards;
public:
	char play();
	bool checkWin(char player, NineBoard board);
};

char Game::play()
{
	HumanPlayer p1('X');
	RandomPlayer p2('O');
	nBoards.displayBoards();
    bool done = false;
    char player = 'X';
    while(!done) {
        BoardCoordinate currentBoard;
        currentBoard = nBoards.getCurrent_board();
        board = nBoards.getBoard();
        int x = -1;
        int y = -1;
        if(player == 'X') {
            p1.getMove(board, x, y);
            nBoards.addMove(player, x, y);
            cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
			nBoards.displayBoards();
            done = checkWin(player, board);
			player = 'O';
        }
        else {
            p2.getMove(board, x, y);
            nBoards.addMove(player, x, y);
            cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
            nBoards.displayBoards();
            done = checkWin(player, board);
            player = 'X';
        }
    }
    return board.gameStatus();
}
}
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
	} else {

	}
	return false;
}

#endif
