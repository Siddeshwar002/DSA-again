#include <string>
#include <climits>

// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(std::string s) {
        int idx = 0;
        int n = s.length();
        
        // Skip leading spaces
        while (idx < n && s[idx] == ' ') {
            idx++;
        }
        
        // Handle optional sign
        int sign = 1;
        // idx is getting incremented so handle index out of bounds
        if (idx < n && (s[idx] == '+' || s[idx] == '-')) {
            // Make sure to save the sign as (+1) or (-1)
            // you need it in the end
            sign = (s[idx] == '-') ? -1 : 1;
            idx++;
        }
        
        // Skip leading zeros
        // Index is getting incremented so handle out of the bound errors
        while (idx < n && s[idx] == '0') {
            idx++;
        }
        
        // Convert digits to integer
        long result = 0;

        // if ay any index it fails to be a numeric character
        // then just exit loop
        while (idx < n && isdigit(s[idx])) {
            result = result * 10 + (s[idx] - '0');
            
            // Handle overflow cases
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            idx++;
        }
        
        // Multiply the sign and return the result
        return static_cast<int>(result * sign);
    }
};