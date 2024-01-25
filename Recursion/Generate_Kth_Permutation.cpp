#include <bits/stdc++.h>
using namespace std;

// * Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N])
// * find the Kth permutation sequence.

// ! This CODE FAILS a few test cases.
// ! The CODE can be made SMARTER

int getFactorial(int n)
{
    int fac = 1;
    while (n)
    {
        fac *= n--;
    }
    return fac;
}

set<int> getSet(int n)
{
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    return s;
}

string getPermutation(int n, int k)
{
    set<int> s = getSet(n);
    int Fact = getFactorial(n);
    string str = "";

    int i = 0;
    int N = n;
    k = double(k);
    while (k != 0 and i < n)
    {
        double slot = Fact / N;
        double block = (k / slot);
        block = ceil(block);
        auto it = s.begin();
        advance(it, block-1);
        int ele = *it;
        // cout << ele << " ";
        str += ('0' + ele);
        s.erase(it);
        Fact = slot;
        k = k % int(slot);
        N--;
        i++;
    }

    if (!s.empty())
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            str += ('0' + *it);
        }
    }

    cout << str << endl;
    return str;
}

int main()
{
    string ans = getPermutation(3, 2);
}