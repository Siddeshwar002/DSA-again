#include <bits/stdc++.h>
using namespace std;

// Runtime error
class Solution
{
public:
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

        int startNode = forest[0][0];
        priority_queue<int, vector<int>, greater<>> q;
        q.push(startNode);
        int cnt = 0;

        while (!q.empty())
        {

            int curNode = q.top();
            q.pop();
            vis[curNode] = true;
            cnt++;

            cout << cnt << endl;

            if (cnt == adj.size())
                return cnt;

            for (auto nextNode : adj[curNode])
            {
                if (nextNode < curNode && !vis[nextNode])
                    return -1;
                if (!vis[nextNode])
                    q.push(nextNode);
            }
        }
        return adj.size() - 1;
    }
};

int main()
{
    vector<vector<int>> forest = {{1, 2, 3},
                                  {0, 0, 4},
                                  {7, 6, 5}};

    Solution obj;
    obj.cutOffTree(forest);
}