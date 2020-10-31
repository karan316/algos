#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
   vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri; 
        if(numRows == 0)
            return tri;
        tri.push_back({1});
        if(numRows == 1)
            return tri;
        tri.push_back({1,1});
        for(int i=2;i<numRows;i++) {
            vector<int> row(i+1);
            row[0]=1;
            row[i]=1;
            for(int j=1;j < i;j++) {
                row[j] = tri[i-1][j-1] + tri[i-1][j];
            }
            tri.push_back(row);
        }
        return tri;
    }     
};

int main()
{
    Solution s;
    vector<vector<int>> result;
    int n;
    cin >> n;
    result = s.generate(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
