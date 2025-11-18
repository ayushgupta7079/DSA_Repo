/*
931. Minimum Falling Path Sum
https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=study-plan-v2&envId=dynamic-programming
*/
class Solution
{
public:
  int dp[105][105];
  int done[105][105];
  int n, m;
  int rec(int x, int y, vector<vector<int>> &grid)
  {

    // pruning
    if (y < 0 || y >= m)
      return 1e9;
    // base
    if (x == n - 1)
      return grid[x][y];

    // cache check
    if (done[x][y])
      return dp[x][y];

    // choice
    int ch1 = grid[x][y] + rec(x + 1, y - 1, grid);
    int ch2 = grid[x][y] + rec(x + 1, y, grid);
    int ch3 = grid[x][y] + rec(x + 1, y + 1, grid);

    // save and return
    done[x][y] = 1;
    return dp[x][y] = min({ch1, ch2, ch3});
  }
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    n = matrix.size();
    m = matrix[0].size();

    memset(dp, -1, sizeof(dp));
    memset(done, 0, sizeof(done));
    int ans = 1e9;
    for (int col = 0; col < m; col++)
    {
      ans = min(ans, rec(0, col, matrix));
    }
    return ans;
  }
};