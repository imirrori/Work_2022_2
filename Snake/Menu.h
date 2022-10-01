#ifndef MENU_H
#define MENU_H

#include "GameState.h"

struct Menu
{
    enum MenuKey
    {
        UP,
        DOWN,
        ENTER
    };

    enum MenuPoint
    {
        START_GAME,
        TABLE_RECORD,
        EXIT,
        //----------
        COUNT,
        FIRST_POINT = START_GAME,
        LAST_POINT = EXIT
    };

    const char* menuStrings[COUNT];
    int currentPoint;
    GameSize gameSize;
};

Menu* CreateMenu(GameSize gameSize);
void DestroyMenu(Menu* menu);
void PrintMenu(Menu* menu);

//Принимать нажатую клавишу
//По тому, какая клавиша нажа, должно быть модифицировано меню
//функция должна возвращать новое состояние игры
GameState RunMenu(Menu* menu, Menu::MenuKey key);

#endif // MENU_H
