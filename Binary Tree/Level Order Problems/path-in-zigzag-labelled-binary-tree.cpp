#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Mathematical solution
// accepted 

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int h = log2(label);
        int node = label;

        vector<int> ans;
        
        while(node != 1){
            ans.push_back(node);
            int range = pow(2,h) + pow(2,h+1)-1;
            h--;
            int parent = (range - node)/2;
            node = parent;
        }
        ans.push_back(node);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};