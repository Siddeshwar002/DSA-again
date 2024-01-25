#include <bits/stdc++.h>
using namespace std;

// ! Hard
// ! 66/67 passed -> TLE

class TrieNode
{
public:
    unordered_map<int, TrieNode *> binChildren;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (cur->binChildren.find(bit) == cur->binChildren.end())
            {
                cur->binChildren[bit] = new TrieNode();
            }
            cur = cur->binChildren[bit];
        }
    }

    int MaxXOR(int num)
    {
        TrieNode *cur = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (cur->binChildren.find(!bit) != cur->binChildren.end())
            {
                maxXor |= (1 << i);
                cur = cur->binChildren[!bit];
            }
            else
            {
                cur = cur->binChildren[bit];
            }
        }
        return maxXor;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<pair<int, pair<int, int>>> vp;
        for (int i = 0; i < queries.size(); i++)
        {
            vp.push_back({queries[i][1], {queries[i][0], i}});
        }

        // Sort both the ds
        sort(nums.begin(), nums.end());
        sort(vp.begin(), vp.end());

        vector<int> ans(queries.size(), -1);
        int idx = 0;
        Trie trie;

        for (auto [m, query] : vp)
        {
            int x = query.first;
            int i = query.second;

            while (idx < nums.size() && nums[idx] <= m)
            {
                trie.insert(nums[idx++]);
            }

            if (idx != 0)
            {
                ans[i] = trie.MaxXOR(x);
            }
        }
        return ans;
    }
};
