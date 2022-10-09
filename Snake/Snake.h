#ifndef SNAKE_H
#define SNAKE_H

#include "GameState.h"

struct Snake {
    struct Point
    {
        int x;
        int y;
    };

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Point body[255];
    int snakeSize;
    Direction direction;
};

Snake* CreateSnake();
void DestroySnake(Snake* snake);
void PrintSnake(Snake* snake);
GameState RunSnake(Snake* snake, Snake::Direction direction);
bool MoveSnake(Snake* snake);

#endif // SNAKE_H
