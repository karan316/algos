#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    vector<int> q;
    vector<int> result;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        nums.push_back(ele);
    }

    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;
        q.push_back(ele);
    }

    int i = 1;
    int j = 0;
    while (!nums.empty() && j != m)
    {
        sort(nums.begin(), nums.end());
        int max = nums[nums.size() - 1];
        if (i == q[j])
        {
            result.push_back(max);
            j++;
        }
        nums[nums.size() - 1] = max / 2;
        if (nums[nums.size() - 1] == 0)
        {
            nums.erase(nums.begin() + nums.size());
        }
        i++;
    }
    cout << "Output: \n";
    for (auto n : result)
    {
        cout << n << endl;
    }
}