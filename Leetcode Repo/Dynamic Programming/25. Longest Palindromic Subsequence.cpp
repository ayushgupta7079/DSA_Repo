/*
Longest Palindromic Subsequence
https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

// approach : 1 LCM of (S, REV(S))
int dp[1001][1001];
string s, t;
int rec(int i, int j)
{

  if (i < 0 || j < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  int ans = 0;
  if (s[i] == t[j])
  {
    ans = max(ans, 1 + rec(i - 1, j - 1));
  }
  ans = max({ans, rec(i, j - 1), rec(i - 1, j)});

  return dp[i][j] = ans;
}
class Solution
{
public:
  int longestPalindromeSubseq(string p)
  {
    s = p;
    reverse(p.begin(), p.end());
    t = p;
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    return rec(n - 1, n - 1);
  }
};

// Approach 2 :
class Solution
{
public:
  int rec(int l, int r, string &s, vector<vector<int>> &dp)
  {
    if (l > r)
      return 0;
    if (l == r)
      return 1;
    if (dp[l][r] != -1)
      return dp[l][r];
    int ans = 0;
    if (s[l] == s[r])
    {
      ans = max(ans, 2 + rec(l + 1, r - 1, s, dp));
    }
    ans = max({ans, rec(l + 1, r, s, dp), rec(l, r - 1, s, dp)});
    return dp[l][r] = ans;
  }
  int longestPalindromeSubseq(string s)
  {
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return rec(0, n - 1, s, dp);
  }
};