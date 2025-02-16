class Solution {
public:
    string convert(string s, int numRows) {
        int idx = numRows-1;
        string ans = "";
        vector<int> indices;

        // Edge Case
        if(numRows == 1)
            return s;
        

        // Collect the initial index 
        while(idx < s.length()){
            indices.push_back(idx);
            idx = idx + (numRows-1) * 2;
        }

        // Edge Case 
        indices.push_back(idx);

        // get all the correspoding indexes from one point to the other
        for(int i = numRows-1; i>= 0 ; i--){
            for(auto curidx : indices){
                int idx1 = curidx - (i);
                
                if(idx1 < s.length())
                    ans += s[idx1];

                // handle repeatations
                if(i != 0 && i != numRows-1){
                    int idx2 = curidx + i;

                    if(idx2 < s.length())
                        ans += s[idx2];
                }
            }
        }

        return ans;
    }
};