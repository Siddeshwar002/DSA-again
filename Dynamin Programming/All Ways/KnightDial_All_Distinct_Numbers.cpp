#include <bits/stdc++.h>
using namespace std;

// Recursive code

class Solution
{
public:
    int allNumbers(int n, int l, int num, vector<vector<int>> moves)
    {
        if (n == l)
            return 1;

        int cnt = 0;
        for (auto nextNum : moves[num])
        {
            cnt += allNumbers(n, l + 1, nextNum, moves);
            cnt %= (int)1e9 + 7;
        }
        return cnt;
    }

    int knightDialer(int n)
    {

        vector<vector<int>> moves = {
            {4, 6},
            {8, 6},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4},
        };

        int ans = 0;
        for (int i = 0; i <= 9; i++)
        {
            ans += allNumbers(n, 1, i, moves);
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};

// ************************************************************************************

// Memoization code
// 64/121 Passed

class Solution
{
public:
    int allNumbers(int n, int l, int num, vector<vector<int>> moves, vector<vector<int>> &memo)
    {
        if (n == l)
            return 1;

        if (memo[l][num] != -1)
        {
            return memo[l][num];
        }

        int cnt = 0;
        for (auto nextNum : moves[num])
        {
            cnt += allNumbers(n, l + 1, nextNum, moves, memo);
            cnt %= (int)1e9 + 7;
        }

        memo[l][num] = cnt;

        return cnt;
    }

    int knightDialer(int n)
    {
        vector<vector<int>> moves = {
            {4, 6},
            {8, 6},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4},
        };

        vector<vector<int>> memo(n + 1, vector<int>(10, -1));

        int ans = 0;
        for (int i = 0; i <= 9; i++)
        {
            ans += allNumbers(n, 1, i, moves, memo);
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};

// **********************************************************************************
// Tabulation

class Solution
{
public:
    int knightDialer(int n)
    {

        vector<vector<int>> moves = {
            {4, 6},
            {8, 6},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4},
        };

        if (n == 1)
            return 10;

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));

        for (int num = 0; num <= 9; num++)
            dp[1][num] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                for (auto nextNum : moves[j])
                {
                    dp[i][nextNum] += dp[i - 1][j];
                    dp[i][nextNum] %= (int)1e9 + 7;
                }
            }
        }

        int ans = 0;
        for (int num = 0; num <= 9; num++)
        {
            ans += dp[n][num];
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};