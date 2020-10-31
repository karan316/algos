class Solution
{
public:
    void setColZero(vector<vector<int>> &matrix, int col)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            matrix[i][col] = 0;
        }
    }
    void setRowZero(vector<vector<int>> &matrix, int row)
    {
        int n = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            matrix[row][i] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<bool> rows(r + 1);
        vector<bool> cols(c + 1);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            if (rows[i] == true)
            {
                setRowZero(matrix, i);
            }
        }
        for (int i = 0; i < c; i++)
        {
            if (cols[i] == true)
            {
                setColZero(matrix, i);
            }
        }
    }
};