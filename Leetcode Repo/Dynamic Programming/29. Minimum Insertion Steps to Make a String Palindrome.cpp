/*
1312. Minimum Insertion Steps to Make a String Palindrome
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
*/
class Solution
{
public:
  int dp[505][505];
  int n;
  int rec(int i, int j, string &s)
  {

    // base
    if (i >= j)
    {
      return 0;
    }

    // cache check
    if (dp[i][j] != -1)
      return dp[i][j];

    // compute
    int ans = 1e9;
    if (s[i] == s[j])
    {
      ans = min(ans, rec(i + 1, j - 1, s));
    }
    ans = min(ans, 1 + rec(i + 1, j, s));
    ans = min(ans, 1 + rec(i, j - 1, s));

    // save and return
    return dp[i][j] = ans;
  }
  int minInsertions(string s)
  {
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, n - 1, s);
  }
};