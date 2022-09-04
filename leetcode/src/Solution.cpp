#include "Solution.h"
#include <cctype>
#include <cmath>
#include <unordered_map>

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
