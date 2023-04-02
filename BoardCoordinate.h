#ifndef BOARD_COORD_H
#define BOARD_COORD_H

struct BoardCoordinate
{
    int row;
    int col;
    char status; /*
                    'X' means X has won
                    'O' means O has won
                    'D' means full/draw
                    'C' means continue
                */
    BoardCoordinate()
    {
        row = 0;
        col = 0;
        status = 'C';
    }
    BoardCoordinate(int x, int y)
    {
        row = x;
        col = y;
    }

    BoardCoordinate(int x, int y, char bStatus)
    {
        row = x;
        col = y;
        status = bStatus;
    }

    bool operator==(const BoardCoordinate &bc) const
    {
        return (row == bc.row) && (col == bc.col);
    }
};

#endif
