#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        int ele;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            a.push_back(ele);
        }
        int one_count = 0;
        for (auto i : a)
        {
            if (i == 1)
            {
                one_count++;
            }
        }
        if (one_count > (n / 6 + 1))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        return 0;
        t--;
    }
}