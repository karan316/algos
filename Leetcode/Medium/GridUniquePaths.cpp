#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int countUniquePaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
    //     if(i >= m || j>=n)
    //         return 0;
    //     if(i == m-1 && j == n-1)
    //         return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = countUniquePaths(i+1, j, m, n, dp) + countUniquePaths(i, j+1, m ,n, dp);
    // }
    //     YOU SOLVED THIS!
    int uniquePaths(int m, int n)
    {
        // if(m ==1 && n==1)
        //     return 1;
        // vector<vector<int>> dp(m , vector<int>(n,0));
        // dp[0][0] = 0;
        // for(int i=1;i<n;i++) {
        //     dp[0][i] = 1;
        // }
        // for(int i =1;i<m;i++) {
        //     dp[i][0] = 1;
        // }
        // for(int i=1;i<m;i++) {
        //     for(int j=1;j<n;j++) {
        //         dp[i][j] = dp[i][j-1] + dp[i-1][j];
        //     }
        // }
        // return dp[m-1][n-1];
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return countUniquePaths(0, 0, m, n, dp);
        //         EDITORIAL
        // There can be m-1 + n-1 = m+n-2 unique paths. There will always be n-1 rightward direction. similarly m-1 downward direction.

        // r can be min of m-1, n-1
        // 10C3 = 8x9x10/3x2x1, 8C2 = 7x8/2x1 (numerator is multiplication of last r digits till N)
        int N = m + n - 2;
        int r = m - 1;
        double ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * (N - r + i) / i;
        }
        return (int)ans;
    }
};