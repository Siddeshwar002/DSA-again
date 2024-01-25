#include <bits/stdc++.h>
using namespace std;

// ! Recursive Approach - TLE
class Solution
{
public:
    int Stones(vector<int> &stones, int weight, map<int, bool> &mp, int cnt)
    {
        if (cnt == stones.size())
        {
            return weight;
        }

        int ans = INT_MAX;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!mp[i])
            {
                mp[i] = true;
                ans = min(ans, Stones(stones, abs(stones[i] - weight), mp, cnt + 1));
                mp[i] = false;
            }
        }
        return ans;
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        int weight = 0;
        map<int, bool> mp;
        int cnt = 0;
        return Stones(stones, weight, mp, cnt);
    }
};

// ! *************************************************************************************
// ! Memoization CODE
// ! 81 / 90 testcases passed

// ! Failed Test case
// [1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98]
// 3
// 1

class Solution2
{
public:
    int Stones(vector<int> &stones, int weight, map<int, bool> &mp, int cnt, vector<vector<int>> &dp)
    {
        if (cnt == stones.size())
        {
            return weight;
        }

        if (dp[cnt][weight] != -1)
            return dp[cnt][weight];

        int ans = INT_MAX;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!mp[i])
            {
                mp[i] = true;
                ans = min(ans, Stones(stones, abs(stones[i] - weight), mp, cnt + 1, dp));
                mp[i] = false;
            }
        }
        return dp[cnt][weight] = ans;
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        int m = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size(), vector<int>(m / 2 + 1, -1));
        int weight = 0;
        map<int, bool> mp;
        int cnt = 0;
        return Stones(stones, weight, mp, cnt, dp);
    }
};

// ! *************************************************************************
// * CORRECCT CODE
// * MEMOIZATION

// * Subset --> Split into --> Sub1 and Sub2 --> calculate Difference(Sub1, Sub2) --> make Difference Minimum

class Solution
{
public:
    int stoneSplit(vector<int> &stones, int idx, int Sum1, int Sum2, vector<vector<int>> &dp)
    {
        if (idx == stones.size())
            return abs(Sum1 - Sum2);

        if (dp[idx][Sum1] != -1)
            return dp[idx][Sum1];

        int SubuSet1 = stoneSplit(stones, idx + 1, Sum1 + stones[idx], Sum2, dp);
        int SubuSet2 = stoneSplit(stones, idx + 1, Sum1, Sum2 + stones[idx], dp);

        return dp[idx][Sum1] = min(SubuSet1, SubuSet2);
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        int m = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(m + 1, -1));
        return stoneSplit(stones, 0, 0, 0, dp);
    }
};