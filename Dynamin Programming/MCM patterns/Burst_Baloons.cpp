#include <bits/stdc++.h>
using namespace std;

// Tabulation
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