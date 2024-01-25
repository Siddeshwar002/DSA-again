#include <bits/stdc++.h>
using namespace std;

// ! Recursive Code
// ! TLE 41/45 Passed

// ! Not able to memoiz this
// ! Its not working

class Solution
{
public:
    int minStrength(vector<vector<int>> &dungeon, int row, int col, int i, int j, int sum, int curStrength, int allStrength)
    {
        if (i >= row || j >= col)
            return INT_MAX;

        sum += dungeon[i][j];

        if (sum < 0)
            curStrength = max(curStrength, sum * (-1) + 1);

        if (i == row - 1 && j == col - 1)
        {
            allStrength = min(allStrength, curStrength);
            curStrength = INT_MIN;
            return allStrength;
        }

        int right = minStrength(dungeon, row, col, i + 1, j, sum, curStrength, allStrength);
        int down = minStrength(dungeon, row, col, i, j + 1, sum, curStrength, allStrength);

        return min(right, down);
    }

    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int row = dungeon.size();
        int col = dungeon[0].size();
        int ans = minStrength(dungeon, row, col, 0, 0, 0, INT_MIN, INT_MAX);
        if (ans == INT_MIN)
            return 1;
        else
            return ans;
    }
};

// ! ****************************************************************************
// ! Memoization
// * Beats : 83 %

class Solution
{
public:
    int pre(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i >= n + 1 or j >= m + 1)
            return 1e9;
        
        if (i == n and j == m)
            return arr[i][j] > 0 ? 1 : 1 - arr[i][j];
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = pre(i + 1, j, n, m, arr, dp);
        int right = pre(i, j + 1, n, m, arr, dp);
        
        int res = min(down, right) - arr[i][j];
        
        return dp[i][j] = res > 0 ? res : 1;
    }

    int calculateMinimumHP(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return pre(0, 0, n - 1, m - 1, arr, dp);
    }
};

// ! ****************************************************************************
// ! Tabulation

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n; i >= 0; i--)
        {
            dp[i][m] = 1e9;
        }
        for (int j = m; j >= 0; j--)
        {
            dp[n][j] = 1e9;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 and j == m - 1)
                {
                    dp[i][j] = arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                    continue;
                }
                int down = dp[i + 1][j];
                int right = dp[i][j + 1];
                int res = min(down, right) - arr[i][j];
                dp[i][j] = res > 0 ? res : 1;
            }
        }

        return dp[0][0];
    }
};