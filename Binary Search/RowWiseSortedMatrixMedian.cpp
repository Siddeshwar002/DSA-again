// * Given an array of N integers.Every number in the array except one appears twice.
// * Find the single number in the array.

#include <bits/stdc++.h>
using namespace std;

int CoutNos(vector<int> arr, int ele)
{
    int low = 0;
    int high = arr.size()-1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (arr[mid] <= ele)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int midpos = (R * C) / 2;

    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < R; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int count = 0;
        for (int i = 0; i < R; i++)
        {
            count += CoutNos(matrix[i], mid);
        }

        if (count <= midpos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int row = 3, col = 3;
    vector<vector<int>> arr = {{1, 3, 5},
                               {2, 6, 9},
                               {3, 6, 9}};

    cout << median(arr, row, col);
}