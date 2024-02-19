#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<string> extractCharacters(const string &input)
    {
        vector<string> result;
        stringstream ss(input);
        string token;

        while (getline(ss, token, ','))
        {
            result.push_back(token);
        }

        return result;
    }

    bool isValidSerialization(string preorder)
    {
        vector<string> characters = extractCharacters(preorder);

        int i = 0;
        // preorder.erase(remove(preorder.begin(), preorder.end(), ','), preorder.end());
        int n = characters.size() - 1;
        queue<pair<string, int>> q;
        q.push({characters[i], i});

        int idx;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            idx = cur.second;

            if (cur.first == "#")
                continue;

            if (idx * 2 + 1 > n || idx * 2 + 2 > n)
                return false;

            // if (idx * 2 + 1 <= n && characters[idx * 2 + 1] == "#" && idx * 2 + 2 > n)
            // return false;

            if (idx * 2 + 1 <= n)
                q.push({characters[idx * 2 + 1], idx * 2 + 1});
            if (idx * 2 + 2 <= n)
                q.push({characters[idx * 2 + 2], idx * 2 + 2});
        }

        if (idx < n)
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    string preorder = "9,#,92,#,#";
    // string preorder = "934##1##2#6##";
    cout << s.isValidSerialization(preorder);
}