#include <bits/stdc++.h>
using namespace std;

class Seg
{
private:
    vector<int> seg;
    vector<int> lazy;

public:
    Seg(int n) : seg(4 * n), lazy(4 * n){};

    // * Build Reamains same
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
    }

    void UpdateLazy(int idx, int low, int high, int l, int r, int value)
    {
        // Before the current update
        // check if there were any previous updates
        // * Propagate the changes in the tree to its child nodes
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        // No overlap
        if (high < l || r < low)
        {
            return;
        }

        // complete overlap
        if (low >= l && high <= r)
        {
            // Update the current node
            seg[idx] += (high - low + 1) * value;

            // propogate to the children nodes
            if (low != high)
            {
                lazy[2 * idx + 1] += value;
                lazy[2 * idx + 2] += value;
            }
            return;
        }

        // Partial Overlap
        int mid = (low + high) >> 1;
        UpdateLazy(2 * idx + 1, low, high, l, r, value);
        UpdateLazy(2 * idx + 2, mid + 1, high, l, r, value);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // Lazy Propogation
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        // No overlap
        if (high < l || r < low)
            return;

        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }
};
