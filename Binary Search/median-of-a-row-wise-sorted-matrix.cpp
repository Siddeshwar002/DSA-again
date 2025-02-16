#include <bits/stdc++.h>
using namespace std;

// This funciton returns total number of elements which are less than element 'mid'
// 'md' is the middle index not 'mid'
// this is basically the upper bound function 
// This gives us the index of element which is greater than the element.
// So all the elements to the left are smaller than that element
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A)
{
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();

    // low and high are not indexes
    // answers lies within those range
    // [low] ............[ans].................[range]

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // calling this for each row
            // getting the count that element mid is greater than how many elements.
            cnt += countSmallerThanMid(A[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int row = 3, col = 3;
    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
    cout << "The median of the row-wise sorted matrix is: " << findMedian(arr) << endl;
    return 0;
}