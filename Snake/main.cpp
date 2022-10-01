#include "Game.h"

int main()
{
    Game* game = CreateGame();
    RunGame(game);
    DestroyGame(game);
    return 0;
}
