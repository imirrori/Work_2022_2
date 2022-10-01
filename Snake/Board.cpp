#include "Board.h"
#include "Politra.h"

#include <curses.h>

Board* CreateBoard()
{
    Board* board = new Board;
    board->height = 70;
    board->width = 20;
    return board;
}

void DestroyBoard(Board* board)
{
    delete board;
}

void PrintBoard(Board* board)
{
    if (!board) {
        return;
    }

    for(int i = 0; i < board->width; ++i) {
        for(int j = 0; j < board->height; ++j) {
            move(i, j);
            chtype ch = '*' | COLOR_PAIR(BOARD_POL);
            addch(ch);
        }
    }
}
