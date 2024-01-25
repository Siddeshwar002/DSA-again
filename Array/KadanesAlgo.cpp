#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxidx = nums[0];
    int maxGlobal = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        maxidx = max(nums[i], maxidx + nums[i]);
        maxGlobal = max(maxidx, maxGlobal);
    }

    return maxGlobal;
}