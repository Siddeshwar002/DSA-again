// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Apprach 1 : 
// String manipulation
// Beats 100% of the solutions

class Solution {
public:
    string BuildLine(int start, int totalStr, int maxWidth, int curLen, vector<string>& words) {
        
        // handle single-word lines
        if (totalStr == 1) { 
            return words[start] + string(maxWidth - curLen, ' ');
        }

        int totalSpace = maxWidth - curLen;
        int inSpace = totalSpace / (totalStr - 1);
        int extraSpace = totalSpace % (totalStr - 1);

        // build the base spaces
        string spaces(inSpace, ' '); 
        string line = "";

        while (totalStr-- > 0) {
            line += words[start++];
            if (totalStr > 0) 
                line += spaces;
            if (extraSpace-- > 0) 
                line += " ";
        }
        
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int curStr = 0;       
        int curLen = words[0].length(); 
        int totalStr = 1;     

        for (int i = 1; i < words.size(); i++) {

            // if NO more strings can be accumulated 
            // Build the line for the strings collected so far
            if (curLen + totalStr + words[i].length() > maxWidth) { 
                ans.push_back(BuildLine(curStr, totalStr, maxWidth, curLen, words));
                curStr = i;          
                curLen = words[i].length();
                totalStr = 1;
            } else { 
                curLen += words[i].length();
                totalStr++;
            }
        }

        // Handle last line
        // Left justfied
        string lastLine = "";

        while (totalStr-- > 0) {
            lastLine += words[curStr++];
            if (totalStr > 0) lastLine += " ";
        }
        
        lastLine += string(maxWidth - lastLine.length(), ' ');
        ans.push_back(lastLine);

        return ans;
    }
};
