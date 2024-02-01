#include <bits/stdc++.h>
using namespace std;

// Scroll down to sees the exact conversion from memoization to tabulation

// Memoization
class Solution
{
public:
    int solve(string s, string t, string ans, int idx, unordered_map<string, int> &mp)
    {

        if (ans == t)
            return 1;

        if (idx == s.length())
            return 0;

        string temp = ans + "_" + to_string(idx);

        if (mp.find(temp) != mp.end())
            return mp[temp];

        int res = 0;

        for (int i = idx; i < s.length(); i++)
        {
            ans += s[i];
            res += solve(s, t, ans, i + 1, mp);
            ans.pop_back();
        }
        return mp[temp] = res;
    }

    int numDistinct(string s, string t)
    {
        unordered_map<string, int> mp;
        return solve(s, t, "", 0, mp);
    }
};

// *********************************************************************************************
// Memoization
class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &memo)
    {
        // Base cases
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;

        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int result = 0;

        if (s[i] == t[j])
            result = solve(s, t, i + 1, j + 1, memo) + solve(s, t, i + 1, j, memo);
        else
            result = solve(s, t, i + 1, j, memo);

        return memo[i][j] = result;
    }

    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return solve(s, t, 0, 0, memo);
    }
};
// *********************************************************************************************
// Tabulation

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        // vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        // the aobve give overflow error
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        // Initialize base cases
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = 1;
            // Look at the recursion
            // when j < 0 then return 1;
            // now, j = 0 and for any 'i' the answer should hold 1
            // dp[i][0] = 1
        }

        // Start the bottom up tabulation
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {

                // Copy and paste the recursion code
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};