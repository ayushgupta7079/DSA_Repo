/*
673. Number of Longest Increasing Subsequence
https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/?envType=study-plan-v2&envId=dynamic-programming
*/
class Solution
{
public:
  int findNumberOfLIS(vector<int> &a)
  {
    int n = a.size();
    vector<int> dp(n, 1), ways(n, 1);
    int ans = 1;

    for (int level = 0; level < n; level++)
    {
      for (int prev = 0; prev < level; prev++)
      {
        if (a[level] > a[prev])
        {
          if (1 + dp[prev] > dp[level])
          {
            dp[level] = max(dp[level], 1 + dp[prev]);
            ways[level] = ways[prev];
          }
          else if (dp[level] == 1 + dp[prev])
          {
            ways[level] += ways[prev];
          }
        }
      }
      ans = max(ans, dp[level]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp[i] == ans)
        count += ways[i];
    }
    return count;
  }
};