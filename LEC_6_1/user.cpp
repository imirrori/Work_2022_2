#include "users.h"

#include <string.h>

User* CreateUser(const char* name, const char* work)
{
    if (name == nullptr)
    {
        return nullptr;
    }

    User* newUser = new User;

    const int name_len = strlen(name);
    newUser->name = new char[name_len + 1]{};
    strncpy(newUser->name, name, name_len);

    if (work != nullptr) {
        const int work_len = strlen(work);
        newUser->work = new char[work_len + 1]{};
        strncpy(newUser->work, work, work_len);
    } else {
        newUser->work = nullptr;
    }


    return newUser;
}

void DeleteUser(User* user)
{
    if (user != nullptr)
    {
        delete[] user->work;
        delete[] user->name;
        delete user;
    }
}
