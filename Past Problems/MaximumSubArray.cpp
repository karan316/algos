#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//this solution passed 200/202 cases
int main()
{
    // vector<int> nums = {};
    vector<int> nums = {-1};
    int max_sum = nums.at(0);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
            max_sum = max(max_sum, accumulate(nums.begin() + i, nums.begin() + j + 1, 0));
    }

    cout << max_sum;
}

// Kadane's algorithm
// The maximum of a sub array (including negative numbers) is the either the current element or the sum of the current element and the maximum subarray sum till the previous index of current element(which ever is greater).
// correct solution
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//         int max_current = nums.at(0); //current maximum
//         int max_global= nums.at(0); //maximum sub array sum till the previous element
//         for(int i = 1; i < nums.size();i++) {
//             max_current = max(nums.at(i), max_current + nums.at(i));
//             if(max_current > max_global) {
// max_global = max_current; //update the maximum subarray sum to current maximum
//             }
//         }
//         return max_global;
//     }

// };

// int maxSubArray(vector<int> nums)
// {
//     int n = nums.size();
//     vector<int> pref(n);
//     for (int i = 0; i < n; i++)
//     {
//         pref[i] = nums[i] + (i == 0 ? 0 : pref[i - 1]);
//     }

//     int min_so_far = 0;
//     int answer = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         answer = max(answer, pref[i] - min_so_far);
//         min_so_far = min(min_so_far, pref[i]);
//     }
//     return answer;
// }
