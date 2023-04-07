#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
protected:
    char player;
public:
    Player(char p) {
        player = p;
    }
    virtual void getMove(TicTacToe board, int& row, int& col) = 0;
    virtual void selectBoard(NineBoard boards, int& row, int& col) = 0;
};
#endif // PLAYER_H
