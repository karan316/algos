#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    unordered_set<int> num_set;
    for (auto i : nums)
    {
        if (num_set.find(i) != num_set.end())
        {
            cout << "duplicate found";
            return 0;
        }
        num_set.insert(i);
    }
    cout << "No duplicates";
}