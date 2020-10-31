#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        unordered_set<long long> set;
        long long A[n], B[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> A[i];
            set.insert(A[i]);
        }

        for (long long i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        for (long long i = 0; i < n; i++)
        {
            if (set.find(B[i]) != set.end())
            {
                set.erase(B[i]);
            }
        }

        if (!set.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << "1" << endl;
        }
    }

    return 0;
}