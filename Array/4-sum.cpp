// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();

    // To avoid the duplicates
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;

            int l = j + 1;
            int r = n - 1;

            while (l < r)
            {
                // Integer overflow addition
                // long long sum = nums[i] + nums[j] + nums[l] + nums[r];

                // Correct addition operation
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[l];
                sum += nums[r];

                if (sum == target)
                {
                    vector<int> v = {nums[i], nums[j], nums[l], nums[r]};
                    ans.push_back(v);
                    l++;
                    r--;

                    // Avoid Duplicates
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,2};
    cout<<"Hi"<<endl;
    fourSum(v , 2);
}