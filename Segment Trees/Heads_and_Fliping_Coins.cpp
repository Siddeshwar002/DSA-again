#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

class Seg
{
private:
    vector<int> seg;
    vector<int> lazy;

public:
    Seg(int n) : seg(4 * n), lazy(4 * n) {}

    void Print()
    {
        cout << "SEG" << endl;
        for (auto it : seg)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    void Build(int idx, int low, int high, vector<int> arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        Build(2 * idx + 1, low, mid, arr);
        Build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }

    // * Range Flip Updates
    void UpdateLazy(int idx, int low, int high, int l, int r)
    {
        // * previous Updates
        if (lazy[idx] != 0)
        {
            seg[idx] = (high - low + 1) - seg[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }
            // * Flip done ans set = 0;
            lazy[idx] = 0;
        }

        if (l > high || r < low)
            return;

        if (l <= low && high <= r)
        {
            seg[idx] = (high - low + 1) - seg[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }
            lazy[idx] = 0;
            return;
        }

        int mid = (low + high) >> 1;
        UpdateLazy(2 * idx + 1, low, mid, l, r);
        UpdateLazy(2 * idx + 2, mid + 1, high, l, r);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        return;
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] = (high - low + 1) - seg[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }
            lazy[idx] = 0;
        }

        // No overlap
        if (high < l || r < low)
            return 0;

        // Complete overlap - return the answer
        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }
};

int main()
{
    vector<int> arr = {1, 1, 0, 0, 1, 0, 1};
    Seg s1(arr.size());
    int n = arr.size();
    s1.Build(0, 0, arr.size() - 1, arr);
    // s1.Print();
    cout << "q : " << s1.query(0, 0, n - 1, 2, 6) << endl;
    s1.UpdateLazy(0, 0, n - 1, 2, 6);
    cout << "q : " << s1.query(0, 0, n - 1, 2, 6) << endl;
}