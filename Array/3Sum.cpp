#include <bits/stdc++.h>
using namespace std;

// ********* Better code *********
vector<vector<int>> threeSum_2(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    // * Sorting the input array
    // * To avoid the duplicate answers
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i)
    {
        // * Avoid duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // * Avoid duplicates for the second element
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }

                // * Avoid duplicates for the third element
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }

                left++;

                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}

// ! Scroll UP for better code
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> sv;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;

        int ele = (-1) * nums[i];

        while (l < r)
        {
            if (i == l)
                l++;
            if (i == r)
                r--;
            if (l == r)
                break;

            if (nums[l] + nums[r] == ele)
            {
                vector<int> v = {nums[i], nums[l], nums[r]};
                sort(v.begin(), v.end());
                sv.insert(v);
                l++;
                r--;
            }
            else if (nums[l] + nums[r] < ele)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    vector<vector<int>> ans;
    for (auto it : sv)
    {
        ans.push_back(it);
    }
    return ans;
}
