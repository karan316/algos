#include <bits/stdc++.h>
using namespace std;

int main()
{
    string J = "z";
    string S = "ZZ";
    unordered_set<char> j_set;
    int jewel_count = 0;
    for (int i = 0; i < J.length(); i++)
    {
        j_set.insert(J[i]);
    }
    for (int i = 0; i < S.length(); i++)
    {
        if (j_set.find(S[i]) != j_set.end())
        {
            jewel_count++;
        }
    }
    cout << jewel_count << endl;
}
