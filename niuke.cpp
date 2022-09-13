#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> output(1);
    cin >> output[0];
    for (int i = 0; i < n - 1; i++)
    {
        int data = 0;
        int index = 0;
        cin >> data >> index;
        output.insert(find(output.begin(), output.end(), index) + 1, data);
    }
    cin >> n;
    for (auto i : output)
        if (i - n)
            cout << i << " ";
    cout << endl;
}
