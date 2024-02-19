#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        if (!root)
            return ans;
        q.push(root);

        while (!q.empty())
        {
            vector<int> vec;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *cur = q.front();
                q.pop();

                vec.push_back(cur->val);

                for (auto child : cur->children)
                    q.push(child);
            }

            ans.push_back(vec);
        }
        return ans;
    }
};