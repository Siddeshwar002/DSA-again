#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;

                if (len == 2)
                {
                    dp[i][j] = min(i, j);
                    continue;
                }

                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[1][n];
    }
};

int main()
{
    Solution sol;
    cout << "Minimum money amount to make change of given denominations is :" << sol.getMoneyAmount(10) << endl;
}