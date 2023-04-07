#ifndef SMART_PLAYER_H
#define SART_PLAYER_H

class SmartPlayer: public Player {
public:
    SmartPlayer(char p) : Player(p) {}
    void getMove(TicTacToe board, int& row, int& col);
    void selectBoard(NineBoard boards, int& row, int& col);
};

void SmartPlayer::getMove(TicTacToe board, int& row, int& col){
    list<int> emptyCells = board.getEmptyCells();
    list<int>::const_iterator it;
	it = emptyCells.begin();
	int pos = rand() % emptyCells.size();
	advance(it, pos); // @suppress("Invalid arguments")
	row = *it/3;
	col = *it%3;
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

#endif // SMART_PLAYER_H
