#include <gtest/gtest.h>

TEST(Testmagicfunctions, testforRandomnumbers)
{
    EXPECT_EQ(getRandomnumbers(), 42);
}