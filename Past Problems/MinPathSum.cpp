#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    // ios_base::sync_with_stdio(false);
    // cin.tie(false);
    // cout.tie(false);
    int rows = grid.size() - 1;
    int cols = grid[0].size() - 1;
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

    for (int i = rows; i >= 0; i--)
    {
        for (int j = cols; j >= 0; j--)
        {
            if ((i == rows) && (j != cols))
            {
                dp[i][j] = grid[i][j] + dp[i][j + 1];
            }
            else if ((j == cols) && (i != rows))
            {
                dp[i][j] = grid[i][j] + dp[i + 1][j];
            }
            else if ((i == rows) && (j == cols))
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}