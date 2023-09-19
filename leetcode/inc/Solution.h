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

void print_listnode(ListNode* v);
ListNode* vector_listnode(vector<int>&& nums);

class Solution
{
public:
    static int test(int input);
    static vector<int> twoSum(vector<int>&& nums, int target);
    static vector<int> twoSum_map(vector<int>& numbers, int target);
    static bool judgeSquareSum(int c);
    static string reverseVowels(string s);
    static int search(vector<int>&& nums, int target);
    // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    static int searchRotate(vector<int>&& nums, int target);
    static int searchInsert(vector<int>& nums, int target);
    static int mergeSort(vector<int>& nums);
    static int quickSort(vector<int>& nums);
    static int quickSort_wiki(vector<int>& nums);
    static int quickSort_oi(vector<int>& nums);
    static int longestCommonSubsequence(string text1, string text2);
    static string lCS(string text1, string text2);
    // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    static int findMin(vector<int>&& nums);
    // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
    static int findMin2(vector<int>&& nums);
    static ListNode* reverseList(ListNode* head);
    static ListNode* reverseList_test(ListNode* head);
    static int findKth(vector<int>& nums, int k);
    static bool isValid(string s);
    static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    static ListNode* deleteDuplicates(ListNode* head);
    static ListNode* removeNthFromEnd(ListNode* head, int n);
    static ListNode* swapPairs(ListNode* head);
    static ListNode* reverseKGroup(ListNode* head, int k);
};