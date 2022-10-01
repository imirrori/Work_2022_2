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
        Board::BoardKey boardKey;
        switch(ch)
        {
        case 27:
            boardKey = Board::ESC;
            break;
        default:
            return game->state;
        }
        return RunBoard(game->board, boardKey);

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
    return game;
}

void DestroyGame(Game* game)
{
    if (!game) {
        return;
    }

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
