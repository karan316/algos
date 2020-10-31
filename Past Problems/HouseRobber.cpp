#include <bits/stdc++.h>

using namespace std;

// int rob(vector<int> &nums)
// {
//     int money = 0;
//     for (int i = 1; i < nums.size(); i += 3)
//     {
//         if (i == nums.size() - 1)
//         {
//             money += nums[i];
//         }
//         else
//         {
//             money += max(nums[i - 1] + nums[i + 1], nums[i]);
//         }
//     }
//     return money;
// }

// int rob(vector<int> nums) {
//     return rob(nums, nums.size() - 1);
// }
// int rob(vector<int> nums, int i) {
//     if (i < 0) {
//         return 0;
//     }
//     return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
// }

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> memo(nums.size() + 1);
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        // current memo value = max( of current house + loot from houses before the previous, loot from the previous house robbery and any loot captured before that )
        // memo[i+1] = loot upto currentHouse, memo[i] = loot upto prevHouse, memo[i-1] = loot upto house before prevHouse
        memo[i + 1] = max(memo[i - 1] + nums[i], memo[i]);
    }
    return memo[nums.size()];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = rob(nums);
    cout << ans << endl;
}

// A robber has 2 options: a) rob current house i; b) don't rob current house.
// If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
// If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
// So it boils down to calculating what is more profitable:

// robbery of current house + loot from houses before the previous
// loot from the previous house robbery and any loot captured before that
// rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )