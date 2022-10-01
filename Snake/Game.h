#ifndef GAME_H
#define GAME_H

#include "Board.h"

struct Game
{
    Board* board;
};

Game* CreateGame();
void DestroyGame(Game* game);
void RunGame(Game* game);

#endif // GAME_H
