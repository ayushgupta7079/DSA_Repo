/*
63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=dynamic-programming
*/
class Solution
{
public:
  int dp[101][101];
  int m, n;
  int rec(int x, int y, vector<vector<int>> &grid)
  {

    // pruning
    if (x >= m || y >= n || grid[x][y] == 1)
      return 0;

    // base
    if (x == m - 1 && y == n - 1)
      return 1;
    // cache

    if (dp[x][y] != -1)
      return dp[x][y];

    // choice
    int down = rec(x + 1, y, grid);
    int right = rec(x, y + 1, grid);
    // save and return

    return dp[x][y] = down + right;
  }
  int uniquePathsWithObstacles(vector<vector<int>> &grid)
  {
    memset(dp, -1, sizeof(dp));
    m = grid.size();
    n = grid[0].size();
    return rec(0, 0, grid);
  }
};