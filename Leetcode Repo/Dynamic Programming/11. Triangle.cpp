/*
120. Triangle
https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  int dp[205][205];
  int done[205][205];
  int n;
  int rec(int x, int y, vector<vector<int>> &grid)
  {

    // base
    if (x == n - 1)
      return grid[x][y];

    // cache check
    if (done[x][y])
      return dp[x][y];
    // choice

    int down = grid[x][y] + rec(x + 1, y, grid);
    int right = grid[x][y] + rec(x + 1, y + 1, grid);

    // save and return
    done[x][y] = 1;
    return dp[x][y] = min(down, right);
  }
  int minimumTotal(vector<vector<int>> &triangle)
  {
    n = triangle.size();
    memset(done, 0, sizeof(done));
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, triangle);
  }
};