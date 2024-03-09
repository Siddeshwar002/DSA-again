#include <bits/stdc++.h>
using namespace std;

// Correct Code
// but gives TLE
// input size = 10^5
// you are using DFS - lol

class Solution
{
public:
    bool dfs(vector<int> start, vector<vector<int>> &pairs, set<vector<int>> &visited, int cnt, int nodes, vector<vector<int>> &res)
    {
        visited.insert({start});
        res.push_back(start);

        if (cnt == nodes)
            return true;

        for (int i = 0; i < pairs.size(); i++)
        {
            if (visited.count(pairs[i]) == 0 && pairs[i][0] == start[1])
                if (dfs(pairs[i], pairs, visited, cnt + 1, nodes, res))
                    return true;
        }
        visited.erase(start);
        res.pop_back();
        return false;
    }

    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        set<vector<int>> visited;
        int nodes = pairs.size();

        vector<vector<int>> res;

        for (int i = 0; i < pairs.size(); i++)
        {
            int cnt = 1;
            if (visited.count({pairs[i][0], pairs[i][1]}) == 0)
            {
                if (dfs(pairs[i], pairs, visited, cnt, nodes, res))
                {
                    return res;
                }
            }
        }
        return res;
    }
};

// $***************************************************************************************
