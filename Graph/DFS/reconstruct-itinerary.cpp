#include <bits/stdc++.h>
using namespace std;

// Correct Approach
// Accepted

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;

        for (const auto &ticket : tickets)
        {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK", graph, itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

    void dfs(const string &airport, unordered_map<string, multiset<string>> &graph, vector<string> &itinerary)
    {
        while (!graph[airport].empty())
        {
            string nextAirport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(nextAirport, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};

// $****************************************************************************************************
// My code :
// wrong code

class Solution
{
public:
    bool dfs(string start, map<string, vector<string>> &mp, vector<string> &res, int k, int count)
    {

        res.push_back(start);

        if (mp[start].empty() && count != k)
        {
            res.pop_back();
            return false;
        }

        for (int i = 0; i < mp[start].size(); ++i)
        {
            string nextNode = mp[start][i];
            mp[start].erase(mp[start].begin() + i);

            // Erase the node before calling DFS
            if (!dfs(nextNode, mp, res, k, count + 1))
            {
                // Insert the node back into the same position if DFS returns false
                mp[start].insert(mp[start].begin() + i, start);

                // return false;
            }
        }
        return true;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, vector<string>> mp;

        for (auto ticket : tickets)
            mp[ticket[0]].push_back(ticket[1]);

        for (auto &node : mp)
            sort(node.second.begin(), node.second.end());

        for (auto node : mp)
        {
            cout << node.first << " -> ";
            for (auto neig : node.second)
                cout << neig << " ";

            cout << endl;
        }

        vector<string> res;
        int count = 0;
        int k = tickets.size();
        dfs("JFK", mp, res, k, count);
        return res;
    }
};

// $************************************************************************************************

// Production level code :
// Correct
// TLE - 80/81 passed
class Solution
{
public:
    bool dfs(string start, map<string, vector<string>> &mp, vector<string> &res, int k, int count)
    {
        res.push_back(start);

        if (count == k)
            return true;

        for (int i = 0; i < mp[start].size(); ++i)
        {
            string nextNode = mp[start][i];

            mp[start].erase(mp[start].begin() + i);

            // If a valid itinerary is found, return true
            // you won't furthur go with other nodes from the same call
            // you can go from the same node in some other call but not in the same call
            if (dfs(nextNode, mp, res, k, count + 1))
            {
                return true;
            }

            // If the current destination didn't lead to a valid path, backtrack
            // by restoring the destination back to the current start node
            mp[start].insert(mp[start].begin() + i, nextNode);
        }

        // If none of the destinations from the current start node lead to a valid path, backtrack
        // Remove the last added node from the result vector
        res.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, vector<string>> mp;

        for (auto ticket : tickets)
            mp[ticket[0]].push_back(ticket[1]);

        for (auto &node : mp)
            sort(node.second.begin(), node.second.end());

        vector<string> res;
        int count = 0;
        int k = tickets.size();
        dfs("JFK", mp, res, k, count);
        return res;
    }
};
