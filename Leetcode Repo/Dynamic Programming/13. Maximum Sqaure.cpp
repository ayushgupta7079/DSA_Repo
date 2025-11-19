/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  int dp[301][301];
  int n, m;
  int rec(int x, int y, vector<vector<char>> &grid)
  {

    // pruning
    if (x < 0 || y < 0)
      return 0;
    // base

    // cache check
    if (dp[x][y] != -1)
      return dp[x][y];
    // transition

    int ans = 0;

    if (grid[x][y] == '1')
    {
      int left = rec(x, y - 1, grid);
      int up = rec(x - 1, y, grid);
      int dia = rec(x - 1, y - 1, grid);
      ans = 1 + min({left, up, dia});
    }

    // save and return
    return dp[x][y] = ans;
  }
  int maximalSquare(vector<vector<char>> &matrix)
  {
    n = matrix.size();
    m = matrix[0].size();
    memset(dp, -1, sizeof(dp));

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        maxi = max(maxi, rec(i, j, matrix));
      }
    }
    return maxi * maxi;
  }
};