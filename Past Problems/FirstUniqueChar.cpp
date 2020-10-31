#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "loveleetcode";
    map<char, int> map;

    for (auto ch : s)
    {
        map[ch]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (map[s[i]] == 1)
        {
            cout << s[i] << " " << i << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
}