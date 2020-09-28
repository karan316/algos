#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        unordered_map<char, int> map;
        int n;
        cin >> n;

        string s;
        cin >> s;

        for (char c : s)
            map[c]++;

        for (char c : s)
        {
            if (map[c] == 1)
            {
                cout << c << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
        return 0;
        t--;
    }
}