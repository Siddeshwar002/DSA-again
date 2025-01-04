#include "../../stdc++.h"
using namespace std;

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

char get_char_at_idx(int n, int idx, vector<int> &num)
{
    int count = 0;               // Count of valid elements
    for (int i = 1; i <= n; i++) // Iterate through all numbers
    {
        if (!num[i]) // If the number is not used
        {
            count++;
            if (count == idx) // Found the required index
            {
                num[i] = 1;     // Mark as used
                return '0' + i; // Convert to char and return
            }
        }
    }
    return '0'; // Should not reach here for valid inputs
}

string get_kth_permutation(int n, int k)
{
    int factorial = fact(n);
    string ans = "";
    vector<int> num(n + 1, 0); // Track used numbers
    int nn = n;

    while (nn > 0)
    {
        int set_elements = factorial / nn;        // Elements in each subset
        int set_idx = (k - 1) / set_elements + 1; // 1-based index for the subset

        char c = get_char_at_idx(n, set_idx, num); // Get character for this index
        ans += c;

        nn -= 1;                        // Reduce the number of elements
        factorial = set_elements;       // Update factorial
        k = (k - 1) % set_elements + 1; // Update k to the new index within the subset
    }

    return ans;
}

int main()
{
    int n = 4;  // Number of elements
    int k = 17; // k-th permutation

    cout << get_kth_permutation(3, 1) << endl; // Output: 3412
    return 0;
}
