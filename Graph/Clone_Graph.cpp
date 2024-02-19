#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *Cloning(Node *node, map<int, Node *> &mp)
    {
        if (mp[node->val])
            return mp[node->val];
        else
        {
            Node *curr = new Node(node->val);
            mp[curr->val] = curr;
            for (auto neigs : node->neighbors)
            {
                curr->neighbors.push_back(Cloning(neigs, mp));
            }
            return curr;
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        map<int, Node *> mp;
        return Cloning(node, mp);
    }
};
