// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> res;
    if (nums.empty())
        return 0;
    // map from value->index
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++)
    {
        int rest = target - nums[i];
        if (hashmap.find(rest) == hashmap.end())
            // not found then insert into the hashmap
            hashmap.insert(pair<int, int>(nums[i], i));
        else
        {
            // found
            res.push_back(i);
            res.push_back(hashmap[rest]);
        }
    }

    for (auto i : res)
    {
        cout << i << " ";
    }
}