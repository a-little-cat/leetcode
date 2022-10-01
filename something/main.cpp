
int quickSork(vector<int>& a, int start, int end, int K)
{
    int value_index = start;
    int left = start + 1;
    int right = end;
    while (left <= right)
    {
        while (a[value_index] > a[left] && left <= right)
        {
            swap(a[value_index], a[left]);
            value_index = left;
            left++;
        }
        while (a[value_index] > a[right] && left <= right)
        {
            swap(a[value_index], a[right]);
            value_index = right;
            right--;
        }
    }
    if (value_index == (a.size() - K))
        return a[left];
    if (value_index < (a.size() - K))
        quickSork(a, left + 1, end, K);
    else
        quickSork(a, left, end - 1, K);
    return -1;
}

class Solution
{
public:
    int findKth(vector<int> a, int n, int K)
    {
        // write code here
        int index = quickSork(a, 0, n - 1, K);

        return a[index];
    }
};
