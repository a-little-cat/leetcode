#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = '0' + s1;
    s2 = '0' + s2;
    int dp[s1.size()][s2.size()];
    for (int i = 0; i < s1.size(); i++)
        dp[i][0] = i;
    for (int j = 1; j < s2.size(); j++)
        dp[0][j] = j;
    for (int i = 1; i < s1.size(); i++)
        for (int j = 1; j < s2.size(); j++)
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
    cout << dp[s1.size() - 1][s2.size() - 1] << endl;
}
