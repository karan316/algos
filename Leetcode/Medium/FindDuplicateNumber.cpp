#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // unordered_map<int,int> count;
        // for(int i: nums) {
        //     if(count[i] == 1)
        //         return i;
        //     count[i]++;
        // }
        // return -1;
        // int n = nums.size();
        // for(int i=0;i<n-1;i++) {
        //     for(int j=i+1;j<n;j++) {
        //         if((nums[i] ^ nums[j]) == 0) {
        //             cout<<nums[i]<<"^"<<nums[j]<<" = "<<(nums[i] ^ nums[j]);
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i=1;i<n;i++) {
        //     if((nums[i-1] ^ nums[i]) == 0)
        //         return nums[i];
        // }
        // return -1;
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};