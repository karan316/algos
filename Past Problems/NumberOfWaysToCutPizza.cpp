// Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.

// For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
// Example 2:

// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1
// Example 3:

// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1

class Solution
{
    int n, m;
    long long MOD = 1000000007;
    vector<vector<int>> s;
    vector<vector<vector<long long>>> dp;

    long long solve(int a, int b, int step)
    {
        if (dp[a][b][step] != -1)
            return dp[a][b][step];
        if (step == 0)
        {
            if (s[a][b] > 0)
                dp[a][b][step] = 1;
            else
                dp[a][b][step] = 0;
            return dp[a][b][step];
        }

        long long sum = 0, i, j, k;
        for (i = a + 1; i < n; i++)
        {
            if (s[a][b] != s[i][b])
            {
                sum = (sum + solve(i, b, step - 1)) % MOD;
            }
        }

        for (i = b + 1; i < m; i++)
        {
            if (s[a][b] != s[a][i])
            {
                sum = (sum + solve(a, i, step - 1)) % MOD;
            }
        }
        dp[a][b][step] = sum;
        return sum;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        n = pizza.size(), m = pizza[0].length();
        s.assign(n + 1, vector<int>(m, 0));

        int i, j;
        for (i = n - 1; i >= 0; i--)
        {
            int ss = 0;
            for (j = m - 1; j >= 0; j--)
            {
                if (pizza[i][j] == 'A')
                    ss++;
                s[i][j] = s[i + 1][j] + ss;
            }
        }

        dp.assign(n, vector<vector<long long>>(m, vector<long long>(k, -1)));

        solve(0, 0, k - 1);

        int ans = dp[0][0][k - 1];
        return ans;
    }
};
