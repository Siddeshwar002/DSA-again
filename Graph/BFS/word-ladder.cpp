#include <bits/stdc++.h>
using namespace std;

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
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
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
                word[i] = originalChar;
            }
        }
        return 0;
    }
};