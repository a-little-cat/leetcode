#include "Solution.h"
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
using ::testing::ElementsAre;

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

TEST(MyTest, judgeSquareSum)
{
    EXPECT_EQ(Solution::judgeSquareSum(2), true);
    EXPECT_EQ(Solution::judgeSquareSum(3), false);
    EXPECT_EQ(Solution::judgeSquareSum(4), true);
    EXPECT_EQ(Solution::judgeSquareSum(2147482647), false);
}

TEST(MyTest, reverseVowels)
{
    EXPECT_EQ(Solution::reverseVowels("abcde"), "ebcda");
    EXPECT_EQ(Solution::reverseVowels("hello"), "holle");
    EXPECT_EQ(Solution::reverseVowels("leetcode"), "leotcede");
    EXPECT_EQ(Solution::reverseVowels(" "), " ");
    EXPECT_EQ(Solution::reverseVowels("a."), "a.");
}

TEST(MyTest, search)
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    EXPECT_EQ(Solution::search(nums, target), 4);
}
TEST(MyTest, searchInsert)
{
    vector<int> nums;
    int target = 0;

    nums = {-1, 0, 3, 5, 9, 12};
    target = 1;
    EXPECT_EQ(Solution::searchInsert(nums, target), 2);
}

TEST(MyTest, mergeSort)
{
    vector<int> nums = {3, 0, -1, 5, 9, 12};
    Solution::mergeSort(nums);
    EXPECT_THAT(nums, ElementsAre(-1, 0, 3, 5, 9, 12));
}

TEST(MyTest, quickSort)
{
    vector<int> nums = {47, 29, 71, 99, 78, 19, 24, 47};
    Solution::quickSort(nums);
    EXPECT_THAT(nums, ElementsAre(19, 24, 29, 47, 47, 71, 78, 99));
}

TEST(MyTest, longestCommonSubsequence)
{
    EXPECT_EQ(Solution::longestCommonSubsequence("abcde", "ace"), 3);
    EXPECT_EQ(Solution::longestCommonSubsequence("abc", "def"), 0);
    EXPECT_EQ(Solution::longestCommonSubsequence("abcba", "abcbcba"), 5);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
