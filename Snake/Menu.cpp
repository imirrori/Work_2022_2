#include "Menu.h"
#include "Politra.h"

#include <curses.h>

Menu* CreateMenu(GameSize gameSize)
{
    Menu* menu = new Menu;
    menu->gameSize = gameSize;
    menu->menuStrings[Menu::START_GAME] = "Start game";
    menu->menuStrings[Menu::TABLE_RECORD] = "Table records";
    menu->menuStrings[Menu::EXIT] = "Exit";
    menu->currentPoint = Menu::START_GAME;
    return menu;
}

void DestroyMenu(Menu* menu)
{
    delete menu;
}

void PrintMenu(Menu* menu)
{
    if (!menu) {
        return;
    }

    attron(COLOR_PAIR(MENU_POL));

    for(int i = 0; i < menu->gameSize.width; ++i) {
        for(int j = 0; j < menu->gameSize.height; ++j) {
            move(j, i);
            addch(' ');
        }
    }

    for (int i = 0; i < Menu::COUNT; ++i) {
        mvprintw(i, 1, "%s", menu->menuStrings[i]);
    }
    move(menu->currentPoint, 0);
    addch('*');

    attroff(COLOR_PAIR(MENU_POL));
}

GameState RunMenu(Menu* menu, Menu::MenuKey key)
{
    switch (key) {
    case Menu::UP:
        if (menu->currentPoint != Menu::FIRST_POINT)
            --menu->currentPoint;
        return MENU;
    case Menu::DOWN:
        if (menu->currentPoint != Menu::LAST_POINT)
            ++menu->currentPoint;
        return MENU;
    case Menu::ENTER:
    {
        switch (menu->currentPoint) {
        case Menu::START_GAME:
            return BOARD;
        case Menu::TABLE_RECORD:
            return MENU;
        case Menu::EXIT:
            return EXIT;
        default:
            break;
        }
    }
    }
    return MENU;
}
