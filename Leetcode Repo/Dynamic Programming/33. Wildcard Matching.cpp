/*
44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/description/
*/
class Solution
{
public:
  int dp[2001][2001];
  int n, m;
  int rec(int i, int j, string &s, string &p)
  {
    // pruning
    if (i > n || j > m)
      return 0;

    // base
    if (i == n && j == m)
      return 1;

    // cache
    if (dp[i][j] != -1)
      return dp[i][j];

    int ans = 0;
    if (p[j] == '?' || s[i] == p[j])
    {
      ans |= rec(i + 1, j + 1, s, p);
    }
    else if (p[j] == '*')
    {
      ans |= rec(i + 1, j, s, p); // consume 1 and stay
      ans |= rec(i, j + 1, s, p); // consume 0
    }

    // save and return
    return dp[i][j] = ans;
  }
  bool isMatch(string s, string p)
  {
    n = s.size();
    m = p.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, s, p);
  }
};