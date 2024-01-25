#include <bits/stdc++.h>
using namespace std;

// * Generate all UNIQUE combinatinos of an array for a given SUM and PRINT them.

// ! Iterative + recursive approach to avoid unnecesary calls
// ! More efficient in Time and Memmory
// TODO : BEST Solution.

void Print_all_Combinations_for_a_give_Sum(vector<int> &candidates, int len, int idx, int target, vector<int> &v, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    // if (candidates[idx] > target)
    //     return;

    for (int i = idx; i < len; i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break; //! break; OR continue;

        v.push_back(candidates[i]);
        Print_all_Combinations_for_a_give_Sum(candidates, len, idx + 1, target - candidates[i], v, ans);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> v;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    //! This is the MOST important
    // ! 1. remove the selection of duplicate elements : [1,1,7,1] and target = 8  --> [1,7] , [1,7] and [7,1]  --> Only [1,7] is Answer.
    Print_all_Combinations_for_a_give_Sum(candidates, candidates.size(), 0, target, v, ans);
    return ans;
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