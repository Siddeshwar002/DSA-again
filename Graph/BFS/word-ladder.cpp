#include <bits/stdc++.h>
using namespace std;


// BFS is optimal for finding the shortest path in an unweighted graph
// while DFS explores all possible paths deeply before backtracking.

// BREADTH FIRST SEARCH
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty())
        {
            auto Curword = q.front();
            string word = Curword.first;
            int steps = Curword.second;
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.length(); i++)
            {
                // save the current character
                char originalChar = word[i];

                // Loop until for all 26 characters
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // find for each new word that's formed
                    if (s.find(word) != s.end())
                    {
                        q.push({word, steps + 1});
                        s.erase(word);
                    }
                }

                // this is important line of code
                // after all "ait, bit, cit ................ ,zit"
                // you need to get back to "hit"
                // and now you replace second character
                
                // retirve the saved character
                word[i] = originalChar;
            }
        }
        return 0;
    }
};


// -----------------------------------------------------------------------------------------
// DEPTH FIRST SEARCH

class Solution {
public:
    // Stores the shortest transformation sequence length
    int minSteps = INT_MAX; 

    void dfs(string word, string& endWord, set<string>& wordList, int steps) {
        if (word == endWord) {
            minSteps = min(minSteps, steps);
            return;
        }

        // Try changing each character in the word
        for (int i = 0; i < word.length(); i++) {
            char originalChar = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                // Skip replacing with the same character
                if (ch == originalChar) continue; 

                word[i] = ch;
                // Valid transformation
                if (wordList.find(word) != wordList.end()) { 
                    // Mark as visited
                    wordList.erase(word);

                    // Check recursivelys
                    dfs(word, endWord, wordList, steps + 1);

                    // Backtrack: Restore word for other paths                    
                    wordList.insert(word);
                }
            }

            // Restore original character before next iteration
            word[i] = originalChar; 
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord is not in the list, return 0
        if (wordSet.find(endWord) == wordSet.end()) return 0; 

        dfs(beginWord, endWord, wordSet, 1);

        // endWord is in the list, but its not reachable then return 0
        return (minSteps == INT_MAX) ? 0 : minSteps;
    }
};
