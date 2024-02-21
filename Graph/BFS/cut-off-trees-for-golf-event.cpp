#include <bits/stdc++.h>
using namespace std;

// Approach is correct
// but
// Throws runtime error on leetcode

class Solution
{
public:
    void dfs(map<int, vector<int>> &adj, vector<bool> &vis, int start, int nodeCnt, int ans, int &res)
    {
        vis[start] = true;

        if (nodeCnt == adj.size())
        {
            res = min(res, ans);
            return;
        }

        for (auto nextNode : adj[start])
        {
            if (!vis[nextNode] && nextNode > start)
            {
                dfs(adj, vis, nextNode, nodeCnt + 1, ans + 1, res);
            }
        }
        return;
    }

    int cutOffTree(vector<vector<int>> &forest)
    {
        map<int, vector<int>> adj;
        int row = forest.size();
        int col = forest[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};

                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (forest[i][j] > 0 && x >= 0 && y >= 0 && x < row && y < col && forest[x][y] > 0)
                    {
                        adj[forest[i][j]].push_back(forest[x][y]);
                    }
                }
            }
        }

        for (auto ele : adj)
        {
            cout << ele.first << "->";
            for (auto v : ele.second)
                cout << v << " ";
            cout << endl;
        }

        cout << "size" << adj.size() << endl;

        for (auto ele : adj)
            sort(ele.second.begin(), ele.second.end());

        int nodes = adj.size();
        vector<bool> vis(nodes, false);

        int ans = 0;
        int res = INT_MAX;
        int nodeCnt = 1;

        auto it = adj.begin();
        int startNode = -1;
        if (it != adj.end())
            startNode = it->first;
        else
            return -1;

        dfs(adj, vis, startNode, nodeCnt, ans, res);

        if (res == INT_MAX)
            return -1;
        else
            return res;
    }
};

int main()
{
    // vector<vector<int>> forest = {
    //     {0, 0, 0, 3528, 2256, 9394, 3153},
    //     {8740, 1758, 6319, 3400, 4502, 7475, 6812},
    //     {0, 0, 3079, 6312, 0, 0, 0},
    //     {6828, 0, 0, 0, 0, 0, 8145},
    //     {6964, 4631, 0, 0, 0, 4811, 0},
    //     {0, 0, 0, 0, 9734, 4696, 4246},
    //     {3413, 8887, 0, 4766, 0, 0, 0},
    //     {7739, 0, 0, 2920, 0, 5321, 2250},
    //     {3032, 0, 3015, 0, 3269, 8582, 0}};

    vector<vector<int>> forest = { {2395, 206, 0, 5388},
                                   {4985, 2866, 0, 1789},
                                   {0, 0, 7052, 0},
                                   {0, 3029, 3327, 685},
                                   {0, 0, 7846, 0},
                                   {0, 0, 1542, 0},
                                   {7577, 0, 2902, 623},
                                   {2610, 9817, 0, 8198} };

    Solution s;
    cout << s.cutOffTree(forest);
}