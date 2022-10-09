#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

int SelectResult(void*, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; ++i)
    {
        printf("argv: %s azColName %s\n", argv[i], azColName[i]);
    }
    return 0;
}

int main()
{
    sqlite3 *db;
    const int rc = sqlite3_open("/home/evgeniy-kozev/workspace/Work_2022_2/SQL/MyDB", &db);
    if (rc != SQLITE_OK) {
        printf("Can't open DB %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    printf("OK\n");

    char* errmsg;
    sqlite3_exec(
        db,
        "SELECT * FROM Person;",
        SelectResult,
        NULL,
        &errmsg);

    sqlite3_exec(
        db,
        "INSERT INTO Person(PersonID, Name) VALUES('3', 'qwe');",
        NULL,
        NULL,
        &errmsg);

    printf("\n\n");
    sqlite3_exec(
        db,
        "SELECT * FROM Person;",
        SelectResult,
        NULL,
        &errmsg);

    return 0;
}
