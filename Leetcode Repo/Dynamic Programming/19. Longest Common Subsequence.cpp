/*
1143. Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/description/
*/

class Solution
{
public:
  int dp[1005][1005];
  int n, m;
  string A, B;

  int rec(int i, int j)
  {

    // base
    if (i >= n || j >= m)
      return 0;

    // cache check
    if (dp[i][j] != -1)
      return dp[i][j];
    // transition

    int ans = 0;
    if (A[i] == B[j])
    {
      ans = max(ans, 1 + rec(i + 1, j + 1));
    }
    else
    {
      ans = max({ans, rec(i, j + 1), rec(i + 1, j)});
    }
    // save and return
    return dp[i][j] = ans;
  }
  int longestCommonSubsequence(string text1, string text2)
  {
    A = text1;
    B = text2;
    n = A.size();
    m = B.size();

    // intialise dp
    memset(dp, -1, sizeof(dp));
    return rec(0, 0);
  }
};