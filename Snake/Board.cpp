#include "Board.h"
#include "Politra.h"

#include <curses.h>

Board* CreateBoard(GameSize gameSize)
{
    Board* board = new Board;
    board->gameSize = gameSize;
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

    for(int i = 0; i < board->gameSize.width; ++i) {
        for(int j = 0; j < board->gameSize.height; ++j) {
            move(j, i);
            chtype ch = ' ' | COLOR_PAIR(BOARD_POL);
            addch(ch);
        }
    }
}

GameState RunBoard(Board* board, Board::BoardKey key)
{
    (void) board;

    switch (key) {
    case Board::ESC:
        return MENU;
    }
    return BOARD;
}
