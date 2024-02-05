// https://leetcode.com/problems/regular-expression-matching/description/?envType=featured-list&envId=top-interview-questions?envType=featured-list&envId=top-interview-questions

#include <bits/stdc++.h>
using namespace std;

// Memoization
// Accepted

class Solution
{
public:
    bool solve(string s, string p, int idx1, int idx2, vector<vector<int>> &memo)
    {

        if (idx1 <= 0 && idx2 <= 0)
            return 1;

        if (idx2 <= 0)
            return 0;

        if (memo[idx1][idx2] != -1)
        {
            return memo[idx1][idx2];
        }

        bool result = false;

        if (idx1 > 0 && (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '.'))
            return solve(s, p, idx1 - 1, idx2 - 1, memo);

        else if (p[idx2 - 1] == '*')
        {

            if (idx1 > 0 && (s[idx1 - 1] == p[idx2 - 2] || p[idx2 - 2] == '.'))
            {

                bool CS = 0, CM = 0, NC = 0;
                CS = solve(s, p, idx1 - 1, idx2, memo);
                CM = solve(s, p, idx1 - 1, idx2 - 2, memo);
                NC = solve(s, p, idx1, idx2 - 2, memo);

                result = (CS || CM || NC);
            }
            else
                result = solve(s, p, idx1, idx2 - 2, memo);
        }
        return memo[idx1][idx2] = result ? 1 : 0;
    }

    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return solve(s, p, n, m, memo);
    }
};

// **************************************************************************************************
// Tabulation
// Accepted

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n1 = s.length();
        int n2 = p.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int idx1 = 0; idx1 <= n1; idx1++)
        {
            for (int idx2 = 0; idx2 <= n2; idx2++)
            {
                if (idx1 == 0 && idx2 == 0)
                {
                    dp[idx1][idx2] = 1;
                }
                else if (idx2 > 1 && p[idx2 - 1] == '*')
                {
                    dp[idx1][idx2] = dp[idx1][idx2 - 2];
                }
            }
        }

        for (int idx1 = 1; idx1 <= n1; idx1++)
        {

            for (int idx2 = 1; idx2 <= n2; idx2++)
            {
                bool result = false;

                if (idx1 > 0 && (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '.'))
                    result = dp[idx1 - 1][idx2 - 1];
                //  solve(s, p, idx1-1, idx2-1 , memo);

                else if (p[idx2 - 1] == '*')
                {

                    if (idx1 > 0 && (s[idx1 - 1] == p[idx2 - 2] || p[idx2 - 2] == '.'))
                    {

                        bool CS = 0, CM = 0, NC = 0;
                        CS = dp[idx1 - 1][idx2];
                        // solve(s, p, idx1-1 , idx2, memo)
                        CM = dp[idx1 - 1][idx2 - 2];
                        // solve(s, p, idx1-1, idx2-2, memo)
                        NC = dp[idx1][idx2 - 2];
                        // solve(s, p, idx1, idx2-2, memo)

                        result = (CS || CM || NC);
                    }
                    else
                        result = dp[idx1][idx2 - 2];
                    // solve(s, p, idx1, idx2-2, memo)
                }
                dp[idx1][idx2] = result ? 1 : 0;
            }
        }
        return dp[n1][n2];
    }
};
