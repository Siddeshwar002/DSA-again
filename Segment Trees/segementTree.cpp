#include <bits/stdc++.h>
using namespace std;

// ! Segment Tree
// * Minimum of the range [l , r]

class SegTree
{
private:
    vector<int> seg;

public:
    SegTree(int n) : seg(4 * n) {}

    void Print()
    {
        for (auto it : seg)
        {
            cout << it << " ";
        }
    }

    void Build(int idx, int low, int high, vector<int> arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        Build(idx * 2 + 1, low, mid, arr);
        Build(idx * 2 + 2, mid + 1, high, arr);
        seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
        return;
    }

    int query(int idx, int low, int high, vector<int> arr, int l, int r)
    {
        // No overlap
        if (r < low || high < l)
            return INT_MAX;

        // Complete overlp
        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(idx * 2 + 1, low, mid, arr, l, r);
        int right = query(idx * 2 + 2, low, mid, arr, l, r);
        return min(left, right);
    }

    void update(int idx, int low, int high, vector<int> arr, int index, int value)
    {
        if (low = high)
        {
            seg[idx] = value;
            return;
        }

        int mid = (low + high) >> 1;

        if (index <= mid)
            update(idx * 2 + 1, low, mid, arr, index, value);
        else
            update(idx * 2 + 2, mid + 1, high, arr, index, value);

        seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
};

int main()
{
    vector<int> arr = {1, 3, 2, 0, 4, 5};
    SegTree st1(arr.size());
    st1.Build(0, 0, arr.size() - 1, arr);
    st1.Print();
    return 0;
}
