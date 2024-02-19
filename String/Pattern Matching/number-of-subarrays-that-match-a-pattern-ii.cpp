#include <bits/stdc++.h>
using namespace std;

// Patter matching using KMP and Pi function
// String pre-processing

class Solution
{
public:
    int KMP(string s, string p)
    {
        s = p + '#' + s;
        cout << "S ";
        cout << s << endl;
        vector<int> Pi(s.length());
        vector<int> ans;
        Pi[0] = 0;

        for (int i = 1; i < s.length(); i++)
        {
            int j = Pi[i - 1];

            while (j > 0 && s[i] != s[j])
                j = Pi[j - 1];

            if (s[i] == s[j])
                j++;

            Pi[i] = j;
            if (j == p.length())
                ans.push_back(i - 2 * p.length());
        }

        return ans.size();
    }

    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        vector<int> newNums;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
                newNums.push_back(1);
            else if (nums[i - 1] == nums[i])
                newNums.push_back(0);

            // A little trick to make the pattern array contain 2 instead of -1
            // this becomes easy while comparing

            else if (nums[i - 1] > nums[i])
                newNums.push_back(2);
        }

        string s_str = "";
        for (int i : newNums)
        {
            s_str += to_string(i);
        }

        string p_str = "";
        for (int i : pattern)
        {
            if (i == -1)
                // Super trick  here, we change -1 in pattern to 2
                // "10-1" -> '-' is also considered as a character
                // we need both '-1' together for string check
                p_str += to_string(2);
            else
                p_str += to_string(i);
        }

        cout << s_str << " " << p_str << endl;

        return KMP(s_str, p_str);
    }
};