#include "Solution.h"
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <utility>
using ::testing::ElementsAre;

TEST(MyTest, test)
{
    EXPECT_EQ(Solution::test(1), 2);
}

TEST(MyTest, twoSum)
{
    EXPECT_THAT(Solution::twoSum({3, 2, 4}, 6), ElementsAre(1, 2));
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
    EXPECT_EQ(Solution::search({-1, 0, 3, 5, 9, 12}, 9), 4);
}

TEST(MyTest, searchRotate)
{
    EXPECT_EQ(Solution::searchRotate({5, 1, 3}, 5), 0);
    EXPECT_EQ(Solution::searchRotate({4, 5, 6, 7, 0, 1, 2}, 0), 4);
    EXPECT_EQ(Solution::searchRotate({4, 5, 6, 7, 0, 1, 2}, 3), -1);
    EXPECT_EQ(Solution::searchRotate({1}, 0), -1);
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

TEST(MyTest, findKth)
{
    vector<int> nums;
    nums = {1, 3, 5, 2, 2};
    EXPECT_EQ(Solution::findKth(nums, 3), 2);
    nums = {7, 10, 10, 5, 6, 4, 9, 9, 8, 3, 4, 2};
    EXPECT_EQ(Solution::findKth(nums, 3), 9);
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
    EXPECT_EQ(Solution::findMin({5, 6, 1, 2, 3, 4}), 1);
    EXPECT_EQ(Solution::findMin({3, 4, 5, 1, 2}), 1);
    EXPECT_EQ(Solution::findMin({4, 5, 6, 7, 0, 1, 2}), 0);
    EXPECT_EQ(Solution::findMin({11, 13, 15, 17}), 11);
}

TEST(MyTest, findMin2)
{
    EXPECT_EQ(Solution::findMin2({3, 3, 1, 3}), 1);
    EXPECT_EQ(Solution::findMin2({1, 3, 5}), 1);
    EXPECT_EQ(Solution::findMin2({2, 2, 2, 0, 1}), 0);
}

TEST(MyTest, isValid)
{
    EXPECT_EQ(Solution::isValid("()"), true);
    EXPECT_EQ(Solution::isValid("()[]{}"), true);
    EXPECT_EQ(Solution::isValid("(]"), false);
    EXPECT_EQ(Solution::isValid("]"), false);
}

TEST(MyTest, reverseList)
{
    EXPECT_THAT(listnode_vector(Solution::reverseList(vector_listnode({1, 2, 3, 4, 5}))), ElementsAre(5, 4, 3, 2, 1));
}

TEST(MyTest, mergeTwoLists)
{
    ListNode* l1 = vector_listnode({1, 2, 4});
    ListNode* l2 = vector_listnode({1, 3, 4});
    print_listnode(Solution::mergeTwoLists(l1, l2));
}

TEST(MyTest, deleteDuplicates)
{
    print_listnode(Solution::deleteDuplicates(vector_listnode({1, 1, 1})));
}

TEST(MyTest, removeNthFromEnd)
{
    print_listnode(Solution::removeNthFromEnd(vector_listnode({1}), 1));
    print_listnode(Solution::removeNthFromEnd(vector_listnode({1, 2, 3, 4, 5}), 2));
}

TEST(MyTest, swapPairs)
{
    print_listnode(Solution::swapPairs(vector_listnode({1, 2, 3, 4})));
    print_listnode(Solution::swapPairs(vector_listnode({1})));
    print_listnode(Solution::swapPairs(vector_listnode({})));
}

TEST(MyTest, reverseKGroup)
{
    print_listnode(Solution::reverseKGroup(vector_listnode({1, 2, 3, 4, 5}), 2));
    print_listnode(Solution::reverseKGroup(vector_listnode({1, 2, 3, 4, 5}), 3));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
