#include <bits/stdc++.h>
using namespace std;

// * 186/190 testcase passed
// * CODE WORKS but,
// ! Memory Limit Exceeded

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = INT_MIN;

    for (int len = 0; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;

            if (i == j)
            {
                dp[i][i] = nums[i];
            }
            else
            {
                dp[i][j] = dp[i][j - 1] * dp[j][j];
            }

            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

// ! Kadanes algorithm
int maxProduct2(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        ans = max(ans, maxProd);
    }

    return ans;
}

int main()
{
    vector<int> vec = {3, 2, 1, 2, 1, -2, -13};
    cout << "ans " << maxProduct2(vec);
}