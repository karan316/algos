#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            int ind_1 = -1, ind_2 = -1;
            int n = nums.size();
            // find the first index from behind that shows descendency
            for (int i = n - 1; i > 0; i--)
            {
                if (nums[i - 1] < nums[i])
                {
                    ind_1 = i - 1;
                    break;
                }
            }
            // if we got a valid ind_1 find ind_2
            if (ind_1 != -1)
            {
                for (int i = n - 1; i > 0; i--)
                {
                    if (nums[i] > nums[ind_1])
                    {
                        ind_2 = i;
                        break;
                    }
                }
            }
            // if indices are valid then swap
            if (ind_1 != -1 && ind_2 != -1)
                swap(nums[ind_1], nums[ind_2]);
            sort(nums.begin() + ind_1 + 1, nums.end());
        }
    }
};
