#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            if (target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};