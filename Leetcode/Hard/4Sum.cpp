#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //     GIVES extra quadruplets
    //     vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //         map<pair<int,int> , int> pair_sum;
    //         vector<vector<int>> result;
    //         // unordered_map<int, vector<int> ) check_quadruplet;
    //         int n = nums.size();
    //         sort(nums.begin(), nums.end());
    //         for(int i=0;i<n-1 ;i++) {
    //             for(int j=i+1;j<n;j++) {
    //                 if(pair_sum.find(pair<int,int>(nums[i],nums[j])) == pair_sum.end()) {
    //                     pair_sum.insert(make_pair(pair<int,int>(nums[i], nums[j]), nums[i]+nums[j]));
    //                 }
    //             }
    //         }
    //         for(auto it : pair_sum) {
    //             cout<<"["<<it.first.first<<","<<it.first.second<<"] "<<it.second<<endl;
    //         }
    //         for(auto it1 = pair_sum.begin(); it1 != pair_sum.end(); it1++) {
    //             for(auto it2 = next(it1); it2 != pair_sum.end();it2++) {
    //                 if((*it1).second + (*it2).second == target) {
    //                     vector<int> a;
    //                     a.push_back((*it1).first.first);
    //                     a.push_back((*it1).first.second);
    //                     a.push_back((*it2).first.first);
    //                     a.push_back((*it2).first.second);
    //                     sort(a.begin(), a.end());
    //                     if(find(result.begin(), result.end(), a) == result.end()) {
    //                         result.push_back(a);
    //                         continue;
    //                     }
    //                 }
    //             }
    //         }
    //         return result;

    //     }
    //     BRUTE FORCE: sort -> three pointers(3 for loops) find the remainder using binary_search in the elements after 3rd pointer(N^3logN)
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     vector<vector<int>> result;
    //     if(nums.empty())
    //         return result;
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     for(int i=0;i<n;i++) {
    //         for(int j = i+1;j<n;j++) {
    //             int left =j+1;
    //             int right = n-1;
    //             while(left < right) {
    //                 if(nums[i]+nums[j]+nums[left]+nums[right] == target) {
    //                     vector<int> quadruplet(4,0);
    //                     quadruplet[0] = nums[i];
    //                     quadruplet[1] = nums[j];
    //                     quadruplet[2] = nums[left];
    //                     quadruplet[3] = nums[right];
    //                     result.push_back(quadruplet);
    //                     while(left<right && nums[left] == quadruplet[2]) left++;
    //                     while(left<right && nums[right] == quadruplet[3]) right--;
    //                 } else if(nums[left]+nums[right] < target - nums[i]-nums[j]) {
    //                     left++;
    //                 } else {
    //                     right--;
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target_2 = target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < target_2)
                    {
                        left++;
                    }
                    else if (two_sum > target_2)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        result.push_back(quadruplet);
                        //                      Skipping duplicates and move left and right pointers
                        while (left < right && nums[left] == quadruplet[2])
                            left++;
                        while (left < right && nums[right] == quadruplet[3])
                            right--;
                    }
                    //                  Skipping duplicates for j
                    while (j + 1 < n && nums[j + 1] == nums[j])
                        j++;
                }
                //                  Skipping duplicates for i
                while (i + 1 < n - 1 && nums[i + 1] == nums[i])
                    i++;
            }
        }
        return result;
    }
};