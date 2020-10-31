#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
//     return count;
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i != j) {
                    // for every interval check if it can be merged in any of the other intervals
//                     if yes then increase count and break to avoid merging multiple times
                    if(intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
                        count++;
                        break;
                    }
                }
            }
        }
//         remaining elements = total elements - mergable elements
        return n-count;
    }
};
