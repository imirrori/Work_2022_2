// Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    constexpr int size = 7;
    int M[size][size];

    srand(time(nullptr));
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            M[i][j] = rand() % 10;
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    int k;
    printf("Please enter raw: ");
    scanf("%d", &k);

    for(int i = 0; i < size; ++i) {
        int temp = M[i][k];
        M[i][k] = M[k][i];
        M[k][i] = temp;
        // swap(M[i][k], M[k][i])
    }

    printf("\n");
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
