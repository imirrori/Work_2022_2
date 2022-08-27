#include <stdio.h>
#include <math.h>

int main()
{
    const int a = 42;
    const int b = 43;
    const int c = a == b ? 12 && 10 : 2 - 4;

    printf("Max value %d", c);

    return 0;

}
