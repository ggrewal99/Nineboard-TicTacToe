#ifndef NINE_BOARD_H
#define NINE_BOARD_H

#include "TicTacToe.h"
#include "BoardCoordinate.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class NineBoard
{
private:
    TicTacToe nBoards[3][3];
    BoardCoordinate current_board;
    int noOfMoves;

public:
    NineBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                nBoards[i][j] = TicTacToe();
            }
        }
        int row = rand() % 3;
        int col = rand() % 3;
        noOfMoves = 0;
        char status = 'C';
        current_board = BoardCoordinate(row, col, status);
    }

    BoardCoordinate getCurrent_boardCoord() {
        return current_board;
    }

    char getCurrent_boardStatus() {
        return current_board.status;
    }
    TicTacToe getBoard() {
        return nBoards[current_board.row][current_board.col];
    }
    int getNoOfMoves() {
        return noOfMoves;
    }
    void displayBoards();
    bool addMove(char player, int x, int y);
    char gameStatus();
    char getStatus(int row, int col) {
        return nBoards[row][col].getStatus();
    }
    bool isBoardFull(int row, int col) {
        return nBoards[row][col].isBoardFull();
    }
    void setCurrentBoard(int row, int col) {
        current_board.row = row;
        current_board.col = col;
    }
    char boardStatus(int x, int y) {
       return nBoards[x][y].gameStatus();
    }
};

void NineBoard::displayBoards()
{
    for (int bigRow = 0; bigRow < 3; bigRow++) {

		for (int row = 0; row < 3; row++)
    	{
    		if(row == 0) {
    			for (int i = 0; i < 3; i++) {
    				if(bigRow == current_board.row && i == current_board.col)
    					cout << "  * * * * * * * ";
    				else
    					cout << "  - - - - - - - ";
				}
    			cout << endl;
			}
        	for (int bigCol = 0; bigCol < 3; bigCol++)
        	{
           		for (int col = 0; col < 3; col++) {
           			if(col != 0)
           				cout << " ";
           			if(bigRow == current_board.row && bigCol == current_board.col && col == 0)
           				cout << "*";
           			else
           				cout << "|";
            		cout << setw(3) << nBoards[bigRow][bigCol].displayCell(row, col);
					if(col == 2)
            			cout << " ";
            	}
            	if(bigRow == current_board.row && bigCol == current_board.col)
            		cout << "*";
            	else
					cout << "|";
        	}
        	cout << endl;
        	if (row != 2)
				cout << "|____|____|____||____|____|____||____|____|____|" << endl << "|    |    |    ||    |    |    ||    |    |    |" << endl;
			if(row == 2) {
				for (int i = 0; i < 3; i++) {
    				if(bigRow == current_board.row && i == current_board.col)
    					cout << "  * * * * * * * ";
    				else
    					cout << "  - - - - - - - ";
				}
    			cout << endl;
			}

    	}
	}
}

bool NineBoard::addMove(char player, int x, int y) {
    int currentRow = current_board.row;
    int currentCol = current_board.col;
    if(nBoards[currentRow][currentCol].isValidMove(x, y)) {
        nBoards[currentRow][currentCol].addMove(player, x, y);
        nBoards[currentRow][currentCol].gameStatus();
        current_board.row = x;
        current_board.col = y;
        noOfMoves++;
    }
}

char NineBoard::gameStatus() {
    //Check rows for a win
	for (int row = 0; row < 3; row++)
		if ((nBoards[row][0].getStatus() != 'F' || nBoards[row][0].getStatus() != 'C') && (nBoards[row][0].getStatus() == nBoards[row][1].getStatus())
				&& (nBoards[row][1].getStatus() == nBoards[row][2].getStatus()))
			return nBoards[row][0].getStatus();

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if ((nBoards[0][col].getStatus() != 'F' || nBoards[0][col].getStatus() != 'C') && (nBoards[0][col].getStatus() == nBoards[1][col].getStatus())
				&& (nBoards[1][col].getStatus() == nBoards[2][col].getStatus()))
			return nBoards[0][col].getStatus();

	//Check diagonals for a win
	if ((nBoards[0][0].getStatus() != 'F' || nBoards[0][0].getStatus() != 'C') && (nBoards[0][0].getStatus() == nBoards[1][1].getStatus())
			&& (nBoards[1][1].getStatus() == nBoards[2][2].getStatus()))
		return nBoards[0][0].getStatus();

	if ((nBoards[2][0].getStatus() != 'F' || nBoards[2][0].getStatus() != 'C') && (nBoards[2][0].getStatus() == nBoards[1][1].getStatus())
			&& (nBoards[1][1].getStatus() == nBoards[0][2].getStatus()))
		return nBoards[2][0].getStatus();

	if (noOfMoves < 81)
		return 'C';

	return 'D';
}

#endif
