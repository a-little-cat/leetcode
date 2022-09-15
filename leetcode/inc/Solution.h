#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution
{
public:
    static int test(int input);
    static vector<int> twoSum(vector<int>& numbers, int target);
    static vector<int> twoSum_map(vector<int>& numbers, int target);
    static bool judgeSquareSum(int c);
    static string reverseVowels(string s);
    static int search(vector<int>& nums, int target);
    static int searchInsert(vector<int>& nums, int target);
    static int mergeSort(vector<int>& nums);
    static int quickSort(vector<int>& nums);
};