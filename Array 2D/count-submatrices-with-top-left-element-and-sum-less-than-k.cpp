#include <bits/stdc++.h>
using namespace std;

// Accepted
// 1.
// Prefix Sum

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j > 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0 && i > 0)
                    grid[i][j] += grid[i - 1][j];
                else if (i > 0 && j > 0)
                    grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];

                if (grid[i][j] <= k)
                    ans++;
            }
        }
        return ans;
    }
};

// 2.
// TLE - 858 / 859 testcases passed
class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> mat = grid;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                mat[i][j] += mat[i - 1][j];
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            int low = 0;
            int high = m - 1;

            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (mat[i][mid] > k)
                    high = mid - 1;
                else if (mat[i][mid] <= k)
                    low = mid + 1;
            }
            ans += (high + 1);
        }

        return ans;
    }
};