#include "pch.h"
#include "../baseball/baseball.cpp"

TEST(BaseBallTest, PreCondition000) {
    BaseBall baseball;
    EXPECT_THROW(baseball.guess("12"), length_error);
}

TEST(BaseBallTest, PreCondition001) {
    BaseBall baseball;
    EXPECT_THROW(baseball.guess("12a"), invalid_argument);
}

TEST(BaseBallTest, PreCondition002) {
    BaseBall baseball;
    EXPECT_THROW(baseball.guess("222"), invalid_argument);
}
