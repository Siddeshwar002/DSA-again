#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public :
    unordered_map<char, TrieNode *> children;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->children.find(bit) == node->children.end())
            {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int find_Max_XOR(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (node->children.find(!bit) != node->children.end())
            {
                maxNum = maxNum | (1 << i);
                node = node->children[!bit];
            }
            else
                node = node->children[bit];
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(arr1[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, trie.find_Max_XOR(arr2[i]));
    }
    return maxi;
}

int main()
{
    vector<int> arr1 = {6, 8};
    vector<int> arr2 = {7, 8, 2};
    int n = 2, m = 3;
    cout << maxXOR(n, m, arr1, arr2) << endl;
    return 0;
}