// TODO: Approach 2 :

// ! Calculate the degree of each node
// ! Check the max of all the degrees

// ! if(m < max_degrees) return false
// ! else return true

// ! this code works when we are coloring edges and not nodes

#include <bits/stdc++.h>
using namespace std;

bool graphColoring(bool graph[101][101], int m, int n)
{
    map<int, int> mp;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (graph[i][j])
            {
                mp[i]++;
                mp[j]++;
                graph[j][i] = 0;
                // cout << i << " " << j << endl;
            }
        }
    }

    for (auto ele : mp)
    {
        // cout<<ele.first<< " -> "<<ele.second<<endl;
        if (ele.second > m)
            return false;
    }

    return true;
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

    if (graphColoring(graph, n, m))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}