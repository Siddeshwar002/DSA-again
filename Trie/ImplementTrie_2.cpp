#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> links;
    int cntEndWith = 0;
    int cntPrefix = 0;
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

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.find(ch) == node->links.end())
            {
                node->links[ch] = new TrieNode();
            }
            node = node->links[ch];
            node->cntPrefix++;
        }
        node->cntEndWith++;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.find(ch) != node->links.end())
            {
                node = node->links[ch];
            }
            else
            {
                return false;
            }
        }
        return node->cntEndWith > 0;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->links.find(ch) != node->links.end())
            {
                node = node->links[ch];
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.find(ch) != node->links.end())
            {
                node = node->links[ch];
            }
            else
            {
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.find(ch) != node->links.end())
            {
                node = node->links[ch];
            }
            else
            {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->links.find(ch) != node->links.end())
            {
                node = node->links[ch];
                node->cntPrefix--;
            }
            else
            {
                return;
            }
        }
        node->cntEndWith--;
    }
};

// Example usage
int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("apricot");

    // * while passing pass the data through assigned variable
    string searchWord = "a";

    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 1
    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 1
    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 0

    cout << trie.countWordsStartingWith(searchWord) << endl; // Output: 3

    trie.erase(searchWord);
    cout << trie.countWordsStartingWith(searchWord) << endl; // Output: 0

    return 0;
}
