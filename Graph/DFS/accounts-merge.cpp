#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(string start, map<string, vector<string>> &adj, set<string> &ans, unordered_set<string> &visited)
    {
        visited.insert(start);
        ans.insert(start);

        for (auto nextNode : adj[start])
        {
            if (visited.count(nextNode) == 0)
                dfs(nextNode, adj, ans, visited);
        }
        return;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &acc)
    {
        map<string, vector<string>> adj;
        map<string, string> mp;

        int r = acc.size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 1; j < acc[i].size(); j++)
            {

                if (j == 1)
                {
                    mp[acc[i][1]] = acc[i][0];
                }
                else
                {
                    adj[acc[i][j - 1]].push_back(acc[i][j]);
                    adj[acc[i][j]].push_back(acc[i][j - 1]);
                }
            }
        }

        for (auto node : adj)
        {
            cout << node.first << " -> ";
            for (auto next : node.second)
                cout << next << " ";
            cout << endl;
        }

        for (auto node : mp)
            cout << node.first << "-" << node.second << endl;

        unordered_set<string> visited;
        vector<vector<string>> res;

        for (auto node : mp)
        {
            if (visited.count(node.first) == 0)
            {
                set<string> ans;
                dfs(node.first, adj, ans, visited);
                string name = node.second;
                vector<string> vec;
                vec.push_back(name);

                for (auto s : ans)
                    vec.push_back(s);

                res.push_back(vec);
            }
        }

        return res;
    }
};