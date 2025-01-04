// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/** Recursive Solution : */
class Solution
{
public:
    bool solve(int i, int j, string s, string p)
    {
        if (j < 0)
        {
            if (i >= 0)
            {
                while (i >= 0 && p[i] == '*')
                    i--;
                if (i >= 0)
                    return 0;
            }
            return 1;
        }

        if (i < 0)
            return 0;

        if (s[j] == p[i] || p[i] == '?')
            return solve(i - 1, j - 1, s, p);

        if (p[i] == '*')
            return (solve(i - 1, j, s, p) || solve(i, j - 1, s, p));

        return 0;
    }
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        return solve(m - 1, n - 1, s, p);
    }
};

/** Memoized Solution : 0 based indexing */
class Solution
{
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (j < 0)
        {
            if (i >= 0)
            {
                while (i >= 0 && p[i] == '*')
                    i--;
                return i < 0;
            }
            return true;
        }

        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[j] == p[i] || p[i] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        if (p[i] == '*')
            return dp[i][j] = (solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp));

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, s, p, dp);
    }
};

/** Memoized Solution : with 1-based indexing */
class Solution
{
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (j == 0)
        {
            if (i > 0)
            {
                while (i > 0 && p[i - 1] == '*')
                    i--;
                return i == 0;
            }
            return true;
        }

        if (i == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        if (p[i - 1] == '*')
            return dp[i][j] = (solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp));

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length(); // j - string
        int m = p.length(); // i - pattern

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(m, n, s, p, dp);
    }
};

/**TABULATION CODE */

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(); // j - string
        int m = p.length(); // i - pattern

        // Create a DP table with dimensions (m+1) x (n+1)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: Both strings are empty
        dp[0][0] = true;

        // Base case: Pattern is empty but the string is not
        for (int j = 1; j <= n; ++j)
            dp[0][j] = false;

        // Base case: String is empty but the pattern may contain '*'
        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] && (p[i - 1] == '*');

        // Fill the DP table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    // Characters match or pattern has '?'
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    // '*' matches zero or more characters
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    // Characters do not match
                    dp[i][j] = false;
                }
            }
        }

        // The result is in dp[m][n]
        return dp[m][n];
    }
};
