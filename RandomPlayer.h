#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H
using namespace std;

// RANDOM PLAYER

class RandomPlayer{
private:
    char player;
public:
    RandomPlayer(char p){
        player = p;
    }
    void getMove(TicTacToe board, int& row, int& col);
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

#endif
