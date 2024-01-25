#include <bits/stdc++.h>
using namespace std;

// ! 1
int LCS(int i, int j, string s1, string s2)
{
    if (i >= s1.length() or j >= s2.length())
        return 0;

    if (s1[i] == s2[j])
    {
        return 1 + LCS(i + 1, j + 1, s1, s2);
    }
    else
    {
        return max(LCS(i, j + 1, s1, s2), LCS(i + 1, j, s1, s2));
    }
}

// int longestCommonSubsequence(string text1, string text2)
// {
//     return LCS(0, 0, text1, text2);
// }

// ! DP = Memoization
// * 46 / 47 testcases passed

int LCS(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i >= s1.length() or j >= s2.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2, dp);
    }
    else
    {
        return dp[i][j] = max(LCS(i, j + 1, s1, s2, dp), LCS(i + 1, j, s1, s2, dp));
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = (text1.size() > text2.size()) ? text1.size() : text2.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return LCS(0, 0, text1, text2, dp);
}

// ! DP - Tabulation
int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}