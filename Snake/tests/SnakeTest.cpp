#include <../Snake.h>

#include <gtest/gtest.h>

TEST(SnakeTest, MoveTest_1)
{
    Snake snake;
    snake.snakeSize = 2;
    snake.gameSize = {100, 100};
    snake.body[1] = {1, 2};
    snake.body[0] = {2, 2};

    //Змея проходит через саму себя?
    //snake.direction = Snake::LEFT;
    //EXPECT_FALSE(MoveSnake(&snake));

    snake.direction = Snake::RIGHT;
    EXPECT_TRUE(MoveSnake(&snake));

    snake.direction = Snake::UP;
    EXPECT_TRUE(MoveSnake(&snake));

    snake.direction = Snake::DOWN;
    EXPECT_TRUE(MoveSnake(&snake));
}

TEST(SnakeTest, MoveTest_2)
{
    Snake snake;
    snake.snakeSize = 2;
    snake.gameSize = {100, 100};
    snake.body[1] = {1, 1};
    snake.body[0] = {2, 1};

    snake.direction = Snake::RIGHT;
    EXPECT_TRUE(MoveSnake(&snake));
    EXPECT_EQ(snake.body[0].x, 3);
    EXPECT_EQ(snake.body[0].y, 1);
    EXPECT_EQ(snake.body[1].x, 2);
    EXPECT_EQ(snake.body[1].y, 1);
}

TEST(SnakeTest, MoveTest_3)
{
    Snake snake;
    snake.snakeSize = 2;
    snake.gameSize = {100, 100};
    snake.body[1] = {1, 2};
    snake.body[0] = {2, 2};

    snake.direction = Snake::UP;
    EXPECT_TRUE(MoveSnake(&snake));
    EXPECT_EQ(snake.body[0].x, 2);
    EXPECT_EQ(snake.body[0].y, 1);
    EXPECT_EQ(snake.body[1].x, 2);
    EXPECT_EQ(snake.body[1].y, 2);
}

TEST(SnakeTest, MoveTest_4)
{
    Snake snake;
    snake.snakeSize = 2;
    snake.gameSize = {100, 100};
    snake.body[1] = {1, 2};
    snake.body[0] = {2, 2};

    snake.direction = Snake::DOWN;
    EXPECT_TRUE(MoveSnake(&snake));
    EXPECT_EQ(snake.body[0].x, 2);
    EXPECT_EQ(snake.body[0].y, 3);
    EXPECT_EQ(snake.body[1].x, 2);
    EXPECT_EQ(snake.body[1].y, 2);
}

TEST(SnakeTest, MoveTest_5)
{
    Snake snake;
    snake.snakeSize = 4;
    snake.gameSize = {100, 100};
    snake.body[3] = {1, 1};
    snake.body[2] = {2, 1};
    snake.body[1] = {2, 2};
    snake.body[0] = {1, 2};

    snake.direction = Snake::UP;
    EXPECT_TRUE(MoveSnake(&snake));
}

TEST(SnakeTest, MoveTest_6)
{
    Snake snake;
    snake.snakeSize = 5;
    snake.gameSize = {100, 100};
    snake.body[4] = {1, 1};
    snake.body[3] = {2, 1};
    snake.body[2] = {3, 1};
    snake.body[1] = {3, 2};
    snake.body[0] = {2, 2};

    snake.direction = Snake::UP;
    EXPECT_FALSE(MoveSnake(&snake));
}

TEST(SnakeTest, MoveTest_7)
{
    /*
     * +-+
     * |@|
     * +-+
     */
    Snake snake;
    snake.snakeSize = 1;
    snake.body[0] = {1, 1};
    snake.gameSize = {3, 3};
    snake.direction = Snake::UP;
    EXPECT_FALSE(MoveSnake(&snake));
    snake.direction = Snake::DOWN;
    EXPECT_FALSE(MoveSnake(&snake));
    snake.direction = Snake::LEFT;
    EXPECT_FALSE(MoveSnake(&snake));
    snake.direction = Snake::RIGHT;
    EXPECT_FALSE(MoveSnake(&snake));
}

TEST(SnakeTest, MoveTest_8)
{
    /*
     * +---+
     * |   |
     * | @ |
     * |   |
     * +---+
     */
    Snake snake;
    snake.snakeSize = 1;
    snake.body[0] = {2, 2};
    snake.gameSize = {5, 5};
    snake.direction = Snake::UP;
    EXPECT_TRUE(MoveSnake(&snake));
    snake.direction = Snake::DOWN;
    EXPECT_TRUE(MoveSnake(&snake));
    snake.direction = Snake::LEFT;
    EXPECT_TRUE(MoveSnake(&snake));
    snake.direction = Snake::RIGHT;
    EXPECT_TRUE(MoveSnake(&snake));
}
