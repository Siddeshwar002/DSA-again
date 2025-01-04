#include <bits/stdc++.h>
using namespace std;

// ! Tabulation : TLE

int superEggDrop(int k, int n)
{
    // dp[i][j] represents the minimum attempts needed with i eggs and j floors
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i)
    {
        // With 1 egg, the worst-case attempts are equal to the number of floors
        for (int j = 1; j <= n; ++j)
        {
            // if you have only one EGG
            // Worst case possibilities
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int x = 1; x <= j; ++x)
                {
                    // Dropping the egg from floor x:
                    // If the egg breaks, search in floors below x with i-1 eggs remaining (dp[i-1][x-1])
                    // If the egg doesn't break, search in floors above x with i eggs remaining (dp[i][j-x])
                    int attempts = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                    // Update the minimum attempts required
                    dp[i][j] = min(dp[i][j], attempts);
                }
            }
        }
    }

    return dp[k][n];
}
