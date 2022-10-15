#ifndef SNAKE_H
#define SNAKE_H

#include "GameState.h"
#include "Helper.h"

struct Snake {
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Point body[255];
    int snakeSize;
    Direction direction;
    GameSize gameSize;
};

Snake* CreateSnake(GameSize gameSize);
void DestroySnake(Snake* snake);
void PrintSnake(Snake* snake);

struct RunSnakeResult
{
    GameState state;
    bool eat;
};

RunSnakeResult RunSnake(Snake* snake, Snake::Direction direction, Point fruit);
bool MoveSnake(Snake* snake);

#endif // SNAKE_H
