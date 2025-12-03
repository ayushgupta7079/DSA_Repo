/*
72. Edit Distance
https://leetcode.com/problems/edit-distance/
*/
class Solution
{
public:
  int dp[1001][1001];
  int n, m;
  int rec(int i, int j, string &s, string &t)
  {

    // pruning
    if (i > n || j > m)
      return 1e9;
    // base
    if (i == n && j == m)
      return 0;
    // cache check
    if (dp[i][j] != -1)
      return dp[i][j];
    int ans = 1e9;

    // do nothing
    if (s[i] == t[j])
    {
      ans = min(ans, rec(i + 1, j + 1, s, t));
    }
    // insert
    ans = min(ans, 1 + rec(i, j + 1, s, t));

    // delete
    ans = min(ans, 1 + rec(i + 1, j, s, t));

    // replace
    ans = min(ans, 1 + rec(i + 1, j + 1, s, t));
    // compute

    // save and return
    return dp[i][j] = ans;
  }
  int minDistance(string word1, string word2)
  {
    memset(dp, -1, sizeof(dp));
    n = word1.size();
    m = word2.size();
    return rec(0, 0, word1, word2);
  }
};