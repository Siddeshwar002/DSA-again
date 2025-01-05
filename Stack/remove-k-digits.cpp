#include "stack"
#include "vector"
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int i = 0;

        while(i < num.size()) {
            while(k > 0 && !st.empty() && st.top() > num[i] - '0') {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
            i++;
        }

        // If k is still greater than 0, remove the remaining digits from the stack
        while(k > 0) {
            st.pop();
            k--;
        }

        string s;
        while(!st.empty()) {
            s += st.top() + '0';  // Convert integer to char and append to string
            st.pop();
        }

        // Reverse the string as the stack pops from the back
        reverse(s.begin(), s.end());

        // Remove leading zeros if present
        int idx = 0;
        while (idx < s.size() && s[idx] == '0') {
            idx++;
        }

        // If there are no digits left after removing zeros, return "0"
        if (idx == s.size()) {
            return "0";
        }

        return s.substr(idx);  // Return the result without leading zeros
    }
};
