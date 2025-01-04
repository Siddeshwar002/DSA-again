#include <iostream>
#include <set>
#include <vector>
using namespace std;

/** Recursive Code :  */

// class Solution
// {
// public:
//     int solve(int i, int j, int currentXor, vector<vector<int> > &grid, int
//     k)
//     {

//         if (i > grid.size() - 1 || j > grid[0].size() - 1)
//             return 0;

//         currentXor ^= grid[i][j];

//         if (i == grid.size() - 1 && j == grid[0].size() - 1)
//         {
//             if (currentXor == k)
//                 return 1;
//             return 0;
//         }

//         int paths = 0;

//         paths += solve(i + 1, j, currentXor, grid, k);
//         paths += solve(i, j + 1, currentXor, grid, k);

//         return paths;
//     }
//     int countPathsWithXorValue(vector<vector<int> > &grid, int k)
//     {
//         int res = solve(0, 0, 0, grid, k);
//         return res;
//     }
// };

/** Memoization code :
 *
 *      - 3D DP
 *      - for each dp[i][j] there could be many current XORs possible depending
 * upon the path that was taken to reach the dp[i][j]
 *      - therfore its a 3D dp
 *      - dp[i][j][currentXor]
 */

class Solution {
public:
  int MOD = (1e9 + 7);
  int solve(int i, int j, int currentXor, vector<vector<int> > &grid, int k,
            vector<vector<vector<int> > > &dp) {

    if (i > grid.size() - 1 || j > grid[0].size() - 1)
      return 0;

    currentXor ^= grid[i][j];

    if (dp[i][j][currentXor] != -1)
      return dp[i][j][currentXor];

    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
      if (currentXor == k)
        return 1;
      return 0;
    }

    int paths = 0;

    paths += solve(i + 1, j, currentXor, grid, k, dp);
    paths = paths % MOD;
    paths += solve(i, j + 1, currentXor, grid, k, dp);
    paths = paths % MOD;

    return dp[i][j][currentXor] = paths;
  }
  int countPathsWithXorValue(vector<vector<int> > &grid, int k) {
    vector<vector<vector<int> > > dp(
        grid.size(), vector<vector<int> >(grid[0].size(), vector<int>(20, -1)));
    int res = solve(0, 0, 0, grid, k, dp);
    return res;
  }
};