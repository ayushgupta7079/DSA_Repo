/*
62. Unique Paths
https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  int dp[101][101];

  int rec(int x, int y, int m, int n)
  {

    // pruning
    if (x >= m || y >= n)
      return 0;

    // base
    if (x == m - 1 && y == n - 1)
      return 1;
    // cache

    if (dp[x][y] != -1)
      return dp[x][y];

    // choice
    int down = rec(x + 1, y, m, n);
    int right = rec(x, y + 1, m, n);
    // save and return

    return dp[x][y] = down + right;
  }
  int uniquePaths(int m, int n)
  {
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, m, n);
  }
};

/*
another solution : (m+n)Cm
*/