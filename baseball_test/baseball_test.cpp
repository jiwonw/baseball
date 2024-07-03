#include "pch.h"
#include "../baseball/baseball.cpp"

class BaseBallTest : public testing::Test {
public:
    Baseball game{ "123" };
};

TEST_F(BaseBallTest, PreCondition000) {
    EXPECT_THROW(game.guess("12"), length_error);
}

TEST_F(BaseBallTest, PreCondition001) {
    EXPECT_THROW(game.guess("12a"), invalid_argument);
}

TEST_F(BaseBallTest, PreCondition002) {
    EXPECT_THROW(game.guess("222"), invalid_argument);
}


TEST_F(BaseBallTest, Logic000) {
    GameResult answer = game.guess("123");
    GameResult expected = { true, 3, 0 };
    EXPECT_EQ(answer.solved, expected.solved);
    EXPECT_EQ(answer.strikes, expected.strikes);
    EXPECT_EQ(answer.balls, expected.balls);
}

TEST_F(BaseBallTest, Logic001) {
    GameResult answer = game.guess("456");
    GameResult expected = { false, 0, 0 };
    EXPECT_EQ(answer.solved, expected.solved);
    EXPECT_EQ(answer.strikes, expected.strikes);
    EXPECT_EQ(answer.balls, expected.balls);
}

TEST_F(BaseBallTest, Logic002) {
    GameResult answer = game.guess("923");
    GameResult expected = { false, 2, 0 };
    EXPECT_EQ(answer.solved, expected.solved);
    EXPECT_EQ(answer.strikes, expected.strikes);
    EXPECT_EQ(answer.balls, expected.balls);
}

TEST_F(BaseBallTest, Logic003) {
    GameResult answer = game.guess("321");
    GameResult expected = { false, 1, 2 };
    EXPECT_EQ(answer.solved, expected.solved);
    EXPECT_EQ(answer.strikes, expected.strikes);
    EXPECT_EQ(answer.balls, expected.balls);
}

