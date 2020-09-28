// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> coordinates = {{-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2}};
    if (coordinates.size() <= 2)
    {
        cout << "true\n";
        return 0;
    }
    int dy, dx;
    float initial_slope;
    dy = coordinates[1][1] - coordinates[0][1];
    dx = coordinates[1][0] - coordinates[0][0];

    if (dx == 0)
    {
        initial_slope = INT_MAX;
    }
    else
    {
        initial_slope = (float)dy / dx;
    }
    for (int i = 2; i < coordinates.size(); i++)
    {
        float slope;
        dy = coordinates[i][1] - coordinates[i - 1][1];
        dx = coordinates[i][0] - coordinates[i - 1][0];
        if (dx == 0 && initial_slope != INT_MAX)
        {
            cout << "false\n";
            return 0;
        }
        else if (dx == 0 && initial_slope == INT_MAX)
        {
            slope = INT_MAX;
            continue;
        }
        else
        {
            slope = (float)dy / dx;
        }
        if (slope != initial_slope)
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}

// int main()
// {
//     vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
//     int n = coordinates.size();
//     if (coordinates.size() <= 2)
//     {
//         cout << "true\n";
//         return 0;
//     }
//     int first_slope = (coordinates[n/2][0] - coordinates[0][0]) / (coordinates[n/2][1] - coordinates[0][1]);

//     int second_slope
//     cout << "true\n";
//     return 0;
// }