#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "GameState.h"
#include "Menu.h"
#include "Snake.h"

struct Game
{
    GameState state;
    GameSize gameSize;
    Board* board;
    Menu* menu;
    Snake* snake;
};

Game* CreateGame();
void DestroyGame(Game* game);
void RunGame(Game* game);

#endif // GAME_H
