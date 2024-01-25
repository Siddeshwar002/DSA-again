#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    int row = matrix.size();
    int col = matrix[0].size();

    bool flag1 = false;
    bool flag2 = false;

    // first  = row
    for (int i = 0; i < col; i++)
    {
        if (matrix[0][i] == 0)
        {
            flag1 = true;
        }
    }

    // first col
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
        {
            flag2 = true;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // row
    for (int i = 1; i < row; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // col
    for (int i = 0; i < col; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 0; j < row; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    // make entire first row = 0;
    if (flag1)
    {
        for (int i = 0; i < col; i++)
        {
            matrix[0][i] = 0;
        }
    }

    // make entire first col = 0;
    if (flag2)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}