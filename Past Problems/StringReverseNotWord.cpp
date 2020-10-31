#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    string s;
    string result = "";
    cin >> s;
    reverse(s.begin(), s.end());
    auto startIndex = s.begin();
    auto endIndex = s.begin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            endIndex = s.begin() + i;
            reverse(startIndex, endIndex);
            startIndex = s.begin() + i + 1;
        }
    }
    startIndex = endIndex + 1;
    reverse(startIndex, s.end());
    cout << s << endl;
    // }
    return 0;
}