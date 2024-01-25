//* Given an undirected graph and a number m, determine if the graph can be colored
//* with at most m colors such that no two adjacent vertices of the graph
//* are colored with the same color.

// TODO: Approach 1 :

// ! using sets and checking if each node can be painted with certain paint
// ! If it can be painted from any of the paints from [1,2,....M] return true.
// ! If all the nodes can be painted then return true.
// ! Failing to paint a node from available colors will lead to return false.

#include <bits/stdc++.h>
using namespace std;

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<set<int>> v;
    map<int, set<int>> mp;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (graph[i][j])
            {
                set<int> s = {i, j};
                v.push_back(s);
                graph[j][i] = 0;
                // cout << i << " " << j << endl;
            }
        }
    }

    // cout << "---------" << endl;

    bool flag;
    for (auto s : v)
    {
        flag = false;
        for (int i = 1; i <= m; i++)
        {
            auto it = s.begin();
            int node_a = *it;
            ++it;
            int node_b = *it;
            // cout << node_a << " " << node_b << endl;
            // cout << "mp[node_a].find(i)" << *mp[node_a].find(i) << endl;
            // cout << "mp[node_a].find(i)" << *mp[node_a].find(i) << endl;

            if (mp[node_a].find(i) == mp[node_a].end() and mp[node_b].find(i) == mp[node_b].end())
            {
                flag = true;
                mp[node_a].insert(i);
                mp[node_b].insert(i);
                // cout << node_a << " " << node_b << " " << i << endl;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    bool graph[101][101] = {0};
    int n = 4;
    int m = 3;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][1] = 1;
    graph[1][3] = 1;

    if (graphColoring(graph, m, n))
        cout
            << "Yes" << endl;
    else
        cout << "No" << endl;
}