// #include <bits/stdc++.h>

#include <vector>
#include <iostream>
#include <set>
using namespace std;

/** Code 1 : Optimal Approach */

void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

/** Code : Most Optimal Approach
 *
 * - gap method
 * - shell sort method
 */

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap : always take the ceil value
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // case 1: left in arr1[]
            // and right in arr2[]:
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }

        // break if iteration gap=1 is completed:
        if (gap == 1)
            break;

        // Otherwise, calculate new gap, take the ceil value for the gap
        gap = (gap / 2) + (gap % 2);
    }
}
