#ifndef MINI_MAX_H
#define MINI_MAX_H

using namespace std;

class MiniMaxPlayer{
private:
    char player;
    char otherPlayer;
    map<char, int> scores;
    int minimax(TicTacToe board, int depth, bool isMaximizing);
public:
    MiniMaxPlayer(char p){
        player = p;
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
    void getMove(TicTacToe board, int& row, int& col);
};

void MiniMaxPlayer::getMove(TicTacToe board, int& row, int& col){
	int bestScore = -999;

	if(board.getNoOfMoves() == 2 && board.isValidMove(1, 1)) {
		row = 1;
		col = 1;
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board.isValidMove(i, j)) {
				board.addMove(player, i, j);
				int score = minimax(board, 0, false);
				board.removeMove(i, j);
				if (score > bestScore) {
					bestScore = score;
					row = i;
					col = j;
				}
			}
		}
	}
}

int MiniMaxPlayer::minimax(TicTacToe board, int depth, bool isMaximizing) {
	char status = board.gameStatus();
	if(status != 'C') {
		return scores[status];
	}
	if(isMaximizing) {
		int bestScore = -999;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if(board.isValidMove(i, j)) {
					board.addMove(player, i, j);
					int score = minimax(board, depth+1, false);
					board.removeMove(i, j);
					bestScore = max(score, bestScore);
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
					board.addMove(otherPlayer, i, j);
					int score = minimax(board, depth+1, true);
					board.removeMove(i, j);
					bestScore = min(score, bestScore);
				}
			}
		}
		return bestScore;
	}
}

#endif
