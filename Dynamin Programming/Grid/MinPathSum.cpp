#include <bits/stdc++.h>
using namespace std;

//   int minPath(vector<vector<int>> &grid, int i, int row, int j, int col, vector<vector<int>> &dp)
// {
//     if (i == row - 1 and j == col - 1)
//     {
//         return dp[i][j] = 0;
//     }

//     // int right = INT_MAX, down = INT_MAX;

//     if(dp[i][j] != INT_MAX) return dp[i][j];

//     if (i + 1 < row and j < col)
//         dp[i+1][j] = minPath(grid, i + 1, row, j, col, dp) + grid[i + 1][j];

//     if (i < row and j + 1 < col)
//         dp[i][j+1] = minPath(grid, i, row, j + 1, col, dp) + grid[i][j + 1];

//     return dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
// }

// ! Improvised code :

int minPath(vector<vector<int>> &grid, int i, int row, int j, int col, vector<vector<int>> &dp)
{
    if (i == row - 1 && j == col - 1)
    {
        return grid[i][j]; // Return the value at the destination cell
    }

    if (dp[i][j] != INT_MAX)
    {
        return dp[i][j];
    }

    int right = INT_MAX, down = INT_MAX;

    if (i + 1 < row)
    {
        down = minPath(grid, i + 1, row, j, col, dp);
    }

    if (j + 1 < col)
    {
        right = minPath(grid, i, row, j + 1, col, dp);
    }

    return dp[i][j] = grid[i][j] + min(right, down);
}

int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));

    return minPath(grid, 0, row, 0, col, dp);
    // return ans;
}

// ! ***********************************************************************
// ! Tabulation :

int minPathSum2(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];

            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];

            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];

            else
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
    }
    return dp[row - 1][col - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "ans : " << minPathSum(grid);
}