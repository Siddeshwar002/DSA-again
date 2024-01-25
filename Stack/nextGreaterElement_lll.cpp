#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n)
{
    long long ans = 0;

    vector<int> vec;
    int num = n;

    if (n == 0)
        return 0;

    while (num != 0)
    {
        int dig = num % 10;
        num /= 10;
        vec.push_back(dig);
    }
    reverse(vec.begin(), vec.end());

    int idx = -1;

    for (int i = vec.size() - 2; i >= 0; i--)
    {
        if (vec[i] < vec[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        return -1;
    }

    else if (idx != -1)
    {
        for (int i = vec.size() - 1; i > idx; i--)
        {
            if (vec[idx] < vec[i])
            {
                swap(vec[idx], vec[i]);
                break;
            }
        }
        reverse(vec.begin() + idx + 1, vec.end());
        for (auto it : vec)
        {
            ans *= 10;
            ans += it;
        }
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
}

int main()
{
    int n = 123;
    return nextGreaterElement(n);
}