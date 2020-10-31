// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {

        //         OPTIMAL 1
        //         set<int> already_seen;
        //         set<int> smaller_num;

        //         if(nums.empty())
        //             return 0;
        //         for(int num : nums) {
        // assume b-a = k. if a was already seen then insert a into the set
        //             if(already_seen.count(num -k ) > 0)
        //                 smaller_num.insert(num-k);
        //          if b was already seen then insert a into the set
        //             if(already_seen.count(num +k ) > 0)
        //                 smaller_num.insert(num);
        // insert the current number
        //             already_seen.insert(num);
        //         }
        // the length of the set of smaller numbers is the answer
        //         return smaller_num.size();

        //         BEST SOLUTION
        sort(nums.begin(), nums.end());
        int j = 1;
        int i = 0;
        int count = 0;
        while (j < nums.size() && i < nums.size())
        {
            if (nums[j] - nums[i] == k)
            {
                count++;
                i++;
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1])
                    j++;
            }
            else if (nums[j] - nums[i] > k)
            {
                i++;
                if (j - i == 0)
                    j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};