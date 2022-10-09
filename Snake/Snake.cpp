#include "Politra.h"
#include "Snake.h"

#include <curses.h>

Snake* CreateSnake()
{
    Snake* snake = new Snake;
    snake->snakeSize = 5;
    snake->body[4] = {1, 1};
    snake->body[3] = {2, 1};
    snake->body[2] = {3, 1};
    snake->body[1] = {4, 1};
    snake->body[0] = {5, 1};
    snake->direction = Snake::RIGHT;
    return snake;
}

void DestroySnake(Snake* snake)
{
    delete snake;
}

void PrintSnake(Snake* snake)
{
    if (!snake) {
        return;
    }

    attron(COLOR_PAIR(SNAKE_POL));

    for(int i = 0; i < snake->snakeSize; ++i) {
        move(snake->body[i].y, snake->body[i].x);
        addch('@');
    }
}

GameState RunSnake(Snake* snake, Snake::Direction direction)
{
    if (!snake) {
        return GameState::BOARD;
    }

    snake->direction = direction;
    if (!MoveSnake(snake)) {
        return GameState::EXIT;
    }

    return GameState::BOARD;
}


bool MoveSnake(Snake* snake)
{
    if (!snake) {
        return false;
    }

    for (int i = snake->snakeSize - 1; i >= 1; --i) {
        snake->body[i] = snake->body[i - 1];
    }

    switch(snake->direction) {
    case Snake::UP:
        --snake->body[0].y;
        break;
    case Snake::DOWN:
        ++snake->body[0].y;
        break;
    case Snake::LEFT:
        --snake->body[0].x;
        break;
    case Snake::RIGHT:
        ++snake->body[0].x;
        break;
    }

    for (int i = 0; i + 1 < snake->snakeSize; ++i) {
        if (snake->body[i + 1].x == snake->body[0].x &&
            snake->body[i + 1].y == snake->body[0].y) {
            return false;
        }
    }

    return true;
}
