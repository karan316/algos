#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &t1,const vector<int> &t2)
{
	return (t1[1]<t2[1]) ;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2) return n;
//         sort based on second element
        sort(points.begin(), points.end(), compare);
        int count = 1;
//         keep a point to compare
        int start_point = points[0][1];
//         start from second element
        for(int i=1;i<n;i++) {
//             skip all the mergable points i.e. first ele of point covered by second ele of prev
            if(start_point >= points[i][0]) continue;
//             new arrow needed so increment count
            count++;
//             new start point
            start_point = points[i][1];
        }
        return count;
        
    }
    
};
int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
    vector<vector<int>> points = {{1, 6}, {2, 8}, {7, 12}, {10, 16}};

    Solution s;
    cout << s.findMinArrowShots(points) << endl;
}