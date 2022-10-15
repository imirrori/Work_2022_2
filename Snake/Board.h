#ifndef BOARD_H
#define BOARD_H

#include "GameState.h"

#include <stdlib.h>
#include <Helper.h>

struct Board
{
    enum BoardKey
    {
        ESC
    };

    GameSize gameSize;
    GameSize snakeSize;
    GameSize scoreSize;

    Point fruit;
};

Board* CreateBoard(GameSize gameSize);
void DestroyBoard(Board* board);
void PrintBoard(Board* board, int score);

//Принимать нажатую клавишу
//По тому, какая клавиша нажа, должно быть модифицировано меню
//функция должна возвращать новое состояние игры
GameState RunBoard(Board* board, Board::BoardKey key);

#endif // BOARD_H
