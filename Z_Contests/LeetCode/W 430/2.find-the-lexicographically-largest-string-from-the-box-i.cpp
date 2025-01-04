// 3403. Find the Lexicographically Largest String From the Box I

class Solution {
public:
    string answerString(string word, int numFriends) {
        char prev = word[0];
        int idx = 0;
        vector<int> indices;
        indices.push_back(0);
        
        if(numFriends == 1)return word;
        
        for(int i = 1; i< word.length() ; i++){
            if(word[i] > prev){
                indices.clear();
                indices.push_back(i);
                prev = word[i];
                // idx = i;
            }else if(word[i] == prev){
                indices.push_back(i);
            }
        }
        
        int len = word.size();
        int req_len = len - (numFriends-1);
        
        string ans;
        for(auto idx : indices){
            int cur_len = min(req_len , (len - idx)); 
            string cur_ans = word.substr(idx , req_len);
            ans = max(ans , cur_ans);
        }
        
        return ans;
    }
};