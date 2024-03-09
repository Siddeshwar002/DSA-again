#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto preq : prerequisites)
        {
            int u = preq[0];
            int v = preq[1];
            adj[v].push_back(u);
            inDeg[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDeg[i] == 0)
                q.push(i);

        int count = 0;
        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);
            count++;

            for (auto dependantNode : adj[node])
            {
                if (--inDeg[dependantNode] == 0)
                    q.push(dependantNode);
            }
        }

        if (count == numCourses)
            return ans;

        return {};
    }
};