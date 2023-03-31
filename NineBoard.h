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
        current_board = BoardCoordinate(row, col);
    }

    BoardCoordinate getCurrent_board() {
        return current_board;
    }
    TicTacToe getBoard() {
        return nBoards[current_board.row][current_board.col];
    }
    int getNoOfMoves() {
        return noOfMoves;
    }
    void displayBoards();
    void addMove(char player, int x, int y);
};

void NineBoard::displayBoards()
{
    cout << current_board.row + 1 << ", " << current_board.col + 1<< endl;
    for (int row = 0; row < 3; row++)
    {
        cout << "*****************" << endl;
        for (int col = 0; col < 3; col++)
        {
            cout << "Board (" << row + 1 << ", " << col + 1 << "): " << endl;
            if (current_board == BoardCoordinate(row, col))
            {
                cout << "(CURRENT)" << endl;
            }
            nBoards[row][col].displayBoard();
            cout << endl;
        }
    }
    cout << "*****************" << endl;

void NineBoard::addMove(char player, int x, int y) {
    int currentRow = current_board.row;
    int currentCol = current_board.col;
    if(nBoards[currentRow][currentCol].isValidMove(x, y)) {
        nBoards[currentRow][currentCol].addMove(player, x, y);
        current_board.row = x;
        current_board.col = y;
        noOfMoves++;
    }
}

#endif
