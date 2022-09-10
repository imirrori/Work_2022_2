//  Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    srand(time(nullptr));
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            M[i][j] = rand() % 10;
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    int resultSum = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size - i - 1; ++j) {
            resultSum += M[i][j];
        }
    }

    printf("Result sum: %d\n", resultSum);

    return 0;
}
