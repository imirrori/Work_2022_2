//Сделать генератор для проверки домашних заданий

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    constexpr int size = 9;
    const char* Names[size] = {
        "Stolarov Vladimir",
        "Maksimenko Mihail",
        "Morozov Dmitry",
        "Morozova Arina",
        "Posipaiko Dmitry",
        "Laktionov Andrey",
        "Barinov Vladislav",
        "Gorachevskay Ekaterina",
        "Makarova Senilga"
    };

    srand(time(nullptr));

    int Results[size] = {};

    for(int i = 0; i < size; ++i)
    {
        int user;

        do
        {
            user = rand() % size;
            for(int j = 0; j < i && user != i; ++j)
            {
                if (Results[j] == user) {
                    user = i;
                }
            }
        } while(user == i); //Don't check himself

        Results[i] = user;
    }
    printf("+------------------------+-------------------------+\n");
    printf("|        Who             |         Whom            |\n");
    printf("+------------------------+-------------------------+\n");
    for(int i = 0; i < size; ++i)
    {
        printf("|%24s| %-24s|\n", Names[i], Names[Results[i]]);
        printf("+------------------------+-------------------------+\n");
    }

    return 0;
}
