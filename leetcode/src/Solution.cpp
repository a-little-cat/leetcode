#include "Solution.h"
#include <cmath>
#include <unordered_map>

using std::unordered_map;

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

vector<int> Solution::twoSum_map(vector<int>& numbers, int target)
{
    unordered_map<int, int> data;
    for (int i = 0; i < numbers.size(); i++)
    {
        auto another_target = target - numbers[i];
        if (data.find(another_target) != data.end())
        {
            return {data[another_target] + 1, i + 1};
        }
        data[numbers[i]] = i;
    }
    return {};
}

bool Solution::judgeSquareSum(int c)
{
    int left = 0;
    int right = static_cast<int>(sqrt(c));
    while (left <= right)
    {
        int cur_pow = pow(left, 2) + pow(right, 2);
        if (cur_pow == c)
            return true;
        if (cur_pow > c)
            right--;
        else
            left++;
    }
    return false;
}