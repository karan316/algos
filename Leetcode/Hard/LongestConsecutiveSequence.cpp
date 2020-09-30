#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hash_set;
        for (int num : nums)
            hash_set.insert(num);
        int max_count = 0;
        for (int num : nums)
        {
            //             calculate only if num -1 does not exist in the hash set.(to start counting from the minimal possible number)
            if (!hash_set.count(num - 1))
            {
                int current_num = num;
                int current_count = 1;
                //                 for every consecutive number in the hash set increment local count
                while (hash_set.count(current_num + 1))
                {
                    current_num++;
                    current_count++;
                }
                //                 change max_count if the new count is greater
                max_count = max(current_count, max_count);
            }
        }
        return max_count;
    }
};