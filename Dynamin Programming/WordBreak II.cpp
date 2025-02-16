#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> res; // Stores the final results
    vector<vector<int>> dpp; // 2D array to store valid substrings

    // Backtracking function to build valid sentences
    void buildStrings(int idx, string ans, int len, string& s) {
        if (idx >= len) {
            ans.pop_back(); // Remove the trailing space
            res.push_back(ans);
            return;
        }

        for (int j = 1; j <= len - idx; j++) {
            if (dpp[idx][j] == 1) { // If the substring is valid
                string temp = s.substr(idx, j); // Extract the substring
                string newAns = ans + temp + " "; // Add it to the current answer
                buildStrings(idx + j, newAns, len, s); // Recur for the remaining string
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // Convert dictionary to a set for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); 

        // Initialize the 2D array
        dpp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        // Fill the 2D array
        // O(N^2) to fill up the dpp table for O(1) access
        for (int start = 0; start < n; start++) {
            for (int length = 1; length <= n - start; length++) {
                string substring = s.substr(start, length);
                if (dict.find(substring) != dict.end()) {
                    dpp[start][length] = 1; // Mark the substring as valid
                }
            }
        }

        // Start backtracking to build all valid sentences
        buildStrings(0, "", n, s);

        // Print the results (optional)
        for (auto s : res) {
            cout << s << endl;
        }

        return res;
    }
};