#include <bits/stdc++.h>
using namespace std;

// * Generate all the permutation possible for give N where array is (1,2,3....N)

//! TC : O( N! )
//! which is greater that 2^N
//! Recursive call for each position

void PrintAllPermutations(int arr[], int N, int pos, bool mp[], vector<vector<int>> &Fans)
{
    if (pos == N)
    {
        vector<int> vec(N, 0);
        // for (int i = 0; i, N; i++)
        // {
        //     vec[i] = arr[i];
        // }
        // Fans.push_back(vec);

        cout << " ";
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!mp[i])
        {
            mp[i] = true;
            arr[pos] = i;
            PrintAllPermutations(arr, N, pos + 1, mp, Fans);
            mp[i] = false;
        }
    }
}

int main()
{
    int N = 4;
    bool mp[N + 1] = {false};
    int arr[N];
    vector<vector<int>> Fans;
    PrintAllPermutations(arr, N, 0, mp, Fans);
}