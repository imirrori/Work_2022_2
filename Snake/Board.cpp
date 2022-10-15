#include "Board.h"
#include "Politra.h"
#include "Helper.h"

#include <curses.h>

Board* CreateBoard(GameSize gameSize)
{
    const int scoreWidth = 20;

    Board* board = new Board;
    board->gameSize = gameSize;
    board->snakeSize = {gameSize.width - scoreWidth, gameSize.height};
    board->scoreSize = {scoreWidth, gameSize.height};
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

    attron(COLOR_PAIR(BOARD_POL));
    for(int i = 0; i < board->gameSize.width; ++i) {
        for(int j = 0; j < board->gameSize.height; ++j) {
            move(j, i);
            addch(' ');
        }
    }
    PrintBorder(0, board->snakeSize.width, board->snakeSize.height);
    PrintBorder(board->snakeSize.width, board->scoreSize.width, board->scoreSize.height);
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
