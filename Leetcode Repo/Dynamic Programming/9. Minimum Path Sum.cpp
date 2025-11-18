/*
64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  int dp[205][205];
  int n, m;
  int rec(int x, int y, vector<vector<int>> &grid)
  {

    // pruning
    if (x >= n || y >= m)
      return 1e9;
    // base
    if (x == n - 1 && y == m - 1)
      return grid[x][y];

    // cache check
    if (dp[x][y] != -1)
      return dp[x][y];
    // choice

    int down = grid[x][y] + rec(x + 1, y, grid);
    int right = grid[x][y] + rec(x, y + 1, grid);

    // save and return
    return dp[x][y] = min(down, right);
  }
  int minPathSum(vector<vector<int>> &grid)
  {
    n = grid.size();
    m = grid[0].size();
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, grid);
  }
};