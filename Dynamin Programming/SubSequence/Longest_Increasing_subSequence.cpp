#include <bits/stdc++.h>
using namespace std;

// ! Fails
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 1;
    // 4, 10, 4, 3, 8, 9
    for (int len = 0; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;

            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (nums[j - 1] < nums[j])
                {
                    dp[i][j] = max(dp[i][j - 1], dp[j][j]) + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[j][j]);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

// * Works
int lengthOfLIS2(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

// * Works even better
int lengthOfLIS3(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end())
            res.push_back(nums[i]);
        else
            *it = nums[i];
    }

    // for(auto it : res)
    //     cout<<it<<" ";
    // cout<<endl;

    return res.size();
}

int main()
{
    vector<int> vec = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "ans " << lengthOfLIS3(vec);
}