#include <bits/stdc++.h>
using namespace std;

// * PRINT ALL the Unique Subsets
// * Given an array of integers that may contain duplicates
// * the task is to return all possible subsets. Return only unique subsets
// * and they can be in any order.

// ! WRONG CODE
// ! mp[sum] has to be changed to mp[v]
// ! where v holds the unique vector

void All_Unique_Subsets(int arr[], int n, int i, vector<int> v, int sum, map<int, int> &mp)
{
    if (i == n and mp[sum] != 1)
    {
        mp[sum] = 1;

        for (auto x : v)
            cout << x << " ";

        cout << endl;
        return;
    }
    else if (i == n and mp[sum] == 1)
        return;

    All_Unique_Subsets(arr, n, i + 1, v, sum, mp);
    v.push_back(arr[i]);
    All_Unique_Subsets(arr, n, i + 1, v, sum + arr[i], mp);
}

int main()
{
    int arr[] = {1, 2, 2, 3};
    vector<int> v;
    map<int, int> mp;
    All_Unique_Subsets(arr, sizeof(arr) / sizeof(arr[0]), 0, v, 0, mp);
}

// ********************************************************************
// * IP
// int arr[] = {1, 2, 2, 3};

// * OP
// 3
// 2
// 2 3
// 2 2
// 2 2 3
// 1
// 1 2 3
// 1 2 2 3

// [1, 2] is missing
// This is because we already considered the SUM = 3 when we encounterd the 3 element.