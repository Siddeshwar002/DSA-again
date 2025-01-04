#include <vector>
#include <iostream>
#include <set>
using namespace std;

/** Approach 1 :
 *      Concept : Merge Overlapping Intervals
 */

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> x;
        vector<vector<int>> y;

        for (auto rect : rectangles)
        {
            x.push_back({rect[0], rect[2]});
            y.push_back({rect[1], rect[3]});
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        vector<vector<int>> x_merge;
        vector<vector<int>> y_merge;

        int cut = 0;

        x_merge.push_back(x[0]);
        for (int i = 1; i < x.size(); i++)
        {
            if (x_merge.back()[1] <= x[i][0])
            {
                cut++;
                x_merge.push_back(x[i]);
            }
            else
                x_merge.back()[1] = max(x_merge.back()[1], x[i][1]);
            if (cut == 2)
                return true;
        }

        cut = 0;

        y_merge.push_back(y[0]);
        for (int i = 1; i < y.size(); i++)
        {
            if (y_merge.back()[1] <= y[i][0])
            {
                cut++;
                y_merge.push_back(y[i]);
            }
            else
                y_merge.back()[1] = max(y_merge.back()[1], y[i][1]);
            if (cut == 2)
                return true;
        }

        return false;
    }
};

/** code 2 :
 *
 *      A very little modification in loops
 */

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> x, y;

        for (auto rect : rectangles)
        {
            x.push_back({rect[0], rect[2]}); // x-intervals
            y.push_back({rect[1], rect[3]}); // y-intervals
        }

        // Sort x and y intervals
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        vector<vector<int>> x_merge, y_merge;
        int cut_x = 0, cut_y = 0;

        x_merge.push_back(x[0]);
        y_merge.push_back(y[0]);

        // convert two loops into single loop

        for (int i = 1; i < x.size(); i++)
        {
            // Process x intervals
            if (x_merge.back()[1] <= x[i][0])
            {
                cut_x++;
                x_merge.push_back(x[i]);
            }
            else
            {
                x_merge.back()[1] = max(x_merge.back()[1], x[i][1]);
            }

            // Process y intervals
            if (y_merge.back()[1] <= y[i][0])
            {
                cut_y++;
                y_merge.push_back(y[i]);
            }
            else
            {
                y_merge.back()[1] = max(y_merge.back()[1], y[i][1]);
            }

            // If either x or y has two cuts, return true
            if (cut_x == 2 || cut_y == 2)
            {
                return true;
            }
        }

        return false;
    }
};
