#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result;
        if (intervals.size() == 1)
        {
            result.push_back({intervals[0][0], intervals[0][1]});
        }
        int n = intervals.size();
        int first, second;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n - 1; i++)
        {
            first = intervals[i][0];
            second = intervals[i][1];

            while (i < n - 1 && (second >= intervals[i + 1][0]))
            {
                if (second < intervals[i + 1][1])
                    second = intervals[i + 1][1];
                if (first > intervals[i + 1][0])
                    first = intervals[i + 1][0];
                i++;
            }
            result.push_back({first, second});
        }
        if (result[result.size() - 1][1] < intervals[n - 1][1])
        {
            result.push_back({intervals[n - 1][0], intervals[n - 1][1]});
        }
        return result;
    }
};