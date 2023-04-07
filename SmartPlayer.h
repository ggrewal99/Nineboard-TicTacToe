#ifndef SMART_PLAYER_H
#define SART_PLAYER_H

class SmartPlayer: public Player {
public:
    SmartPlayer(char p) : Player(p) {}
    void getMove(TicTacToe board, int& row, int& col);
    void selectBoard(NineBoard board, int& row, int& col);
};

void SmartPlayer::getMove(TicTacToe board, int& row, int& col){

}
void SmartPlayer::selectBoard(NineBoard board, int& row, int& col){

}

#endif // SMART_PLAYER_H
