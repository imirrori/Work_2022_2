#include "Helper.h"

#include <curses.h>

void PrintBorder(size_t offest_width, size_t width, size_t height)
{
    size_t newWidth = width + offest_width;
    for(size_t i = offest_width; i < newWidth; ++i) {
        for(size_t j = 0; j < height; ++j) {
            move(j, i);
            if ((i == 0 && j == 0) ||
                (i == 0 && j == height - 1) ||
                (i == newWidth - 1 && j == 0) ||
                (i == newWidth - 1 && j ==  height - 1))
            {
                addch('+');
            } else if (j == 0 || j == height - 1) {
                addch('-');
            } else if (i == 0 || i == newWidth - 1) {
                addch('|');
            } else {
                addch(' ');
            }
        }
    }
}
