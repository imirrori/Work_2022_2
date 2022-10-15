#include "Politra.h"
#include "Snake.h"

#include <curses.h>
#include <string.h>

Snake* CreateSnake(GameSize gameSize)
{
    Snake* snake = new Snake;
    snake->gameSize = gameSize;
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

    Snake::Point newBody[255];
    memcpy(newBody, snake->body, sizeof(Snake::Point) * snake->snakeSize);

    for (int i = snake->snakeSize - 1; i >= 1; --i) {
        newBody[i] = newBody[i - 1];
    }

    switch(snake->direction) {
    case Snake::UP:
        --newBody[0].y;
        break;
    case Snake::DOWN:
        ++newBody[0].y;
        break;
    case Snake::LEFT:
        --newBody[0].x;
        break;
    case Snake::RIGHT:
        ++newBody[0].x;
        break;
    }

    for (int i = 0; i + 1 < snake->snakeSize; ++i) {
        if (newBody[i + 1].x == newBody[0].x &&
            newBody[i + 1].y == newBody[0].y) {
            return false;
        }
    }

    for (int i = 0; i < snake->snakeSize; ++i) {
        if (newBody[i].x == 0 ||
            newBody[i].y == 0 ||
            newBody[i].x == snake->gameSize.width - 1 ||
            newBody[i].y == snake->gameSize.height - 1) {
            return false;
        }
    }

    memcpy(snake->body, newBody, sizeof(Snake::Point) * snake->snakeSize);
    return true;
}
