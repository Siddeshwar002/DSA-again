#include <bits/stdc++.h>
using namespace std;

// 1.
// Accepted

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum1 = 0, sum2 = 0;
        vector<int> x, nx;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = (nums[i] ^ k) - nums[i];

            if (diff >= 0)
            {
                sum1 += nums[i] ^ k;
                x.push_back(diff);
            }
            else
            {
                sum2 += nums[i];
                nx.push_back(abs(diff));
            }
        }

        if (x.size() % 2 == 0)
            return sum1 + sum2;

        sort(x.begin(), x.end());
        sort(nx.begin(), nx.end());

        if (nx.size() == 0)
            return sum1 + sum2 - x[0];

        return max(sum1 + sum2 - x[0], sum1 + sum2 - nx[0]);
    }
};

// 2.
// Approach : Considering the even number nodes
// and considering the XOR value of that even no of nodes

// Wrong code

class Solution
{
public:
    void solve(int i, vector<int> &nums, int k, long long sum, int cnt, long long &ans, vector<vector<int>> &dp)
    {

        if (i >= nums.size())
        {
            if (cnt % 2 == 0)
                ans = max(ans, sum);
            return;
        };

        solve(i + 1, nums, k, sum + nums[i], cnt, ans, dp);
        solve(i + 1, nums, k, sum + (nums[i] ^ k), cnt++, ans, dp);

        return;
    }

    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        long long ans = 0;
        solve(0, nums, k, 0, 0, ans, dp);
        return ans;
    }
};