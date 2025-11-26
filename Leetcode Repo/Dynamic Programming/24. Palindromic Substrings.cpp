/*
https://leetcode.com/problems/palindromic-substrings/
*/
class Solution
{
public:
  int dp[1005][1005];
  int rec(int l, int r, string s)
  {
    if (l >= r)
      return 1;
    if (dp[l][r] != -1)
      return dp[l][r];
    int ans = 0;
    if (s[l] == s[r])
    {
      ans = rec(l + 1, r - 1, s);
    }
    return dp[l][r] = ans;
  }
  int countSubstrings(string s)
  {
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
      for (int j = n - 1; j >= i; j--)
      {
        if (rec(i, j, s))
        {
          ans++;
        }
      }
    }
    return ans;
  }
};