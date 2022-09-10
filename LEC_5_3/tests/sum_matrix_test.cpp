#include "gtest/gtest.h"

#include "../mtricx_sum.h"

//int matrixSum(int* M, int x, int y);

TEST(MtrixSumTests, ZeroTest)
{
    EXPECT_EQ(matrixSum(nullptr, 0, 0), 0);
    EXPECT_EQ(matrixSum(nullptr, 42, 12), 0);
}

TEST(MtrixSumTests, OneValue)
{
    int M[1] = {1};
    EXPECT_EQ(matrixSum(M, 1, 0), 0);
}

TEST(MtrixSumTests, SumTest)
{
    int M[2][2] = { {3, 1},
                    {2, 4} };
    EXPECT_EQ(matrixSum((int*)M, 2, 2), 3);
}

TEST(MtrixSumTests, StrTest)
{
    EXPECT_STREQ("asdf","asdf");
}

TEST(MtrixSumTests, MassTest)
{
    int A[2] = {1, 2};
    int B[2] = {1, 2};
    EXPECT_EQ(memcmp(A, B, sizeof(int) * 2), 0);
}
