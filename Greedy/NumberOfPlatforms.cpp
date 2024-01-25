#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int,int>> vp;

    for (int i = 0; i < n; i++)
    {
        vp.push_back(make_pair(dep[i], i));
    }
    sort(vp.begin(), vp.end());

    vector<int> Plat(n,INT16_MAX);
    int no = -1;

    Plat[0] = dep[0];
    bool flag = 0;

    for(auto x : vp){
        cout<<x.first<<" "<<x.second<<endl;
    }

    for(auto v : vp){
        bool flag = 0;
        for(auto P : Plat){
            if(arr[v.second] > P){
                Plat[no] = v.first;
                flag = 1;
                break;
            }
        }
        if(!flag){
            Plat[++no] = v.first;
            cout<<Plat[0]<<endl;
        }
    }
    
    return no+1;

}

int main(){

    int n = 6;
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int ans = findPlatform(arr, dep, n);
}