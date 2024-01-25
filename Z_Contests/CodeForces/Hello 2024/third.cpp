#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }

    vector<int> a,b;

    for(int i = 0 ; i < n ;i++){
        if(i == 0){
            a.push_back(arr[i]);
            continue;
        }

        if(a.back() > arr[i] ){
            a.push_back(arr[i]);
        }else{
            b.push_back(arr[i]);
        }
    }

    int ans = 0;

    for(int i = 1 ; i < b.size() ; i++){
        if(b[i-1] < b[i])
            ans++;
    }

    cout<<ans<<endl;

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