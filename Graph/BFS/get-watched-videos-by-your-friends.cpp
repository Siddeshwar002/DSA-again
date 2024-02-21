#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        queue<pair<int, int>> q;
        int n = friends.size();
        vector<bool> vis(n, false);
        unordered_map<string, int> mp;

        q.push({id, 0});
        vis[id] = true;

        while (!q.empty())
        {

            int Qsize = q.size();

            for (int i = 0; i < Qsize; i++)
            {

                int node = q.front().first;
                int curlevel = q.front().second;
                q.pop();

                if (curlevel == level)
                {
                    for (auto video : watchedVideos[node])
                    {
                        mp[video]++;
                    }
                    continue;
                }

                for (auto nextNode : friends[node])
                    if (!vis[nextNode])
                    {
                        vis[nextNode] = true;
                        q.push({nextNode, curlevel + 1});
                    }
            }
        }

        for (auto m : mp)
            cout << m.first << " " << m.second << endl;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        for (auto m : mp)
        {
            pq.push({m.second, m.first});
        }

        vector<string> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

