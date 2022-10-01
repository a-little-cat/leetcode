#include "Solution.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::tolower;
using std::swap;
using std::max;
using std::min;
using std::cout;
using std::endl;

template <typename T>
void print_vector(vector<T>& nums)
{
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
}

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

int Solution::searchRotate(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] > nums[right])
            if (nums[left] <= target && target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        else
        {
            if (nums[mid] <= target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
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

int quick(vector<int>& nums, int left, int right)
{
    int out = left;
    int left_index = left + 1;
    for (int i = left + 1; i <= right; i++)
        if (nums[i] < nums[out])
            swap(nums[i], nums[left_index++]);
    swap(nums[out], nums[left_index - 1]);
    return left_index - 1;
}

void quickSort_(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int index = quick(nums, left, right);
        quickSort_(nums, left, index - 1);
        quickSort_(nums, index + 1, right);
    }
}

int Solution::quickSort(vector<int>& nums)
{
    quickSort_(nums, 0, nums.size() - 1);
    return 0;
}

int Solution::longestCommonSubsequence(string text1, string text2)
{
    int dp[text2.size() + 1];
    for (int i = 0; i < text2.size() + 1; i++)
        dp[i] = 0;

    for (int i = 0; i < text1.size(); i++)
    {
        int upleft = dp[0];
        for (int j = 1; j < text2.size() + 1; j++)
        {
            int tmp = dp[j];
            if (text1[i] == text2[j - 1])
                dp[j] = upleft + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            upleft = tmp;
        }
    }
    return dp[text2.size()];
}

string Solution::lCS(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int index = -1;
    int max_length = -1;
    for (int i = 1; i <= text1.size(); i++)
        for (int j = 1; j <= text2.size(); j++)
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length)
                {
                    max_length = dp[i][j];
                    index = i - max_length;
                }
            }
            else
                dp[i][j] = 0;

    return text1.substr(index, max_length);
}

int Solution::findMin(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}

int Solution::findMin2(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right--;
    }
    return nums[left];
}

ListNode* Solution::reverseList(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int partition(vector<int>& nums, int left, int right)
{
    int pivotIndex = random() % (right - left + 1) + left;
    swap(nums[pivotIndex], nums[right]);

    int storeIndex = left;
    for (int i = left; i <= right - 1; i++)
    {
        printf("%d -> %d   %d -> %d\n", storeIndex, nums[storeIndex], i, nums[i]);
        if (nums[i] < nums[right])
            swap(nums[i], nums[storeIndex++]);
        print_vector<int>(nums);
    }
    swap(nums[right], nums[storeIndex]);
    print_vector<int>(nums);
    return storeIndex;
}

void quickSort_wiki_(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(nums, left, right);
        quickSort_wiki_(nums, left, pivotIndex - 1);
        quickSort_wiki_(nums, pivotIndex + 1, right);
    }
}

int Solution::quickSort_wiki(vector<int>& nums)
{
    quickSort_wiki_(nums, 0, nums.size() - 1);

    return 0;
}
