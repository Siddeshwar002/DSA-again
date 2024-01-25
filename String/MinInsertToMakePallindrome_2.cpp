#include <bits/stdc++.h>
using namespace std;

// ! 53 / 58 testcases passed


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
