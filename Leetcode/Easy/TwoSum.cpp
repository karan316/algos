#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> index;
        int n = nums.size();
        vector<int> result;
        if (n == 0)
            return result;
        //         check if complement exists in hashmap
        for (int i = 0; i < n; i++)
        {
            if (index.find(target - nums[i]) != index.end())
            {
                result.push_back(i);
                result.push_back(index[target - nums[i]]);
                return result;
            }
            else
            {
                index.insert(pair<int, int>(nums[i], i));
            }
        }
        return result;
    }
};