#ifndef BOARD_H
#define BOARD_H

struct Board
{
    int width;
    int height;
};

Board* CreateBoard();
void DestroyBoard(Board* board);
void PrintBoard(Board* board);

#endif // BOARD_H
