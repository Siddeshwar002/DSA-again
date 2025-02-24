#include <bits/stdc++.h>
using namespace std;


// Correct Code but
// Memory Limit Exceeded
// 33 / 37 testcases passed

// Approach : 
//      - Same as the word-ladder I code
//      - Just saving the words into the list 
//      - but this gives MLE

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

            // IMP : 
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
                // This ofcourse will be the shortest sequence found
                if (ans.size() == 0)
                    ans.push_back(vec);
            
                // next time always check of the new sequence is of the same length
                // because we need all the shortest sequences only
                else if (ans[0].size() == vec.size())
                    ans.push_back(vec);
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

// -----------------------------------------------------------------------------------------
