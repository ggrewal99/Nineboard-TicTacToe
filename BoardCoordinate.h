#ifndef BOARD_COORD_H
#define BOARD_COORD_H

struct BoardCoordinate
{
    int row;
    int col;
    BoardCoordinate()
    {
        row = 0;
        col = 0;
    }
    BoardCoordinate(int x, int y)
    {
        row = x;
        col = y;
    }

    bool operator==(const BoardCoordinate &bc) const
    {
        return (row == bc.row) && (col == bc.col);
    }
};

#endif