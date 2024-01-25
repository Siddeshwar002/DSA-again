#include <vector>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2] = {nullptr, nullptr};
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
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (cur->children[bit] == nullptr)
            {
                cur->children[bit] = new TrieNode();
            }
            cur = cur->children[bit];
        }
    }

    int getMaxXOR(int num)
    {
        TrieNode *cur = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (cur->children[1 - bit] != nullptr)
            {
                maxXor |= (1 << i);
                cur = cur->children[1 - bit];
            }
            else
            {
                cur = cur->children[bit];
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        int maxResult = 0;
        Trie trie;

        for (int num : nums)
        {
            trie.insert(num);
            int maxXor = trie.getMaxXOR(num);
            maxResult = max(maxResult, maxXor);
        }

        return maxResult;
    }
};
