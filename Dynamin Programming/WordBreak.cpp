#include <bits/stdc++.h>
using namespace std;

// * CORRECT

bool word(string s, vector<string> &dict, int start)
{

    for (int i = start; i < s.length(); i++)
    {
        if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && i == s.length() - 1)
            return true;
        else if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && word(s, dict, i + 1))
            return true;
    }
    return false;
}

bool wordBreak(string s, vector<string> &dict)
{
    return word(s, dict, 0);
}

// ! ***************************************************************************
// ! Wrong DP

bool word(string s, vector<string> &dict, int start, vector<bool> &dp)
{

    if (dp[start])
        return dp[start];

    for (int i = start; i < s.length(); i++)
    {
        // ! Why wrong ?

        // * dp[start] : start -> starting index
        // * dp[i] : i -> ending index
        // * you are messing up the whole indexing
        // * store only starting index or ending index
        // * we know the value of starting index -> So storing w.r.t starting index is CORRECT

        if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && i == s.length() - 1)
            return dp[i] = true;
        else if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && word(s, dict, i + 1, dp))
            return dp[i] = true;
    }
    return dp[start] = false;
}

bool wordBreak(string s, vector<string> &dict)
{
    vector<bool> dp(s.length() + 1, false);
    return word(s, dict, 0, dp);
}

// ! ***************************************************************************

// * Correct Code
bool word(string s, vector<string> &dict, int start, vector<int> &dp)
{
    if (start == s.length())
    {
        return true;
    }

    if (dp[start] != -1)
    {
        return dp[start];
    }

    for (int i = start; i < s.length(); i++)
    {
        if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && word(s, dict, i + 1, dp))
        {
            return dp[start] = true;
        }
    }

    return dp[start] = false;
}

// ***************************************************************************
// Tabulation
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<int> dp(s.length() + 1, 0);

    // empty string is always in dictionary
    dp[0] = 1;

    for (int len = 1; len <= s.length(); len++)
    {
        for (int start = 0; start < len; start++)
        {
            if (dp[start] && find(wordDict.begin(), wordDict.end(), s.substr(start, len - start)) != wordDict.end())
            {
                dp[len] = 1;
                break;
            }
        }
    }

    // return if there exist words for len = s.length();
    return dp[s.length()];
}
bool wordBreak(string s, vector<string> &dict)
{
    vector<int> dp(s.length(), -1);
    return word(s, dict, 0, dp);
}

int main()
{
    vector<string> v{"aaaa", "aaa"};
    string str = "aaaaaaa";
    cout << wordBreak(str, v) << endl;
    return 0;
}