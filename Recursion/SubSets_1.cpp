#include <bits/stdc++.h>
using namespace std;

// ! Print Sum of All Subsets

void SumOfAllSubsets(int arr[], int n, int i, int sum)
{
    if (i == n)
    {
        cout << sum << " ";
        return;
    }

    SumOfAllSubsets(arr, n, i + 1, sum);
    SumOfAllSubsets(arr, n, i + 1, sum + arr[i]);
}

int main()
{
    int arr[] = {5, 2, 1};

    SumOfAllSubsets(arr, sizeof(arr) / sizeof(arr[0]), 0, 0);
}