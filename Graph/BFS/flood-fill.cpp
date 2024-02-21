#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void floodFillUtil(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        // no necessity of a Visited matrix
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor || image[sr][sc] == newColor)
        {
            return;
        }

        // Update the color
        image[sr][sc] = newColor;

        // Visit all four neighboring pixels
        floodFillUtil(image, sr - 1, sc, newColor, oldColor); // Up
        floodFillUtil(image, sr + 1, sc, newColor, oldColor); // Down
        floodFillUtil(image, sr, sc - 1, newColor, oldColor); // Left
        floodFillUtil(image, sr, sc + 1, newColor, oldColor); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        floodFillUtil(image, sr, sc, newColor, oldColor);
        return image;
    }
};
