//Сформировать новый массив из элементов массива М (25),
//встречающихся в этом массиве только один раз.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    constexpr int size = 25;
    int M[size];

    srand(time(nullptr));

    printf("M: ");
    for(int i = 0; i < size; ++i)
    {
        M[i] = rand() % 21 - 5;
        printf("%d ", M[i]);
    }

    int A[size] = {};
    int k = 0;
    for(int i = 0; i < size; ++i)
    {
        bool found = false;
        int temp = M[i];
        for(int j = 0; j < size && !found; ++j)
        {
            if (j != i && temp == M[j]) {
                found = true;
            }
        }

        if (!found) {
            A[k] = temp;
            ++k;
        }
    }

    printf("\nA: ");
    for(int i = 0; i < k; ++i)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
