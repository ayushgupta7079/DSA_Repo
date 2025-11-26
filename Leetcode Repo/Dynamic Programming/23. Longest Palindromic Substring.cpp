/*
5 Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/description/
*/

class Solution
{
public:
  int dp[1001][1001];
  int n;
  string s;
  int rec(int l, int r)
  {

    // base case
    if (l >= r)
    {
      return 1;
    }
    // cache check
    if (dp[l][r] != -1)
    {
      return dp[l][r];
    }
    // compute;
    int ans = 0;
    if (s[l] == s[r])
    {
      ans = rec(l + 1, r - 1);
    }
    return dp[l][r] = ans;
  }
  string longestPalindrome(string t)
  {
    s = t;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    string temp;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (rec(i, j))
        {
          if (j - i + 1 > ans)
          {
            ans = j - i + 1;
            temp = s.substr(i, j - i + 1);
          }
        }
      }
    }
    return temp;
  }
};