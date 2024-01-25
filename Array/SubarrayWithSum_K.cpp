#include <bits/stdc++.h>
using namespace std;

// ! Smart Code

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;

    mp[sum] = 1;

    for (auto it : nums)
    {
        sum += it;
        int find = sum - k;
        if (mp.find(find) != mp.end())
        {
            ans += mp[find];
        }

        // ! map accessing
        mp[sum]++;
    }

    return ans;
}

// ! **********************************************************

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int preSum = 0;
    int cnt = 0;

    // if(k != 0)
    mp[0] = 1;

    for (auto it : nums)
    {
        preSum += it;

        if (k == 0 and mp.find(preSum) != mp.end())
        {
            cnt++;
            // mp[preSum] += 1;
        }

        if (mp.find(preSum) == mp.end())
        {
            mp[preSum] = 1;
        }
        else
            mp[preSum] += 1;

        if (k != 0 && mp.find(mp[preSum - k]) != mp.end())
        {
            cnt += mp[preSum - k];
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums = {-1, -1, 1};
    int k = 1;
    cout << "Number of Subarrays with Sum K: " << subarraySum(nums, k) << endl;
}