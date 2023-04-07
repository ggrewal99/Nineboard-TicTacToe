#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
using namespace std;

// HUMAN PLAYER

class HumanPlayer: public Player{
public:
    HumanPlayer(char p) : Player(p) {}
    void getMove(TicTacToe board, int& row, int& col);
    void selectBoard(NineBoard boards, int& row, int& col);
};

void HumanPlayer::getMove(TicTacToe board, int& row, int& col){
    do {
        cout << "Player " << player << " enter move: ";
        cin >> row >> col;
        cout << endl;
        row = row - 1;
        col = col - 1;
    } while (!board.isValidMove(row,col));
}

void HumanPlayer::selectBoard(NineBoard boards, int& row, int& col) {
    do {
        cout << "Player " << player << " enter board coordinates: ";
        cin >> row >> col;
        cout << endl;
        row = row - 1;
        col = col - 1;
    } while(boards.getStatus(row, col) != 'C');
}

#endif
