#include <bits/stdc++.h>
using namespace std;

// ! Generate all UNIQUE combinatinos of an array for a given SUM and PRINT them.

// ! All combinations including the duplicate elements
// ! [1,7,1]
// ! target = 8;
// ! Ans = [1,7] and [7,1]
// ! not changing the position with the same number but different one.
// ! This code is considering the repetations

// ! This works for :
// * distinct integers and a target

void Print_ALL_Combinations_of_Target(int arr[], int n, int i, vector<int> v, int sum, map<vector<int>, int> &mp, int target, vector<vector<int>> &vec)
{
    if (sum == target and mp[v] != 1)
    {
        vec.push_back(v);
        mp[v] = 1;
        // for (auto x : v)
        //     cout << x << " ";

        // cout << endl;
    }

    if (i == n)
        return;

    Print_ALL_Combinations_of_Target(arr, n, i + 1, v, sum, mp, target, vec);
    v.push_back(arr[i]);
    Print_ALL_Combinations_of_Target(arr, n, i + 1, v, sum + arr[i], mp, target, vec);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    int n = candidates.size();
    int arr[n];

    int i = 0;
    for (auto x : candidates)
    {
        arr[i++] = x;
    }

    vector<int> v;
    map<vector<int>, int> mp;
    // int target = 25;
    vector<vector<int>> vec;
    Print_ALL_Combinations_of_Target(arr, sizeof(arr) / sizeof(arr[0]), 0, v, 0, mp, target, vec);
    return vec;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);

    for (auto v : ans)
    {
        cout << "[";
        for (auto ele : v)
        {
            cout << ele << " ";
        }
        cout << "]" << endl;
    }
}