#include <bits/stdc++.h>
using namespace std;

//* Given a string s, partition s such that every
//* substring
//* of the partition is a
//* palindrome.
//* Return all possible palindrome partitioning of s.

//! TC - O(2^N) * O(N/2)
//! O(2^N) --> Recursive Calls
//! O(N/2)   --> To check Is Pallindrom

// TODO : Can be improved by using DP

bool IsPallindrom(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}

// ! SMART CODE
void printPartitions(string str, int idx, vector<string> vec, vector<vector<string>> &ans)
{
    if (idx == str.length())
    {
        ans.push_back(vec);
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        // * Partition the string only if it is a Pallindrom
        if (IsPallindrom(str, idx, i))
        {
            vec.push_back(str.substr(idx, i - idx + 1));
            printPartitions(str, i + 1, vec, ans);
            vec.pop_back();
        }

        // * else -> there is nothing to do
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> vec;
    vector<vector<string>> ans;
    printPartitions(s, 0, vec, ans);
    return ans;
}

int main()
{
}