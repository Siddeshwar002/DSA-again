#include <bits/stdc++.h>
using namespace std;

// ! Recursive CODE

class Solution
{
public:
    double safeProb(int n, int k, int l, int row, int col)
    {
        if (k == l)
            return 1 / pow(8, l);

        int dx[] = {-1, +1, +2, +2, +1, -1, -2, -2};
        int dy[] = {-2, -2, -1, +1, +2, +2, +1, -1};

        double sum = 0;

        for (int i = 0; i < 8; i++)
        {
            int n_row = row + dx[i];
            int n_col = col + dy[i];

            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < n)
            {
                sum += safeProb(n, k, l + 1, n_row, n_col);
            }
        }
        return sum;
    }

    double knightProbability(int n, int k, int row, int col)
    {
        return safeProb(n, k, 0, row, col);
    }
};

// ! **********************************************************************************
// ! Memoizatoin CODE
// ! 3D DP table
// * Beats 77%

class Solution
{
public:
    double safeProbMemo(int n, int k, int l, int row, int col, vector<vector<vector<double>>> &memo)
    {
        if (k == l)
            return 1.0 / pow(8, l);

        if (memo[row][col][l] != -1)
            return memo[row][col][l];

        int dx[] = {-1, +1, +2, +2, +1, -1, -2, -2};
        int dy[] = {-2, -2, -1, +1, +2, +2, +1, -1};

        double sum = 0;

        for (int i = 0; i < 8; ++i)
        {
            int n_row = row + dx[i];
            int n_col = col + dy[i];

            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < n)
            {
                sum += safeProbMemo(n, k, l + 1, n_row, n_col, memo);
            }
        }

        memo[row][col][l] = sum;

        return sum;
    }

    double knightProbability(int n, int k, int row, int col)
    {
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));

        return safeProbMemo(n, k, 0, row, col, memo);
    }
};
