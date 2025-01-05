#include "stack"
#include "vector"
using namespace std;

class Solution {
public:

    // Calculating areas for each histgram created after considering each row
     int area_of_each_row(vector<int> arr) {
        stack<int> st;
        int i = 0;
        int area = 0;

        while (i < arr.size()) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int nse = i;
                int curEle = arr[st.top()];
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                area = max(area, curEle * (nse - pse - 1));
            }
            st.push(i);
            i++;
        }

        while (!st.empty()){
            int nse = arr.size();
            int curEle = arr[st.top()];
            st.pop();
            int pse = !st.empty() ? st.top() : -1;
            area = max(area, curEle * (nse - pse - 1));
        }
        return area;
    }

  int maximalRectangle(vector<vector<char>>& matrix) {
    
    if (matrix.empty() || matrix[0].empty()) return 0;

    vector<int> arr(matrix[0].size(), 0);
    int maxArea = 0;

    for (const auto& vec : matrix) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == '0')
                arr[i] = 0;
            else
                arr[i] += 1;  
        }

        maxArea = max(maxArea, area_of_each_row(arr));
    }

    return maxArea;
}

};