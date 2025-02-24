#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isEnd;
    unordered_map<char, TrieNode *> children;

    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                cur->children[c] = new TrieNode(); 
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    TrieNode *findNode(string s)
    {
        TrieNode *cur = root;
        for (char c : s)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                return nullptr;
            }
            cur = cur->children[c];
        }
        return cur;
    }

    bool search(string word)
    {
        TrieNode *node = findNode(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = findNode(word);
        return node != nullptr;
    }
};
