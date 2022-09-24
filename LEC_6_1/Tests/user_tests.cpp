#include "../users.h"

#include "gtest/gtest.h"

TEST(UsersTests, CreateNullTest)
{
    User* user = CreateUser(nullptr, nullptr);
    DeleteUser(user);
}

TEST(UsersTests, NameTest)
{
    User* user = CreateUser("Toto", nullptr);
    EXPECT_STREQ(user->name, "Toto");
    EXPECT_EQ(user->work, nullptr);
    DeleteUser(user);
}

TEST(UsersTests, WorkTest)
{
    User* user = CreateUser("", "Worker");
    EXPECT_STREQ(user->work, "Worker");
    DeleteUser(user);
}

