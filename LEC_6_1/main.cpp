#include "database.h"

#include <stdio.h>

int main()
{
    {
        DataBase* db = new DataBase;
        db->users_size = 2;
        db->users = new User*[2];
        db->users[0] = CreateUser("User 1", "Work 1");
        db->users[1] = CreateUser("User 2", "Work 2");
        WriteDBToFile(db, "/home/evgeniy-kozev/workspace/Work_2022_2/LEC_6_1/UserDB.txt");
    }
    {
        DataBase* db = ReadDBFromFile(
            "/home/evgeniy-kozev/workspace/Work_2022_2/LEC_6_1/UserDB.txt");
        for(int i = 0; i < db->users_size; ++i)
        {
            printf("Name: %s", db->users[i]->name);
            printf("Work: %s", db->users[i]->work);
        }

    }

    return 0;
}
