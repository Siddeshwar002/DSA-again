#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(string start, string end, unordered_set<string> &vis, vector<vector<string>> &equations, vector<double> &values, double &ans)
    {
        if (start == end)
            return true;

        if (vis.find(start) != vis.end())
            return false;
        vis.insert(start);

        for (int i = 0; i < equations.size(); i++)
        {
            if (start == equations[i][0] && vis.find(equations[i][1]) == vis.end())
            {
                if (dfs(equations[i][1], end, vis, equations, values, ans *= values[i]))
                    return true;
                ans /= values[i];
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        vector<double> res;
        int Esize = equations.size();
        unordered_set<string> nodes;

        for (int i = 0; i < Esize; i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = (1 / values[i]);

            nodes.insert(u);
            nodes.insert(v);

            equations.push_back({v, u});
            values.push_back(w);
        }

        for (int i = 0; i < equations.size(); i++)
        {
            cout << equations[i][0] << " " << equations[i][1] << " " << values[i] << endl;
        }

        for (auto query : queries)
        {
            string start = query[0];
            string end = query[1];

            unordered_set<string> vis;
            double ans = 1;

            if (dfs(start, end, vis, equations, values, ans) && (nodes.find(start) != nodes.end() && nodes.find(end) != nodes.end()))
                res.push_back(ans);
            else
                res.push_back((double)-1);
        }
        return res;
    }
};