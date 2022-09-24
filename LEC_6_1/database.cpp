#include "database.h"

#include <stdlib.h>
#include <stdio.h>

// 2 - число пользователей
// имя_1
// работа_1
// имя_2
// работа_2

DataBase* ReadDBFromFile(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == nullptr) {
        return nullptr;
    }

    DataBase* newDB = new DataBase;

    fscanf(file, "%d\n", &newDB->users_size);
    newDB->users = new User*[newDB->users_size];

    for (int i = 0; i < newDB->users_size; ++i) {
        char name[255];
        fgets(name, 255, file);
        char work[255];
        fgets(work, 255, file);
        newDB->users[i] = CreateUser(name, work);
    }

    fclose(file);

    return newDB;
}

void WriteDBToFile(DataBase* db, const char* fileName)
{
    FILE* file = fopen(fileName, "w");
    fprintf(file, "%d\n", db->users_size);
    for (int i = 0; i < db->users_size; ++i) {
        fprintf(file, "%s\n", db->users[i]->name);
        fprintf(file, "%s\n", db->users[i]->work);
    }
    fclose(file);
}

void DestroyDB(DataBase* db)
{

}
