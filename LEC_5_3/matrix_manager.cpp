#include "matrix_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int* M, int x, int y)
{
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            printf("%d ", *((M + i * y) + j));
        }
        printf("\n");
    }
}

void fillMatrix(int* M, int x, int y)
{
    srand(time(nullptr));
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            *((M + i * y) + j) = rand() % 10;
        }
    }
}
