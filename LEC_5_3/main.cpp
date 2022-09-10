//  Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали.

#include "matrix_manager.h"
#include "mtricx_sum.h"

#include <stdio.h>

/* size = 4
 * 1 0 0 2
 * 0 1 2 0
 * 0 2 1 0
 * 2 0 0 1
 **/

int main()
{
    constexpr int size = 5;
    int M[size][size];

    fillMatrix(
        reinterpret_cast<int*>(M), size, size);
    printMatrix(
        reinterpret_cast<int*>(M), size, size);

    const int resultSum =
        matrixSum(
            reinterpret_cast<int*>(M),
            size,
            size);

    printf("Result sum: %d\n", resultSum);
    return 0;
}
