// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

// Example 1:
// Input:
// image =[[1,1,1],
// [1,1,0],
// [1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output:[[2,2,2],
// [2,2,0],
// [2,0,1]]
// Explanation:
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.

#include <bits/stdc++.h>

using namespace std;

void paintImage(vector<vector<int>> &image, int sr, int sc, int newColor, int startColor, set<pair<int, int>> &visited)
{
    if (sc < 0 || sc > image[0].size() - 1 || sr < 0 || sr > image.size() - 1 || image[sr][sc] != startColor)
        return;

    if (visited.find(make_pair(sr, sc)) != visited.end())
    {
        return;
    }
    visited.insert(make_pair(sr, sc));
    image[sr][sc] = newColor;

    paintImage(image, sr - 1, sc, newColor, startColor, visited);
    paintImage(image, sr, sc + 1, newColor, startColor, visited);
    paintImage(image, sr + 1, sc, newColor, startColor, visited);
    paintImage(image, sr, sc - 1, newColor, startColor, visited);
}

int main()
{
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    int sr = 1, sc = 1;
    int newColor = 2;

    int startColor = image[sr][sc];

    // unordered_set<pair<int, int>> visited;
    set<pair<int, int>> visited;

    paintImage(image, sr, sc, newColor, startColor, visited);

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << "\t";
        }
        cout << "\n";
    }
}