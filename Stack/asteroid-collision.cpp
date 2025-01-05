#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm> // For reverse
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int i = 0;

        while (i < nums.size()) {
            bool dest = false;
            while (!st.empty() && nums[i] < 0 && !dest) {
                if (st.top() > 0) {
                    if (st.top() == abs(nums[i])) {
                        st.pop();
                        dest = true;
                    } else if (st.top() > abs(nums[i])) {
                        dest = true;
                    } else if (st.top() < abs(nums[i])) {
                        st.pop();
                        dest = false;
                    }
                } else {
                    st.push(nums[i]);
                    dest = true;
                }
            }
            if (!dest)
                st.push(nums[i]);
            i++;
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> asteroids = {5, 10, -5}; // Example input
    vector<int> result = solution.asteroidCollision(asteroids);

    cout << "Result: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
