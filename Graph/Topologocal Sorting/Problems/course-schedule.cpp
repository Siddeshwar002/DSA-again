#include <bits/stdc++.h>
using namespace std;

// 1.
// using BFS method
// Accepted

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<int> outDeg(numCourses, 0);

        for (auto edge : prerequisites)
        {
            outDeg[edge[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (outDeg[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto edge : adj[node])
            {
                outDeg[edge]--;
                if (outDeg[edge] == 0)
                    q.push(edge);
            }
        }
        if (cnt == numCourses)
            return true;

        return false;
    }
};

// 2.
// BFS method
// same approach as above but
// Production level code
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto &prereq : prerequisites)
        {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adjList[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        while (!q.empty())
        {
            int currentCourse = q.front();
            q.pop();
            coursesTaken++;

            for (int dependentCourse : adjList[currentCourse])
            {
                if (--inDegree[dependentCourse] == 0)
                {
                    q.push(dependentCourse);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};

// 3.
// Using DFS
// If Visited Node form the call stack found then return false;
// 48/52 passed

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, unordered_set<int> &vis, int start)
    {
        if (vis.count(start) > 0)
            return false;
        vis.insert(start);

        for (auto next : adj[start])
        {
            if (!dfs(adj, vis, next))
                return false;
        }

        vis.erase(start);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto course : prerequisites)
            adj[course[0]].push_back(course[1]);

        unordered_set<int> vis;
        for (int i = 0; i < numCourses; i++)
        {
            if (vis.count(i) == 0)
                if (!dfs(adj, vis, i))
                    return false;
        }
        return true;
    }
};