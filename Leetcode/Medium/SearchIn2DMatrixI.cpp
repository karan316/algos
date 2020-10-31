#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int low, high, mid;
        low = 0;
        high = n * m - 1;
        while (low <= high)
        {
            mid = (low + (high - low) / 2);
            if (matrix[mid / m][mid % m] == target)
                return true;
            if (target > matrix[mid / m][mid % m])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};