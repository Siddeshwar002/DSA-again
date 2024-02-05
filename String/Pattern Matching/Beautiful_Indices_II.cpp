#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)
#define print(x) std::cout << (x) << std::endl

// KMP String matching algotithm
// Uses 'Z' Function to match

vector<int> KMP(string s, string p)
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

    return ans;
}

vector<int> beautifulIndices(string s, string a, string b, int k)
{
    vector<int> A = KMP(s, a);
    vector<int> B = KMP(s, b);
    vector<int> ans;

    int i = 0;
    // cout << "A" << A.size() << endl;
    loop(i, A.size())
    {
        cout << A[i] << " ";
    }
    print("");
    // cout << "B" << B.size() << endl;

    i = 0;
    loop(i, B.size())
    {
        cout << B[i] << " ";
    }

    print(".");
    cout << "ans";
    print(".");

    for (auto it : A)
    {
        int L = it - k;
        int R = it + k;
        int low = 0;
        int high = B.size() - 1;

        if (L < 0)
            L = 0;
        if (R > s.length() - 1)
            R = s.length() - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (L <= B[mid] && B[mid] <= R)
            {
                cout << it << " ";
                ans.push_back(it);
                break;
            }

            else if (B[mid] < L)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    string s = "isawsquirrelnearmysquirrelhouseohmy";
    string a = "my";
    string b = "squirrel";
    int k = 15;
    beautifulIndices(s, a, b, k);
}