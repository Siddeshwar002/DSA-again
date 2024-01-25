#include <bits/stdc++.h>
using namespace std;

// ! Memoization
// ! Time Limit Exceeded

// ! 3D DP Table

class Solution
{
public:
    vector<int> countNum(string s)
    {
        int len = s.length();
        int cnt = 0;

        for (auto it : s)
        {
            if (it == '0')
                cnt++;
        }
        return {cnt, len - cnt};
    }

    int largestSubset(vector<string> &strs, int idx, int m, int n, int cur_m, int cur_n, unordered_map<string, int> &memo)
    {
        if (idx == strs.size())
            return 0;

        // ! 3D DP Table
        string key = to_string(idx) + "_" + to_string(cur_m) + "_" + to_string(cur_n);
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        int consider = 0, notConsider = 0;

        vector<int> count = countNum(strs[idx]);

        if (count[0] + cur_m <= m && count[1] + cur_n <= n)
        {
            consider = largestSubset(strs, idx + 1, m, n, cur_m + count[0], cur_n + count[1], memo) + 1;
        }

        notConsider = largestSubset(strs, idx + 1, m, n, cur_m, cur_n, memo);

        memo[key] = max(consider, notConsider);

        return memo[key];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        unordered_map<string, int> memo;
        return largestSubset(strs, 0, m, n, 0, 0, memo);
    }
};

// ! *********************************************************************************
// * Tabulation

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (const string &s : strs)
    {
        int count0 = count(s.begin(), s.end(), '0');
        int count1 = count(s.begin(), s.end(), '1');

        // * Update the table for each (m, n) pair based on the current string
        for (int i = m; i >= count0; --i)
        {
            for (int j = n; j >= count1; --j)
            {
                dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
            }
        }
    }

    return dp[m][n];
}