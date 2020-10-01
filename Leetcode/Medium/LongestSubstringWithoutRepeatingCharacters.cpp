#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        unordered_map<char, int> count;
        int i = 0, j = 0, max_length = 1;
        //         the first character is atleast there in the beginning
        count[s[0]]++;
        while (j < n - 1)
        {
            //             if the next character is unique increase the sliding window from front
            if (count[s[j + 1]] == 0)
            {
                count[s[j + 1]]++;
                j++;
                //                 increase the max length
                max_length = max(max_length, j - i + 1);
            }
            else
            {
                //                 if it is a repeating character decrease the window from behind which reduces the count
                count[s[i]]--;
                i++;
            }
        }
        return max_length;
    }
};
