#include "Politra.h"

#include <curses.h>

void InitPolitra()
{
    start_color(); //Включить работу с цветами
    init_pair(BOARD_POL, COLOR_RED, COLOR_GREEN);
}
