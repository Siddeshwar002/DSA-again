class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int n = citations.size();
        sort(citations.begin() , citations.end());

        for(int i = 0 ; i < n; i++){
            if(n-i >= citations[i])
                ans = max(ans , citations[i]);
            else 
                ans = max(ans, n-i);
        }
        return ans;
    }
};