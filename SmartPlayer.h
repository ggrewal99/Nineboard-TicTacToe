#ifndef SMART_PLAYER_H
#define SART_PLAYER_H

using namespace std;

class SmartPlayer: public Player {
private:
    char thisPlayer;
    char otherPlayer;
    map<char, int> scores;
    int minimax(NineBoard boards, int depth, int alpha, int beta, bool isMaximizing);
public:
    SmartPlayer(char p) : Player(p) {
        name = 'S';
        if(player == 'X'){
        	otherPlayer = 'O';
        	scores['X'] = 1;
			scores['O'] = -1;
			scores['D'] = 0;
        }
        else {
        	otherPlayer = 'X';
        	scores['X'] = -1;
        	scores['O'] = 1;
        	scores['D'] = 0;
        }
    }
    void getMove(TicTacToe board, int& row, int& col){}
    void getMove(NineBoard boards, int& row, int& col);
    void selectBoard(NineBoard boards, int& row, int& col);
};

void SmartPlayer::getMove(NineBoard boards, int& row, int& col){
    TicTacToe board;
    board = boards.getBoard();
    BoardCoordinate currentBoard;

    int bestScore = -999;

	if(board.getNoOfMoves() == 1 && board.isValidMove(1, 1)) {
		row = 1;
		col = 1;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board.isValidMove(i, j)) {
                currentBoard = boards.getCurrent_boardCoord();
				boards.addMove(player, i, j);
				int score = minimax(boards, 0, -999, 999, false);
				//board.removeMove(currentBoard.row, currentBoard.col, i, j);
				if (score > bestScore) {
					bestScore = score;
					row = i;
					col = j;
				}
			}
		}
	}
}

int SmartPlayer::minimax(NineBoard boards, int depth, int alpha, int beta, bool isMaximizing) {
    TicTacToe board;
    board = boards.getBoard();
    BoardCoordinate currentBoard;
    currentBoard = boards.getCurrent_boardCoord();
    char status = boards.gameStatus();
	if(status != 'C') {
		return scores[status];
	}
	else if (depth == 5)
        return 0;
	if(isMaximizing) {
		int bestScore = -999;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if(board.isValidMove(i, j)) {
					boards.addMove(player, i, j);
					//currentBoard = boards.getCurrent_boardCoord();
					int score = minimax(boards, depth+1, alpha, beta, false);
					//board.removeMove(currentBoard.row, currentBoard.col, i, j);
					bestScore = max(score, bestScore);
					alpha = max(alpha, bestScore);
					if (beta <= alpha)
                        break;
				}
			}
		}
		return bestScore;
	}
	else {
		int bestScore = 999;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if(board.isValidMove(i, j)) {
					boards.addMove(otherPlayer, i, j);
					//currentBoard = boards.getCurrent_boardCoord();
					int score = minimax(boards, depth+1, alpha, beta, true);
					bestScore = min(score, bestScore);
					//board.removeMove(currentBoard.row, currentBoard.col, i, j);
					beta = min(beta, bestScore);
					if(beta <= alpha)
                        break;
				}
			}
		}
		return bestScore;
	}
}

void SmartPlayer::selectBoard(NineBoard boards, int& row, int& col){
    int bestScore = -999;
    BoardCoordinate coordinates;
    for (int masterRow = 0; masterRow < 3; masterRow++) {
        for (int masterCol = 0; masterCol < 3; masterCol++) {
                if(boards.getStatus(masterRow, masterCol) != 'C')
                    continue;
                TicTacToe board;
                board = boards.getBoard(masterRow, masterCol);
                int score = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    //cout << "Board char: " << board.getChar(i, j) << endl;
                    if(board.getChar(i, j) == player) {
                        score++;
                    }
                    if (score > bestScore) {
                        bestScore = score;
                        coordinates.row = masterRow;
                        coordinates.col = masterCol;
                    }
                }
            }
        }
    }
    row = coordinates.row;
    col = coordinates.col;
}


/* WIP MINIMAX ALGORITHM FOR SELECTING A BOARD

* INSIDE THE MINIMAX FUNCTION
    bool boardSelect = false;
    if(boards.getStatus(currentBoard.row, currentBoard.col) != 'C') {
        if(!boardSelect) {
            boardSelect = true;
            cout << "selecting board.." << endl;
            selectBoard(boards, currentBoard.row, currentBoard.col);
            boards.setCurrentBoard(currentBoard.row, currentBoard.col);
            board = boards.getBoard();
        }
    }


* selectBoard() function
    int bestScore = -999;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(!boards.isBoardFull(i, j) && boards.boardStatus(i, j) == 'C') {
                int score = minimax(boards, 0, -999, 999, false);
                if(score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
*/

#endif // SMART_PLAYER_H
