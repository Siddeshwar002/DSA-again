#include <bits/stdc++.h>
using namespace std;

// ! HARD

// Recursive Code
// Incorrect code - very near to answer

class Solution
{
public:
    int allWays(int n, int l, int prev, int curLen, vector<int> rollMax)
    {

        if (n == l)
            return 1;

        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (prev == i && curLen == rollMax[i])
                continue;

            else if (prev == i && curLen < rollMax[i])
                curLen++;

            else if (prev != i)
                curLen = 1;

            cnt += allWays(n, l + 1, i, curLen, rollMax);
            cnt %= (int)1e9 + 7;
        }
        return cnt;
    }
    int dieSimulator(int n, vector<int> &rollMax)
    {
        return allWays(n, 0, -1, 0, rollMax);
    }
};

// **********************************************************************************************
// Correct Code
// God know what the if/else if made a difference

class Solution
{
public:
    int allWays(int n, int l, int prev, int curLen, vector<int> rollMax)
    {

        if (n == l)
            return 1;

        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (prev == i && curLen == rollMax[i])
                continue;

            if (prev == i)
            {
                cnt += allWays(n, l + 1, prev, curLen + 1, rollMax);
            }

            else if (prev != i)
            {
                cnt += allWays(n, l + 1, i, 1, rollMax);
            }

            cnt %= (int)1e9 + 7;
        }
        return cnt;
    }
    int dieSimulator(int n, vector<int> &rollMax)
    {
        return allWays(n, 0, -1, 0, rollMax);
    }
};

// **********************************************************************************************
// Memoization Code
// Beats 5%

class Solution
{
public:
    int allWays(int n, int l, int prev, int curLen, const vector<int> &rollMax, unordered_map<string, int> &memo)
    {
        if (n == l)
            return 1;

        string memoKey = to_string(l) + "_" + to_string(prev) + "_" + to_string(curLen);
        if (memo.find(memoKey) != memo.end())
            return memo[memoKey];

        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (prev == i && curLen == rollMax[i])
                continue;

            if (prev == i)
            {
                cnt += allWays(n, l + 1, prev, curLen + 1, rollMax, memo);
            }
            else if (prev != i)
            {
                cnt += allWays(n, l + 1, i, 1, rollMax, memo);
            }

            cnt %= static_cast<int>(1e9 + 7);
        }

        memo[memoKey] = cnt;
        return cnt;
    }

    int dieSimulator(int n, vector<int> &rollMax)
    {
        unordered_map<string, int> memo;
        return allWays(n, 0, -1, 0, rollMax, memo);
    }
};

// **********************************************************************************************
// Tabulation code :
class Solution
{
public:
    const int mod = 1e9 + 7;

    int dieSimulator(int n, vector<int> &rollMax)
    {

        int dp[n + 1][7];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int start = 1; start <= 6; start++)
            {
                int ans = 0;
                for (int taken = 1; taken <= rollMax[start - 1]; taken++)
                {
                    if (taken == i)
                    {
                        ans++;
                        break;
                    }

                    for (int next_start = 1; next_start <= 6; next_start++)
                    {
                        if (next_start != start)
                        {
                            ans += dp[i - taken][next_start];
                            ans %= mod;
                        }
                    }
                }

                dp[i][start] = ans;
            }
        }

        int f_ans = 0;
        for (int start = 1; start <= 6; start++)
        {
            f_ans += dp[n][start];
            f_ans %= mod;
        }
        return f_ans;
    }
};