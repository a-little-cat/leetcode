#include <string>
#include <vector>
using std::vector;
using std::string;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution
{
public:
    static int test(int input);
    static vector<int> twoSum(vector<int>& numbers, int target);
    static vector<int> twoSum_map(vector<int>& numbers, int target);
    static bool judgeSquareSum(int c);
    static string reverseVowels(string s);
    static int search(vector<int>& nums, int target);
    static int searchRotate(vector<int>& nums, int target);
    static int searchInsert(vector<int>& nums, int target);
    static int mergeSort(vector<int>& nums);
    static int quickSort(vector<int>& nums);
    static int quickSort_wiki(vector<int>& nums);
    static int longestCommonSubsequence(string text1, string text2);
    static string lCS(string text1, string text2);
    static int findMin(vector<int>& nums);
    static int findMin2(vector<int>& nums);
    static ListNode* reverseList(ListNode* head);
};