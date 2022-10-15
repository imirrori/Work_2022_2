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
    board->fruit = { rand() % (board->snakeSize.width - 2),
                     rand() % (board->snakeSize.height - 2) };
    return board;
}

void DestroyBoard(Board* board)
{
    delete board;
}

void PrintBoard(Board* board, int score)
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

    mvprintw(
        1,
        board->snakeSize.width + 1,
        "score: %d", score);

    attron(COLOR_PAIR(FRUIT_POL));
    move(board->fruit.y, board->fruit.x);
    addch('*');
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
