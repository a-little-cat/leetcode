#include "Solution.h"
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

TEST(MyTest, test)
{
    EXPECT_EQ(Solution::test(1), 2);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
