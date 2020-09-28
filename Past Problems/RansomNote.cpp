#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ransomNote = "a";
    string magazine = "b";

    unordered_multiset<char> s;
    for (char ch : ransomNote)
    {
        s.insert(ch);
    }

    for (char ch : magazine)
    {
        if (!s.empty() && s.find(ch) != s.end())
        {
            s.erase(s.find(ch));
        }
    }
    if (s.empty())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}