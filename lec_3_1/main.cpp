//Написать программу, получающую натуральное число N
//Вывести все натуральные числа, на которые делится N, без остатка

#include <stdio.h>

int main()
{
    int N;
    printf("Please enter N: ");
    scanf("%d", &N);
    printf("Divider N: ");
    for(int i = 1; i < N; ++i)
    {
        if((N % i) == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
