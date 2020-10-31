// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

// Example 1:

// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: [3,3,7,7,10,11,11]
// Output: 10

// Note: Your solution should run in O(log n) time and O(1) space

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            s.erase(nums[i]);
            continue;
        }
        s.insert(nums[i]);
    }
    cout << *s.begin();
}

// optimal solution
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//         int start=0,end = nums.size()-1;

//         while(start<end) {
//             int mid = ((unsigned int)start + (unsigned int)end) >> 1;
//             if(nums[mid] == nums[mid^1]) {
//                 start = mid +1;
//             } else {
//                 end = mid;
//             }
//         }

//         return nums[start];
//     }
// };

// Starting from index 0, which is even, every number has to appear in pairs (ideally) - Even-odd, even-odd, even-odd..... until
// this trend is broken by a single element.
// So if you check any odd-index and the even-index just before it, you can know whether the single
// element comes in the array after the odd-index or before the odd-index. For instance- if I check index 5, and it's previous 4,
// if they are equal, that automatically means that 0-1, 2-3, 4-5 etc are all in pairs, so the single element would be in the array arr[6:end].
// So we adjust low = mid +1 and proceed. If it wasn't equal that means that one among 0-1, 2-3, 4-5 is a single element.
// odd xor 1 = odd-1
// even xor 1 = even+1