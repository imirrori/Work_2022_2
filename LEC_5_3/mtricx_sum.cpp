#include "mtricx_sum.h"

int matrixSum(int* M, int x, int y)
{
    int resultSum = 0;
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y - i - 1; ++j) {
            resultSum += *((M + i * y) + j);
        }
    }
    return resultSum;
}
