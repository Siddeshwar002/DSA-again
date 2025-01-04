#include "stdc++.h"
using namespace std;

// ! TC - O(2^N)
// ! REcursive calls

// ! No map[v] needed to store the unique subsets

// ! sorting
// ! Preventing the calculation to duplicate subsets

// ! Storing all the subsets generated

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        // ! avoiding Duplicates
        if (i != ind && nums[i] == nums[i - 1])
            continue;

        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    // ! very important to avoid DUPLICATES
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
}