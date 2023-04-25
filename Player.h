#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
protected:
    char player;
    char name;
public:
    Player(char p) {
        player = p;
    }
    char getName() {
        return name;
    }
    virtual void getMove(TicTacToe board, int& row, int& col) = 0;
    virtual void getMove(NineBoard board, int& row, int& col) = 0;
    virtual void selectBoard(NineBoard boards, int& row, int& col) = 0;
};
#endif // PLAYER_H
