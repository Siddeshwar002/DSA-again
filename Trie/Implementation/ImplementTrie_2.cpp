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
    // Create the trie
    Trie()
    {
        root = new TrieNode();
    }

    // Word insertion
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

    //  search if this word is present
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

    // check if there exists any word starting with this prefix
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

    // the whole words which are equal
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

    // The words which have this same prefix
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

int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("apricot");

    string searchWord = "a";

    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 1
    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 1
    cout << trie.countWordsEqualTo(searchWord) << endl; // Output: 0

    cout << trie.countWordsStartingWith(searchWord) << endl; // Output: 3

    trie.erase(searchWord);
    cout << trie.countWordsStartingWith(searchWord) << endl; // Output: 0

    return 0;
}
