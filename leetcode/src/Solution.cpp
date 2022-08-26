#include "Solution.h"

int Solution::test(int input)
{
    return input + 1;
}

vector<int> Solution::twoSum(vector<int>& numbers, int target)
{
    int sum = 0;
    int left = 0;
    int right = static_cast<int>(numbers.size() - 1);
    while (numbers[left] + numbers[right] != target)
    {
        if (numbers[left] + numbers[right] > target)
            right--;
        else
            left++;
    }
    return {left + 1, right + 1};
}
