#include "Game.h"
#include "Politra.h"

#include <curses.h>
#include <stdlib.h>
#include <time.h>

void PrintGameSubModules(Game* game)
{
    if (!game) {
        return;
    }

    switch (game->state) {
    case MENU:
        PrintMenu(game->menu);
        break;
    case BOARD:
        PrintBoard(game->board, game->score);
        PrintSnake(game->snake);
        break;
    case EXIT:
        return;
    }
}

GameState RunGameSubModules(Game* game)
{
    if (!game) {
        return MENU;
    }

    int ch = getch();

    switch (game->state) {
    case MENU:
        Menu::MenuKey menuKey;
        switch(ch)
        {
        case KEY_UP:
            menuKey = Menu::UP;
            break;
        case KEY_DOWN:
            menuKey = Menu::DOWN;
            break;
        case 10:
            menuKey = Menu::ENTER;
            break;
        default:
            return game->state;
        }
        return RunMenu(game->menu, menuKey);
    case BOARD:
    {
        Snake::Direction direction = game->snake->direction;
        switch(ch)
        {
        case 27:
            return RunBoard(game->board, Board::ESC);
        case KEY_UP:
            direction = Snake::UP;
            break;
        case KEY_DOWN:
            direction = Snake::DOWN;
            break;
        case KEY_LEFT:
            direction = Snake::LEFT;
            break;
        case KEY_RIGHT:
            direction = Snake::RIGHT;
            break;
        case -1:
            break;
        default:
            return game->state;
        }
        RunSnakeResult result = RunSnake(game->snake, direction, game->board->fruit);
        if (result.eat) {
            ++game->score;
        }
        return result.state;
    }
    case EXIT:
        return game->state;
    }
    return game->state;
}

Game* CreateGame()
{
    initscr(); //Инициализация библиотеки
    keypad(stdscr, TRUE); // включить работу с непечатными символами (стрелками)
   // cbreak();
   // noecho();
    curs_set(0); // Убрать мигающий курсор
   // refresh();

    halfdelay(1);
    InitPolitra();
    srand(time(NULL));

    Game* game = new Game;
    game->state = MENU;
    game->gameSize = {70, 20};
    game->board = CreateBoard(game->gameSize);
    game->menu = CreateMenu(game->gameSize);
    game->snake = CreateSnake(game->board->snakeSize);
    return game;
}

void DestroyGame(Game* game)
{
    if (!game) {
        return;
    }

    DestroySnake(game->snake);
    DestroyMenu(game->menu);
    DestroyBoard(game->board);
    delete game;
    endwin();
}

void RunGame(Game* game)
{
    while(game->state != EXIT) {
        PrintGameSubModules(game);
        game->state = RunGameSubModules(game);
    }
}
