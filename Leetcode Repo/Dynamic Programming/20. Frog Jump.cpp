class Solution
{
public:
  int dp[10010];
  int n;
  int rec(int level, vector<int> &h)
  {

    // base
    if (level == n - 1)
      return 0;

    // cache check
    if (dp[level] != -1)
      return dp[level];

    // transition
    int ans = 1e9;
    if (level + 1 <= n - 1)
    {
      ans = min(ans, rec(level + 1, h) + abs(h[level + 1] - h[level]));
    }
    if (level + 2 <= n - 1)
    {
      ans = min(ans, rec(level + 2, h) + abs(h[level + 2] - h[level]));
    }
    // save and return
    return dp[level] = ans;
  }
  int frogJump(vector<int> &heights)
  {
    n = heights.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, heights);
  }
};