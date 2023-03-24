#ifndef TICTACTOE_H
#define TICTACTOE_H

using namespace std;

class TicTacToe {
	private:
		char board[3][3];
		int noOfMoves;
		list<int> emptyCells;
    public:
		TicTacToe(){
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					board[i][j] = ' ';
			noOfMoves = 0;

			for(int i = 0; i < 9; i++) {
				emptyCells.push_back(i);
			}
		}

        void displayBoard(); 
		bool isValidMove(int row, int col) const;
		// Return 'D' for draw 'C' for continue and 'X' or 'O' for win
    	char gameStatus();  
    	void addMove(char player,int row,int col);
    	void updateEmptyCells(int x, int y);
    	list<int> getEmptyCells() {
    		return emptyCells;
    	}
    	int getNoOfMoves() {
    		return noOfMoves;
    	}
    	char getChar(int i, int j) {
    		return board[i][j];
    	}
    	void removeMove(int row, int col);
};

void TicTacToe::removeMove(int row, int col) {
	board[row][col] = ' ';
}

void TicTacToe::updateEmptyCells(int x, int y) {
	emptyCells.remove(x*3+y);
}
/*********************************
Author: Prof. Dongmo Zhang (Western Sydney University)
Date: unknown
*/
void TicTacToe::displayBoard() {
	cout << "   1    2    3" << endl;
    cout << "  - - - - - - - -"<<endl;

	for (int row = 0; row < 3; row++) {
		cout << row + 1 <<"|";

		for (int col = 0; col < 3; col++) {
            if(col == 0)
                cout <<"";
			cout << setw(3) << board[row][col];

			//if (col != 2)
				cout << " |";
		}
		cout << endl;
		if (row != 2)
			cout << " |____|____|____|" << endl << " |    |    |    |" << endl;
	}
	cout << "  - - - - - - - -" << endl;
}
/*
*************************************/

bool TicTacToe::isValidMove(int row, int col) const {
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

char TicTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1])
				&& (board[row][1] == board[row][2]))
			return board[row][0];

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col])
				&& (board[1][col] == board[2][col]))
			return board[0][col];

	//Check diagonals for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2]))
		return board[0][0];

	if (board[2][0] != ' ' && (board[2][0] == board[1][1])
			&& (board[1][1] == board[0][2]))
		return board[2][0];

	if (noOfMoves < 9)
		return 'C';

	return 'D';
}

void TicTacToe::addMove(char player,int x,int y) {
	if(!isValidMove(x,y))
        return;

    board[x][y] = player;
    noOfMoves++;
    updateEmptyCells(x, y);
}

#endif
