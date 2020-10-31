#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int t = 0, i;
        for (i = 0; i < nums.size(); i++)
            t ^= nums[i];
        return t;
    }
};