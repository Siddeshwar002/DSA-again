#include <iostream>
#include <vector>
using namespace std;

// ! Approach 1 : Bit manipulation
// ! TC  : O(2^n * n)

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    // Loop from 0 to 2^n - 1
    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> sub;

        // Iterate through each bit of the current 'num'
        for (int i = 0; i < n; i++)
        {
            // Check if the ith bit of 'num' is set (1)
            if (num & (1 << i))
            {
                sub.push_back(nums[i]); // Include the corresponding element from 'nums'
            }
        }

        ans.push_back(sub); // Add the generated subset to 'ans'
    }

    return ans; // Return the vector containing all subsets
}

// ! Approach 2 : Consider, Not Consider
// ! TC  : O(2^n)

void solve(int i, string s, string &f)
{
    if (i == s.length())
    {
        cout << f << " ";
        return;
    }
    // picking
    f = f + s[i];
    solve(i + 1, s, f);
    // poping out while backtracking
    f.pop_back();
    solve(i + 1, s, f);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    // Display the generated subsets
    for (auto sub : result)
    {
        cout << "[";
        for (int i = 0; i < sub.size(); i++)
        {
            cout << sub[i];
            if (i < sub.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
