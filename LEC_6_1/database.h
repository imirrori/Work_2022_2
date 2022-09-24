#ifndef DATABASE_H
#define DATABASE_H

#include "users.h"

struct DataBase
{
    int users_size;
    User** users;
};

DataBase* ReadDBFromFile(const char* fileName);
void WriteDBToFile(DataBase* db, const char* fileName);
void DestroyDB(DataBase* db);

#endif // DATABASE_H
