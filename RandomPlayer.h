#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H
using namespace std;

// RANDOM PLAYER

class RandomPlayer: public Player {
public:
    RandomPlayer(char p) : Player(p) {
        name = 'R';
    }
    void getMove(TicTacToe board, int& row, int& col);
    void getMove(NineBoard board, int& row, int& col){}
    void selectBoard(NineBoard boards, int& row, int& col);
};

void RandomPlayer::getMove(TicTacToe board, int& row, int& col){
    list<int> emptyCells = board.getEmptyCells();
    list<int>::const_iterator it;
	it = emptyCells.begin();
	int pos = rand() % emptyCells.size();
	advance(it, pos); // @suppress("Invalid arguments")
	row = *it/3;
	col = *it%3;
}

void RandomPlayer::selectBoard(NineBoard boards, int& row, int& col) {
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(boards.getStatus(row, col) != 'C');
}
#endif
