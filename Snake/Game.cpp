#include "Game.h"
#include "Politra.h"

#include <curses.h>

Game* CreateGame()
{
    initscr(); //Инициализация библиотеки
   // cbreak();
   // noecho();
    curs_set(0); // Убрать мигающий курсор
   // refresh();

    InitPolitra();

    Game* game = new Game;
    game->board = CreateBoard();
    return game;
}

void DestroyGame(Game* game)
{
    if (!game) {
        return;
    }

    DestroyBoard(game->board);
    delete game;
    endwin();
}

void RunGame(Game* game)
{
    if (!game) {
        return;
    }

    PrintBoard(game->board);
    getch();
}
