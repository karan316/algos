#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        //         if size 1 => return nums[0] if size 0 => return 0
        if (n < 2)
            return n ? nums[0] : 0;
        //         Maximum of two house rob algorithms
        return max(robHouses(nums, 0, n - 2), robHouses(nums, 1, n - 1));
    }

private:
    //     House Robber Algorithm
    int robHouses(vector<int> &nums, int first, int last)
    {
        int lastHouseMoney = 0, secondLastHouseMoney = 0;

        for (int i = first; i <= last; i++)
        {
            //             either take the previous house money or the sum of the house before previous and the current house money
            int nextHouseMoney = max(lastHouseMoney, secondLastHouseMoney + nums[i]);
            //             move the house pointers
            secondLastHouseMoney = lastHouseMoney;
            lastHouseMoney = nextHouseMoney;
        }

        return lastHouseMoney;
    }
};

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
}