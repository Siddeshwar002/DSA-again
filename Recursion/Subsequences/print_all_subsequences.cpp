#include "../../stdc++.h"
using namespace std;

/* The following functiosn differ in the way they print the output */

/*
Output :
3
2
2 3
1
1 3
1 2
1 2 3
*/
namespace Version1
{
    void print_all_subsequences(int i, int n, vector<int> vec, vector<int> ans)
    {
        if (i == n)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
            return;
        }
        print_all_subsequences(i + 1, n, vec, ans);
        ans.push_back(vec[i]);
        print_all_subsequences(i + 1, n, vec, ans);
        return;
    }
}

/*
Output :

1 2 3
1 2
1 3
1
2 3
2
3
*/
namespace Version2
{
    void print_all_subsequences(int i, int n, vector<int> vec, vector<int> ans)
    {
        if (i == n)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
            return;
        }
        ans.push_back(vec[i]);
        print_all_subsequences(i + 1, n, vec, ans);
        ans.pop_back();
        print_all_subsequences(i + 1, n, vec, ans);
        return;
    }
}

int main()
{
    vector<int> vec = {1, 2, 3};
    vector<int> ans;
    Version1::print_all_subsequences(0, 3, vec, ans);
}