/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

class Solution
{
public:
  int lengthOfLIS(vector<int> &a)
  {
    int n = a.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int level = 0; level < n; level++)
    {
      for (int prev = 0; prev < level; prev++)
      {
        if (a[level] > a[prev])
        {
          dp[level] = max(dp[level], 1 + dp[prev]);
        }
      }
      ans = max(ans, dp[level]);
    }
    return ans;
  }
};
