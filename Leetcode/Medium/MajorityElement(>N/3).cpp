#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cand_1 = -1, cand_2 = -1, count_1 = 0, count_2 = 0;
        int n = nums.size();
        for (int i : nums)
        {
            if (cand_1 == i)
                count_1++;
            else if (cand_2 == i)
                count_2++;
            else if (count_1 == 0)
            {
                cand_1 = i;
                count_1 = 1;
            }
            else if (count_2 == 0)
            {
                cand_2 = i;
                count_2 = 1;
            }
            else
            {
                count_1--;
                count_2--;
            }
        }
        count_1 = 0, count_2 = 0;
        vector<int> result;
        for (int i : nums)
        {
            if (i == cand_1)
                count_1++;
            else if (i == cand_2)
            {
                count_2++;
            }
        }
        if (count_1 > n / 3)
            result.push_back(cand_1);
        if (count_2 > n / 3)
            result.push_back(cand_2);
        return result;
    }
};