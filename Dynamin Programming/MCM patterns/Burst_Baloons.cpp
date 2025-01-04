// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

using namespace std;

/** Memoization :
 *
 * TC : O(N^3)
 *
 */
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxCoins = INT_MIN;

    for (int k = i; k <= j; k++)
    {
        int coins = nums[i - 1] * nums[k] * nums[j + 1];

        int remainingCoins = maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);

        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return dp[i][j] = maxCoins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    return maxCoinsHelper(1, n, nums, dp);
}

/** Tabulation :
 *
 * TC : O(N^3)
 */

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int maxi = INT_MIN;

            for (int ind = i; ind <= j; ind++)
            {
                int coins = nums[i - 1] * nums[ind] * nums[j + 1];

                int remainingCoins = dp[i][ind - 1] + dp[ind + 1][j];

                maxi = max(maxi, coins + remainingCoins);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

/** Tabulation : */
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // including the nums[-1] and nums[n]
        int n = nums.size() + 2;
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> new_nums(n, 1);
        int i = 1;
        for (auto num : nums)
        {
            new_nums[i++] = num;
        }

        for (int len = 3; len <= n; len++)
        {
            // iterate from interval length from 3 to n
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;

                // select between left and right boundary (i, j)
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][n - 1];
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution s;
    cout << "The maximum number of coins can be obtained by using one or more sticks is: " << s.maxCoins(nums) << endl;
}