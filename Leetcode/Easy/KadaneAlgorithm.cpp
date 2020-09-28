#include <bits/stdc++.h>
using namespace std;

// IF MAXIMUM SUM CAN BE NEGATIVE
int maxSubArray(vector<int> &nums)
{
    int max_current = nums[0];
    int max_global = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        max_current = max(nums[i], max_current + nums[i]);
        max_global = max(max_global, max_current);
    }

    return max_global;
}

// IF MAXIMUM SUM CAN'T BE NEGATIVE
int maxSubArray(vector<int> &nums)
{
    int max_current = nums[0];
    int max_global = INT_MIN;
    int n = nums.size();
    for (int i : nums)
    {
        max_current += i;
        max_global = max(max_global, max_current);
        if (max_current < 0)
            max_current = 0;
    }

    return max_global;
}
