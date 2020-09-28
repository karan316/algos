#include <bits/stdc++.h>

using namespace std;

int indexOf(int a[], int n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            return i;
        }
    }
}

void moveEleToStart(int P[], int index)
{
    int temp = P[index];
    for (int i = index - 1; i >= 0; i--)
    {
        P[i + 1] = P[i];
    }
    P[0] = temp;
}

int main()
{
    int queries[] = {3, 1, 2, 1};
    int m = 5;
    int P[m];
    for (int i = 0; i < m; i++)
    {
        P[i] = i + 1;
    }
    int n = sizeof(queries) / sizeof(queries[0]);
    int result[n];

    for (int i = 0; i < n; i++)
    {
        result[i] = indexOf(P, m, queries[i]);
        moveEleToStart(P, result[i]);
    }

    for (auto i : result)
    {
        cout << i << " ";
    }
}