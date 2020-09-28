#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> exists;

// abcabcbb
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;
    vector<int> count(300, 0);
    int i = 0, j = 0, max_length = 1;
    count[s[0]]++;
    while (j != n - 1)
    {
        if (count[s[j + 1]] == 0)
        {
            j++;
            count[s[j]] = 1;
            max_length = max(max_length, j - i + 1);
        }
        else
        {
            count[s[i]]--;
            i++;
        }
    }
    return max_length;
}

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        exists[c] = 0;
    }
    int result = lengthOfLongestSubstring(s);
    cout << s << endl;
}