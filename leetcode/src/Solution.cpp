#include "Solution.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::tolower;
using std::swap;

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

bool isVowel(char c)
{
    int f[26] = {0};
    f['a' - 'a'] = 1;
    f['e' - 'a'] = 1;
    f['i' - 'a'] = 1;
    f['o' - 'a'] = 1;
    f['u' - 'a'] = 1;
    c = tolower(c);
    if ((c - 'a') < 0 || (c - 'a') > 25)
        return false;
    return f[c - 'a'];
}

string Solution::reverseVowels(string s)
{
    int left = 0;
    int right = static_cast<int>(s.size() - 1);
    while (true)
    {
        while (left < s.size() && !isVowel(s[left]))
            left++;
        while (right >= 0 && !isVowel(s[right]))
            right--;
        if (left >= right)
            break;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int Solution::search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
    }

    return -1;
}

int Solution::searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // printf("left:%3dright:%3dmid:%3d\n", left, right, mid);
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }

    return left;
}

void merge(vector<int>& nums, vector<int>& tmp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
        if (nums[i] < nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];

    while (i <= mid)
        tmp[k++] = nums[i++];
    while (j <= right)
        tmp[k++] = nums[j++];

    for (i = left; i <= right; i++)
        nums[i] = tmp[i];
}

void mergeSort_(vector<int>& nums, vector<int>& tmp, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort_(nums, tmp, left, mid);
        mergeSort_(nums, tmp, mid + 1, right);
        merge(nums, tmp, left, mid, right);
    }
}

int Solution::mergeSort(vector<int>& nums)
{
    vector<int> tmp(nums.size());
    mergeSort_(nums, tmp, 0, nums.size() - 1);
    return 0;
}
