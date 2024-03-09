#include <bits/stdc++.h>
#include <algorithm> // for gcd(n,m)
using namespace std;

// 1.
// Super concepts
// Connecting the nums[i] with their factor -> amazing
// connecting the nums if they have common factor
// which makes them connected
class Solution
{
    vector<int> rank, parent;

public:
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUpar(u), ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return;
    }

    int largestComponentSize(vector<int> &nums)
    {
        int size = *max_element(nums.begin(), nums.end());
        rank.resize(size + 1, 1);
        parent.resize(size + 1);
        int n = nums.size();

        for (int i = 0; i < size + 1; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 2; j <= sqrt(nums[i]); ++j)
            {
                if (nums[i] % j == 0)
                {
                    unionByRank(nums[i], j);
                    unionByRank(nums[i] / j, j);
                }
            }
        }

        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            // we just need to count the nums
            // but we also have the factors of nums
            // which we cant count
            int node = findUpar(nums[i]);
            mp[node]++;
        }

        int res = 0;
        for (auto &m : mp)
            res = max(res, m.second);

        return res;
    }
};

// 2.
// Correct approach
// but gives TLE

class Solution
{
    vector<int> rank, parent;

public:
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUpar(u), ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return;
    }

    bool hasAnEdge(int n, int m)
    {
        // inbuilt
        // return gcd(n, m) > 1;
    }

    int largestComponentSize(vector<int> &nums)
    {
        int size = *max_element(nums.begin(), nums.end());
        rank.resize(size + 1, 1);
        parent.resize(size + 1);
        int n = nums.size();

        for (int i = 0; i < size + 1; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int u = nums[i];
                int v = nums[j];

                if (hasAnEdge(u, v))
                {
                    unionByRank(u, v);
                }
            }
        }

        map<int, int> mp;
        for (int i = 0; i < size + 1; i++)
        {
            int node = findUpar(parent[i]);
            mp[node]++;
        }

        int res = 0;
        for (auto &m : mp)
            res = max(res, m.second);

        return res;
    }
};