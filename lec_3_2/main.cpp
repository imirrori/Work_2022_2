// Написать программу которая имеет меню с выбором математической функции

#include <math.h>
#include <stdio.h>

int main()
{
    int ch = 0;
    do
    {
        switch(ch)
        {
        case 1:
            {
                double x;
                printf("Please enter X: ");
                scanf("%lf", &x);
                printf("cos(X) : %f\n", cos(x));
                break;
            }
        case 2:
            {
                double x;
                printf("Please enter X: ");
                scanf("%lf", &x);
                printf("sin(X) : %f\n", sin(x));
                break;
            }
        }

        printf("1. cos()\n");
        printf("2. sin()\n");
        printf("3. exit\n");
        scanf("%d", &ch);

    } while(ch != 3);
    return 0;
}
