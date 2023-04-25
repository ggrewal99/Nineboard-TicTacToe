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
	Player* player[2];
public:
    Game(Player* p1, Player* p2) {
        player[0] = p1;
        player[1] = p2;
    }
	char play();
	bool checkWin (char playerSymbol, NineBoard board);
};

char Game::play()
{
	nBoards.displayBoards();
    bool done = false;
    char playerSymbol = 'X';
    while(!done) {
        currentBoard = nBoards.getCurrent_boardCoord();
        board = nBoards.getBoard();
        int x = -1;
        int y = -1;
        if(playerSymbol == 'X') {
            while(nBoards.getStatus(currentBoard.row, currentBoard.col) != 'C') {
                player[0]->selectBoard(nBoards, x, y);
                nBoards.setCurrentBoard(x, y);
                currentBoard.row = x;
                currentBoard.col = y;
                board = nBoards.getBoard();
                cout << "X selects board (" << (x + 1) << "," << (y + 1) << ") " << endl;
            }
            if (player[0]->getName() == 'S')
                player[0]->getMove(nBoards, x, y);
            else
                player[0]->getMove(board, x, y);
            cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
            nBoards.addMove(playerSymbol, x, y);
			nBoards.displayBoards();
			done = checkWin(playerSymbol, nBoards);
			playerSymbol = 'O';
        }
        else {
            while(nBoards.getStatus(currentBoard.row, currentBoard.col) != 'C') {
                player[1]->selectBoard(nBoards, x, y);
                nBoards.setCurrentBoard(x, y);
                currentBoard.row = x;
                currentBoard.col = y;
                board = nBoards.getBoard();
                cout << "O selects board (" << (x + 1) << "," << (y + 1) << ") " << endl;
            }
            if (player[1]->getName() == 'S')
                player[1]->getMove(nBoards, x, y);
            else
                player[1]->getMove(board, x, y);
            cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
					<< endl;
            nBoards.addMove(playerSymbol, x, y);
            nBoards.displayBoards();
            done = checkWin(playerSymbol, nBoards);
            playerSymbol = 'X';
        }
/*
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "Board (" << (i + 1) << "," << (j + 1) << ") status: " << nBoards.getStatus(i, j) << "  ";
            }
            cout << endl;
        }
*/
    }
    return nBoards.gameStatus();
}

bool Game::checkWin(char playerSymbol, NineBoard board) {
    char gStatus = board.gameStatus();
    if (gStatus == playerSymbol) {
		cout << "Player " << playerSymbol<< " wins!" << endl;
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
