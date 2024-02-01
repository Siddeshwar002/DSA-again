// https://leetcode.com/problems/longest-palindromic-subsequence/description/?envType=list&envId=55afh7m7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j] && len == 2)
                    dp[i][j] = 2;

                // Macth
                // shift both the indexes
                else if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                // NO Match
                // eiher shit index 'i' or 'j'
                // consider the one which gives max of both
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[0][n - 1];
    }
};