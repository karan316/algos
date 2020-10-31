// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

#include <bits/stdc++.h>

using namespace std;
//  up
// left    right
//     bottom

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (grid[i][j] == '0')
    {
        return;
    }
    // mark the current index to zero
    grid[i][j] = '0';

    // mark zeroes for the upper index
    if (i > 0 && grid[i - 1][j] == '1')
    {
        dfs(grid, i - 1, j);
    }

    // mark zeroes for below index
    if (i + 1 < grid.size() && grid[i + 1][j] == '1')
    {
        dfs(grid, i + 1, j);
    }

    // mark zeroes for the left index
    if (j > 0 && grid[i][j - 1] == '1')
    {
        dfs(grid, i, j - 1);
    }
    // mark zeroes for the right index
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
    {
        dfs(grid, i, j + 1);
    }
}
int main()
{
    // dfs method
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    int num_of_islands = 0, i, j;

    for (i = 0; i < grid.size(); i++)
    {
        for (j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                // mark all the 1s that are a part of island into zeroes so that in the next iteration it does not count as an island
                dfs(grid, i, j);
                num_of_islands++;
            }
        }
    }

    return num_of_islands;
}

// errichto code BFS used
// int main()
// {
//     vector<vector<char>> grid = {
//         {'1', '1', '1', '1', '0'},
//         {'1', '1', '0', '1', '0'},
//         {'1', '1', '0', '0', '0'},
//         {'0', '0', '0', '0', '0'}};
//     if (grid.empty() || grid[0].empty())
//     {
//         return 0;
//     }
//     int H = grid.size();
//     int W = grid[0].size();

//     int num_of_islands = 0;
//     auto inside = [&](int row, int col) { return 0 <= row && row < H && 0 <= col && col < W; };

//     vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     vector<vector<bool>> vis(H, vector<bool>(W));
//     for (int row = 0; row < H; row++)
//     {
//         for (int col = 0; col < W; col++)
//         {
//             if (!vis[row][col] && grid[row][col] == '1')
//             {
//                 num_of_islands++;
//                 queue<pair<int, int>> q;
//                 q.push({row, col});
//                 vis[row][col] = true;

//                 while (!q.empty())
//                 {
//                     pair<int, int> p = q.front();
//                     q.pop();

//                     for (pair<int, int> dir : directions)
//                     {
//                         int new_row = p.first + dir.first;
//                         int new_col = p.second + dir.second;
//                         if (inside(new_row, new_col) && !vis[new_row][new_col] && grid[new_row][new_col] == '1')
//                         {
//                             q.push({new_row, new_col});
//                             vis[new_row][new_col] = true;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     return num_of_islands;
// }