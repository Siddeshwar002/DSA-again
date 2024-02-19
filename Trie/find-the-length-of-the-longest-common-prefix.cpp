#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> links;
    int cntLength = 0;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        // Initialize root node
        root = new TrieNode();
    }

    void insert(int num)
    {
        string s = to_string(num);
        TrieNode *cur = root;
        for (auto c : s)
        {
            if (cur->links.find(c) == cur->links.end())
                cur->links[c] = new TrieNode();
            cur = cur->links[c];
            // Increment count for each character
            cur->cntLength++;
        }
    }

    int search(int num)
    {
        string s = to_string(num);
        TrieNode *cur = root;

        int len = 0;
        for (auto c : s)
        {
            if (cur->links.find(c) == cur->links.end())
                return len;
            cur = cur->links[c];
            len++;
        }
        return len;
    }
};

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (auto num : arr2)
        trie.insert(num);

    int ans = 0;

    for (auto num : arr1)
    {
        int lcp = trie.search(num);
        ans = max(ans, lcp);
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << "ans :" << longestCommonPrefix(arr1, arr2);
}
