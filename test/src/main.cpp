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

TEST(MyTest, searchRotate)
{
    vector<int> nums;
    nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(Solution::searchRotate(nums, 0), 4);
    nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(Solution::searchRotate(nums, 3), -1);
    nums = {1};
    EXPECT_EQ(Solution::searchRotate(nums, 0), -1);
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

TEST(MyTest, quickSort_oi)
{
    vector<int> nums;
    nums = {47, 29, 71, 99, 78, 19, 24, 47};
    Solution::quickSort_oi(nums);
    EXPECT_THAT(nums, ElementsAre(19, 24, 29, 47, 47, 71, 78, 99));
    nums = {1, 2, 3, 4, 5};
    Solution::quickSort_oi(nums);
    EXPECT_THAT(nums, ElementsAre(1, 2, 3, 4, 5));
    nums = {2, 2, 2, 2};
    Solution::quickSort_oi(nums);
    EXPECT_THAT(nums, ElementsAre(2, 2, 2, 2));
}


TEST(MyTest, longestCommonSubsequence)
{
    EXPECT_EQ(Solution::longestCommonSubsequence("abcde", "ace"), 3);
    EXPECT_EQ(Solution::longestCommonSubsequence("abc", "def"), 0);
    EXPECT_EQ(Solution::longestCommonSubsequence("abcba", "abcbcba"), 5);
}

TEST(MyTest, lCS)
{
    EXPECT_EQ(Solution::lCS("babce", "abc"), "abc");
}

TEST(MyTest, findMin)
{
    vector<int> nums;
    nums = {3, 4, 5, 1, 2};
    EXPECT_EQ(Solution::findMin(nums), 1);
    nums = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(Solution::findMin(nums), 0);
    nums = {11, 13, 15, 17};
    EXPECT_EQ(Solution::findMin(nums), 11);
}

TEST(MyTest, findMin2)
{
    vector<int> nums;
    nums = {1, 3, 5};
    EXPECT_EQ(Solution::findMin2(nums), 1);
    nums = {2, 2, 2, 0, 1};
    EXPECT_EQ(Solution::findMin2(nums), 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
