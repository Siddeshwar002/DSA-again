#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> answer = matrix;

        for (int j = 0; j < n; ++j)
        {
            int maxVal = INT_MIN;

            // Iterate over each column to find the maximum value in that column
            for (int i = 0; i < m; ++i)
            {
                maxVal = max(maxVal, matrix[i][j]);
            }

            // Replace -1 with the maximum value of the column
            for (int i = 0; i < m; ++i)
            {
                if (answer[i][j] == -1)
                {
                    answer[i][j] = maxVal;
                }
            }
        }
        return answer;
    }
};
