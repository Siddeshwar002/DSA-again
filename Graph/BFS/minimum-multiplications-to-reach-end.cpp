// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/** QUESTION :
 * Given start, end and an array arr of n numbers.
 * At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
 * Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
 * */

/** Approach :
 *
 * Dijikstras Algorithm
 * BFS - queue
 * Distance array stores steps
 */

/** TLE :
 *
 * Not including distance[] and solving give TLE
 *
 * Example 1 :  You were able to reach a node at steps = k
 *              Next time you again reach a node but with steps k' ; where k' > k
 *              You should NOT push this into the queue
 *              If You dont perform this check, then this will lead to TLE
 */

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        const int mod = 100000;
        vector<int> dis(mod, INT_MAX);

        // Edge case: start == end
        if (start == end)
            return 0;

        queue<pair<int, int>> q;
        q.push({start, 0});
        dis[start] = 0;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int num = cur.first;
            int steps = cur.second;

            for (int factor : arr)
            {
                int adjNode = (1LL * num * factor) % mod;

                /* this condition saves the code from TLE */
                if (steps + 1 < dis[adjNode])
                {
                    if (adjNode == end)
                        return steps + 1;

                    dis[adjNode] = steps + 1;
                    q.push({adjNode, steps + 1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;

        cout << "~" << "\n";
    }
}

// } Driver Code Ends`