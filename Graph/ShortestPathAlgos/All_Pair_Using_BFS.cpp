#include <bits/stdc++.h>
using namespace std;

// ! All pair Shortest path Alogorithm
// ! n<=100

// !Dosent work for n <= 10^5
// ! Need a Advanced CODE

// ! problem specific CODE

vector<vector<int>> countOfPairs(int n, int x, int y)
{

    unordered_map<int, vector<int>> adjacencyList;

    for (int i = 1; i < n; ++i)
    {
        adjacencyList[i].push_back(i + 1);
        adjacencyList[i + 1].push_back(i);
    }

    adjacencyList[x].push_back(y);
    adjacencyList[y].push_back(x);

    // * Given a adjacency list start executing from this line

    vector<vector<int>> allDistance(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        vector<int> distances(n + 1, -1);
        distances[i] = 0;

        queue<int> bfsQueue;
        bfsQueue.push(i);

        while (!bfsQueue.empty())
        {
            int current = bfsQueue.front();
            bfsQueue.pop();

            // cout << "Curent Node : " << current << endl;
            // cout << "Before" << endl;
            // for (auto it : distances)
            //     cout << it << " ";
            // cout << endl;
            // for (auto it : pairsCount)
            //     cout << it << " ";
            // cout << endl;

            for (int neighbor : adjacencyList[current])
            {
                if (distances[neighbor] == -1)
                {
                    distances[neighbor] = distances[current] + 1;
                    bfsQueue.push(neighbor);
                    allDistance[i][neighbor] = distances[neighbor];

                    // * Anyways its gonna be computed when neighbor becomes the starting index
                    // allDistance[neighbor][i] = distances[neighbor];
                }
            }

            // cout << "After" << endl;
            // for (auto it : distances)
            //     cout << it << " ";
            // cout << endl;
            // for (auto it : pairsCount)
            //     cout << it << " ";
            // cout << endl;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << allDistance[i][j] << " ";
        }
        cout << endl;
    }
    return allDistance;
}

int main()
{
    countOfPairs(5, 2, 4);
}