#include "Helper.h"

#include <curses.h>

void PrintBorder(size_t width, size_t height)
{
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            move(j, i);
            if ((i == 0 && j == 0) ||
                (i == 0 && j == height - 1) ||
                (i == width - 1 && j == 0) ||
                (i == width - 1 && j ==  height - 1))
            {
                addch('+');
            } else if (j == 0 || j == height - 1) {
                addch('-');
            } else if (i == 0 || i == width - 1) {
                addch('|');
            } else {
                addch(' ');
            }
        }
    }
}
