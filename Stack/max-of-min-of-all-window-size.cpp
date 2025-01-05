#include <bits/stdc++.h>
using namespace std;

std::vector<int> maxOfMin(int arr[], int n)
{
    std::vector<int> result(n, 0);
    std::stack<int> st; // Monotonic stack to track previous and next smaller elements

    // Arrays to store the previous and next smaller elements for each index
    std::vector<int> prevSmaller(n, -1);
    std::vector<int> nextSmaller(n, n);

    // Finding the previous smaller element for each index
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            prevSmaller[i] = st.top();
        }
        st.push(i);
    }

    for (auto it : prevSmaller)
        cout << it << " ";
    cout << endl;

    // Clear the stack for the next iteration
    while (!st.empty())
    {
        st.pop();
    }

    // Finding the next smaller element for each index
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }

    for (auto it : nextSmaller)
        cout << it << " ";
    cout << endl;

    // Calculate the maximum of the minimums for each window size
    cout<<"Window Size"<<endl;
    for (int i = 0; i < n; ++i)
    {
        int windowSize = nextSmaller[i] - prevSmaller[i] - 1;
        cout<<windowSize<<" ";
        result[windowSize - 1] = std::max(result[windowSize - 1], arr[i]);

    }

    for (auto it : result)
        cout << it << " ";
    cout << endl;

    // Fill in any remaining values in the result vector
    for (int i = n - 2; i >= 0; --i)
    {
        result[i] = std::max(result[i], result[i + 1]);
    }

    for (auto it : result)
        cout << it << " ";
    cout << endl;

    return result;
}

int main(){
    int N = 7;
    int arr[] = {10,20,30,50,10,70,30};
    maxOfMin(arr , N);

}

