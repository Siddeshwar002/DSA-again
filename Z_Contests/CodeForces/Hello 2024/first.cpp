#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    // if(a == b){
    //     cout<<"Bob";
    //     return;
    // }

    int diff = abs(a - b);

    if (a == b or diff % 2 == 0)
    {
        cout << "Bob"<<endl;
    }
    else
    {
        cout << "Alice" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}