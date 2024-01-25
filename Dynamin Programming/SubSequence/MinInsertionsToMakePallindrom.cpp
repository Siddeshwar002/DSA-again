#include <bits/stdc++.h>
using namespace std;

// * Accepted Soln

int minInsertions_Tab(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));

    for (int gap = 1; gap < s.length(); gap++)
    {
        for (int l = 0, r = gap; r < s.length(); l++, r++)
        {
            if (s[l] == s[r])
            {
                dp[l][r] = dp[l + 1][r - 1];
            }
            else
            {
                dp[l][r] = 1 + min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }
    return dp[0][s.length() - 1];
}

// ! ********************************************************************
// ! TLE

int MinInsertionsMemo(string s, int l, int r, int len, vector<vector<int>> &dp)
{
    if (l >= len || r < 0)
        return 0;

    if (l > r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int result;
    if (s[l] == s[r])
        result = MinInsertionsMemo(s, l + 1, r - 1, len, dp);
    else
        result = 1 + min(MinInsertionsMemo(s, l + 1, r, len, dp), MinInsertionsMemo(s, l, r - 1, len, dp));

    dp[l][r] = result;
    return result;
}

int minInsertions(string s)
{
    int len = s.length();
    if (len <= 1)
        return 0;

    // Create a DP array for memoization
    vector<vector<int>> dp(len, vector<int>(len, -1));

    return MinInsertionsMemo(s, 0, len - 1, len, dp);
}
