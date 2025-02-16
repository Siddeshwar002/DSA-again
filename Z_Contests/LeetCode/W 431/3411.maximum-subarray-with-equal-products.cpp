#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized approach : 
// To efficiently compute the GCD and LCM, we can use the following mathematical properties:

// GCD Property:
// gcd(a, b, c) = gcd(gcd(a, b), c)

// This means that to calculate the GCD of three or more numbers, you can iteratively compute the GCD of pairs of numbers.

// LCM Property:
// lcm(a, b, c) = lcm(lcm(a, b), c)

// Similarly, to calculate the LCM of three or more numbers, you can iteratively compute the LCM of pairs of numbers.

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        for (int start = 0; start < n; ++start) {
            long long product = 1, g = 0, l = 1;
            
            for (int end = start; end < n; ++end) {

                if (product > INT_MAX / nums[end]) {
                    break;  
                }
                
                product *= nums[end]; 

                g = (g == 0) ? nums[end] : gcd(g, nums[end]); 

                l = lcm(l, nums[end]); 
                
                if (product == g * l) {
                    maxLen = max(maxLen, end - start + 1);
                }
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 4};  
    cout << sol.maxLength(nums) << endl;  
    return 0;
}
