#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2, 2};

    int num_count = 0;
    for (auto i : arr)
    {
        if (find(arr.begin(), arr.end(), i + 1) != arr.end())
        {
            num_count++;
        }
    }
    cout << num_count;
}