#ifndef USERS_H
#define USERS_H

struct User
{
    char* name;
    char* work;
};

// Имя является обязательным полем.
// При невозможности создать пользователя возвращается nullptr
// Пользователь должен быть удален DeleteUser
User* CreateUser(const char* name, const char* work);
void DeleteUser(User* user);

#endif // USERS_H
