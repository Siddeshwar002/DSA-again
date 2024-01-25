#include <bits/stdc++.h>
using namespace std;

// ! All pair Shortest path Alogorithm
// ! n<=100

// !Dosent work for n <= 10^5
// ! Need a Advanced CODE

vector<int> countOfPairs(int n, int x, int y)
{

    unordered_map<int, vector<int>> adjacencyList;

    for (int i = 1; i < n; ++i)
    {
        adjacencyList[i].push_back(i + 1);
        adjacencyList[i + 1].push_back(i);
    }

    adjacencyList[x].push_back(y);
    adjacencyList[y].push_back(x);

    vector<int> pairsCount(n, 0);

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

                    if (distances[neighbor] > 0 && distances[neighbor] <= n)
                    {
                        pairsCount[distances[neighbor] - 1]++;
                    }
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

    return pairsCount;
}

int main()
{
    countOfPairs(5, 2, 4);
}