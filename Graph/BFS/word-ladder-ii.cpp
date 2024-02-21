#include <bits/stdc++.h>
using namespace std;

// Correct
// TLE

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // to mark the entry of new level
            // trick part
            // deletion after the whole level is completed
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                // if we get the same size then only we add it
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);

                        // mark as visited on the level
                        usedOnLevel.push_back(word);

                        // backtracking
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

// $*******************************************
