// #include <bits/stdc++.h>
#include <vector>
using namespace std;

/** MEMOIZATION */

int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n,
                       vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

/** TABULATION */

// Solution 1 Bottom up :
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // there is no out-of-bounds base condition
    // if(indices go out of the array ? ) return INT_MAX;

    // Initialize the bottom row
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // there is no out-of-bounds base condition

            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

/** Solution 2 : Top down
 *
 * Clean code
 * the way all the edge cases are handled is so good
 */

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 && j == 0)
                // no previous blocks so initialize this
                dp[0][0] = triangle[0][0];
            else if (j == 0)
                // you can only take from striaght up - dp[i-1][j]
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (i == j)
                // you can only take from left upper diagonal - dp[i-1][j-1]
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else
                // you can take from both - so you take the min from both
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}