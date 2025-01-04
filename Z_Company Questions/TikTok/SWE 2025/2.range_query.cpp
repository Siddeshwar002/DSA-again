#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
QUESTION :
Given a string s consisting of stars"*" and bars "|", an array of starting indices startindex,
and an array of ending indices endindex, determine the number of stars between any two bars within
the substring between the two indices, inclusive. Note that in this problem, indexing starts at 1.
*/

vector<int> countStarsBetweenBars(string s, vector<int> &startIndex, vector<int> &endIndex)
{
    int n = s.size();
    vector<int> prefixStars(n, 0);
    vector<int> leftBar(n, -1), rightBar(n, -1);
    vector<int> result;

    // Step 1: Compute prefix sum of stars
    for (int i = 0; i < n; i++)
    {
        prefixStars[i] = (i > 0 ? prefixStars[i - 1] : 0) + (s[i] == '*' ? 1 : 0);
    }

    // Step 2: Compute nearest left and right bars for each position
    int lastBar = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '|')
            lastBar = i;
        leftBar[i] = lastBar;
    }

    lastBar = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '|')
            lastBar = i;
        rightBar[i] = lastBar;
    }

    // Step 3: Process each query
    for (int q = 0; q < startIndex.size(); q++)
    {
        int start = startIndex[q] - 1; // Convert to 0-based index
        int end = endIndex[q] - 1;     // Convert to 0-based index

        int left = rightBar[start];
        int right = leftBar[end];

        if (left != -1 && right != -1 && left < right)
        {
            result.push_back(prefixStars[right] - prefixStars[left]);
        }
        else
        {
            result.push_back(0);
        }
    }

    return result;
}

int main()
{
    string s = "|**|*|*";
    vector<int> startIndex = {1, 1, 3};
    vector<int> endIndex = {5, 6, 7};

    vector<int> result = countStarsBetweenBars(s, startIndex, endIndex);

    for (int stars : result)
    {
        cout << stars << endl;
    }

    return 0;
}
