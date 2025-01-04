#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool solve(int idx, int cnt, string s, map<string,int> &mp){
    if (cnt < 0) return false;
    string x = to_string(idx) + "-" + to_string(cnt);
    
    if(idx == s.length()){
        if(cnt == 0)
            return true;
        return false;
    }

    if(mp.find(x) != mp.end())
        return mp[x];

    if(s[idx] == '(')
        return mp[x] = solve(idx+1, cnt+1, s, mp);
    else if(s[idx] == ')')
        return mp[x] = solve(idx+1, cnt-1, s, mp);
    else if(s[idx] == '*')
        return mp[x] = (solve(idx+1, cnt+1,s, mp) || solve(idx+1, cnt,s, mp) || solve(idx+1, cnt-1,s, mp));
    
    return mp[x] = false;
}
    bool checkValidString(string s) {
        map<string,int> mp;
        return solve(0,0,s, mp);
    }
};