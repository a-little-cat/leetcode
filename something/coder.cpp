#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    int l = 0;
    int r = 0;
    int max_length = 1;

    while (r < s.length())
    {
        if (s[r] == 'a')
            a++;
        else
            b++;
        if (a <= m || b <= m)
            r++;
        else
        {
            if (r - l > max_length)
                max_length = r - l;
            if (s[l] == 'a')
                a--;
            else
                b--;
            r++;
            l++;
        }
    }
    printf("%d\n", max_length);
    return 0;
}