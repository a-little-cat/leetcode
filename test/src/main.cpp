#include "Solution.h"
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

TEST(MyTest, test)
{
    EXPECT_EQ(Solution::test(1), 2);
}

TEST(MyTest, twoSum)
{
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    auto ans = Solution::twoSum(input, target);
    EXPECT_EQ(ans.size(), 2);
    EXPECT_EQ(ans[0], 1);
    EXPECT_EQ(ans[1], 2);
    ans = Solution::twoSum_map(input, target);
    EXPECT_EQ(ans.size(), 2);
    EXPECT_EQ(ans[0], 1);
    EXPECT_EQ(ans[1], 2);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
