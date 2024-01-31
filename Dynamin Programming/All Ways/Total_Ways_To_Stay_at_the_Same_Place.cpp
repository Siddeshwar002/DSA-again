#include <bits/stdc++.h>
using namespace std;

// Recursive
// Memo
class Solution
{
public:
    int totalWays(int i, int steps, int n)
    {
        if (i < 0 || i > n - 1)
            return 0;

        if (i == 0 && steps == 0)
            return 1;

        int ans = 0;

        for (int k = -1; k <= 1; k++)
        {
            ans += totalWays(i + k, steps - 1, n);
        }
        return ans;
    }

    int numWays(int steps, int arrLen)
    {
        return totalWays(0, steps, arrLen);
    }
};

// ************************************************************************
// Tabulation :

class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        const int MOD = 1e9 + 7;
        int maxLen = min(steps / 2 + 1, arrLen);

        vector<vector<int>> dp(steps + 1, vector<int>(maxLen + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= steps; ++i)
        {
            for (int j = 0; j < maxLen; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                // Move to the current position from the same position in the previous step
                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                    // Move to the current position from the left in the previous step
                }
                if (j < maxLen - 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                    // Move to the current position from the right in the previous step
                }
            }
        }

        return dp[steps][0];
    }
};

int main()
{
    Solution s;
    cout << s.numWays(2, 2);
}