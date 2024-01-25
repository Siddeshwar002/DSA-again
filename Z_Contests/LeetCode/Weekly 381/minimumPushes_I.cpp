#include <bits/stdc++.h>
using namespace std;

    int minimumPushes(string word) {
        int len = word.length();
        
        int ans = 0;
        
        if(len <= 8){
            ans = len;
        }else if(len > 8 && len <= 16){
            ans = 8 + 2*(len-8);
        }else if(len > 16 && len <= 24){
            ans = 8 + 16 + 3*(len - 16);
        }else if(len >24){
            ans = 8 + 16 + 24 + 4*(len-24);
        }
        
        return ans;
    }

int main(){
    cout << minimumPushes("acolkxjbizfmhnrdq");
}