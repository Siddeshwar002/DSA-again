#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

/**QUESTION :
 * https://www.geeksforgeeks.org/problems/merging-details/0
 * HARD
 *
 *
 * Approach :
 *
 * Disjoint set Union Implementation
 * Connected components concept
 */

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int par_u = findUPar(u);
        int par_v = findUPar(v);

        if (par_u == par_v)
            return;

        if (size[par_u] >= size[par_v])
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> mergeDetails(vector<vector<string>> &details)
    {
        int n = details.size();

        DisjointSet d(n);
        map<string, int> mp;

        for (int i = 0; i < details.size(); i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                if (mp.find(details[i][j]) == mp.end())
                {
                    mp[details[i][j]] = i;
                }
                else
                {
                    int par1 = d.findUPar(mp[details[i][j]]);
                    int par2 = d.findUPar(i);

                    d.UnionBySize(par1, par2);
                }
            }
        }

        vector<vector<string>> vec(n);
        for (auto eachEntry : mp)
        {
            int U_par = d.findUPar(eachEntry.second);
            vec[U_par].push_back(eachEntry.first);
        }

        vector<vector<string>> result;

        for (int i = 0; i < vec.size(); i++)
        {
            if (!vec[i].empty())
            {
                vec[i].insert(vec[i].begin(), details[i][0]);
                result.push_back(vec[i]);
            }
        }

        return result;
    }
};
