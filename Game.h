#ifndef GAME_H
#define GAME_H

#include "TicTacToe.h"

using namespace std;

class Game
{
private:
	TicTacToe board;
	NineBoard nBoards;
	BoardCoordinate currentBoard;
public:
	char play();
	bool masterCheckWin (char player, NineBoard board);
};

char Game::play()
{
	HumanPlayer p1('X');
	RandomPlayer p2('O');
	nBoards.displayBoards();
    bool done = false;
    char player = 'X';
    while(!done) {
        currentBoard = nBoards.getCurrent_boardCoord();
        board = nBoards.getBoard();
        int x = -1;
        int y = -1;
        if(player == 'X') {
            if(nBoards.getStatus(currentBoard.row, currentBoard.col) != 'C') {
                p1.selectBoard(nBoards, x, y);
                nBoards.setCurrentBoard(x, y);
                board = nBoards.getBoard();
            }
            p1.getMove(board, x, y);
            cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
            nBoards.addMove(player, x, y);
			nBoards.displayBoards();
			done = masterCheckWin(player, nBoards);
			player = 'O';
        }
        else {
            if(nBoards.getStatus(currentBoard.row, currentBoard.col) != 'C') {
                p2.selectBoard(nBoards, x, y);
                nBoards.setCurrentBoard(x, y);
                board = nBoards.getBoard();
            }
            p2.getMove(board, x, y);
            cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
            nBoards.addMove(player, x, y);
            nBoards.displayBoards();
            done = masterCheckWin(player, nBoards);
            player = 'X';
        }
    }
    return nBoards.gameStatus();
}

bool Game::masterCheckWin(char player, NineBoard board) {
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

#endif
