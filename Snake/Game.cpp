#include "Game.h"
#include "Politra.h"

#include <curses.h>

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
        PrintBoard(game->board);
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
        switch(ch)
        {
        case 27:
            return RunBoard(game->board, Board::ESC);
        case KEY_UP:
            return RunSnake(game->snake, Snake::UP);
        case KEY_DOWN:
            return RunSnake(game->snake, Snake::DOWN);
        case KEY_LEFT:
            return RunSnake(game->snake, Snake::LEFT);
        case KEY_RIGHT:
            return RunSnake(game->snake, Snake::RIGHT);
        default:
            return game->state;
        }
    case EXIT:
        return game->state;
    }
}

Game* CreateGame()
{
    initscr(); //Инициализация библиотеки
    keypad(stdscr, TRUE); // включить работу с непечатными символами (стрелками)
   // cbreak();
   // noecho();
    curs_set(0); // Убрать мигающий курсор
   // refresh();

    InitPolitra();

    Game* game = new Game;
    game->state = MENU;
    game->gameSize = {70, 20};
    game->board = CreateBoard(game->gameSize);
    game->menu = CreateMenu(game->gameSize);
    game->snake = CreateSnake();
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
