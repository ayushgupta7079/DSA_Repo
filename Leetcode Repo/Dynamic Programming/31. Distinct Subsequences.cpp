/*
115. Distinct Subsequences
https://leetcode.com/problems/distinct-subsequences/description/
*/
class Solution
{
public:
  int dp[1001][1001];
  int n, m;
  int rec(int i, int j, string &s, string &t)
  {

    // pruning
    if (i == n)
    {
      if (j == m)
        return 1;
      else
        return 0;
    }

    // cache check
    if (dp[i][j] != -1)
      return dp[i][j];

    // compute
    int ans = 0;
    if (s[i] == t[j])
    {
      ans += rec(i + 1, j + 1, s, t);
    }
    ans += rec(i + 1, j, s, t);
    // save and return
    return dp[i][j] = ans;
  }
  int numDistinct(string s, string t)
  {
    memset(dp, -1, sizeof(dp));
    n = s.size();
    m = t.size();
    return rec(0, 0, s, t);
  }
};