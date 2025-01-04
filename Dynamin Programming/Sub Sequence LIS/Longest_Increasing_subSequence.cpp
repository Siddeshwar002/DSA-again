// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
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

/** Works
 * TC - O(N^2) */
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

/** Works even better
 * Binary Search Approach */
int lengthOfLIS3(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (it == res.end())
        {
            cout << nums[i] << endl;
            res.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
            cout << "N " << *it << endl;
        }
    }

    // for (auto it : res)
    //     cout << it << " ";
    // cout << endl;

    return res.size();
}

int main()
{
    vector<int> vec = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS3(vec) << endl;
}

/** Memoization code :
 * Works :
 * prev_index = -1 when idx = 0;
 * but dp[-1] is not possible
 * So shift the index
 * prev_index + 1 instead prev_index
 */
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return getAns(arr, n, 0, -1, dp);
}

/** Tabulation code:
 *
 * In Memoization :
 *      - F(index , prev_index)
 *      - prev_index was going from (-1) to (index - 1)
 *      - so when doing Tabulation :
 *      - you need to make sure the prev_idx goes from (index - 1) to (-1)
 */

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {

            int notTake = 0 + dp[ind + 1][prev_index + 1];

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {

                take = 1 + dp[ind + 1][ind + 1];
            }

            dp[ind][prev_index + 1] = max(notTake, take);
        }
    }

    return dp[0][0];
}