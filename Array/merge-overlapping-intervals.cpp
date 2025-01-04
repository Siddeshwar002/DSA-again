// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/** Code 1 :
 *
 * Clean Code
 * No repetative if-else conditions
 * Learn how to code neat like a PRO
 *
 * If I would have written the code then there would be unnecessary if
 * conditions - Noob
 */

vector<vector<int> > merge(vector<vector<int> > &intervals) {
  // if there is only one interval then that itself is the answer
  if (intervals.size() <= 1)
    return intervals;

  // Sorting is very important
  sort(intervals.begin(), intervals.end());

  vector<vector<int>> output;

  // insert the first pair into the answer
  output.push_back(intervals[0]);

  for (int i = 1; i < intervals.size(); i++) {
    // if the next pair can fit inside the previously pushed pair then just
    // update the pair
    if (output.back()[1] >= intervals[i][0])
      output.back()[1] = max(output.back()[1], intervals[i][1]);
    else
      // if it dosen't fit in then just add this into the answer
      output.push_back(intervals[i]);
  }

  return output;
}