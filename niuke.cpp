#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int table[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

    string output;
    for (auto c : input)
    {
        if (c >= 'a' && c <= 'z')
            output += table[c - 'a'] + '0';
        else if (c >= 'A' && c <= 'Y')
            output += tolower(c) + 1;
        else if (c == 'Z')
            output += 'a';
        else
            output += c;
    }
    cout << output << endl;
}
