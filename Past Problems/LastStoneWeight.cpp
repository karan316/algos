#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int n = stones.size();
    while (stones.size() > 1)
    {
        sort(stones.begin(), stones.end());
        if (stones[n - 2] == stones[n - 1])
        {
            stones.erase(stones.begin() + (n - 2), stones.begin() + (n));
            n = n - 2;
        }
        else if (stones[n - 2] != stones[n - 1])
        {
            stones[n - 1] = stones[n - 1] - stones[n - 2];
            stones.erase(stones.begin() + (n - 2));
            n--;
        }
    }
    if (stones.empty())
    {
        cout << "empty";
    }
    else
    {
        cout << stones[0];
    }
}

// 2, 2

// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1]