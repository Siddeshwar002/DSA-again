#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{

    int idx = -1;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }

    cout << "idx" << idx;

    if (idx == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > idx; i--)
    {
        if (nums[idx] < nums[i])
        {
            swap(nums[idx], nums[i]);
            break;
        }
    }

    reverse(nums.begin() + idx + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
}