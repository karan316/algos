#include <bits/stdc++.h>

using namespace std;
// 2 2
// 3 1 5 4
// 5 1 2 8 9 3
// 0 1
// 1 3
int main()
{
    vector<vector<int>> a;

    int n, q;
    cout << "n, q";
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int size;
        cout << "size: ";
        cin >> size;
        vector<int> b;
        for (int j = 0; j < size; j++)
        {
            int ele;
            cout << "ele: ";
            cin >> ele;
            b.push_back(ele);
        }
        a.push_back(b);
    }
    for (int k = 0; k < q; k++)
    {
        int i = 0, j = 0;
        cout << " i,j";
        cin >> i >> j;
        cout << a[i][j];
    }
    return 0;
}