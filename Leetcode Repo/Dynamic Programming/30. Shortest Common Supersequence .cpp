/*
1092. Shortest Common Supersequence
https://leetcode.com/problems/shortest-common-supersequence/description/
*/

class Solution
{
public:
  string s, t;
  int n, m;
  int dp[1005][1005];

  int rec(int i, int j)
  {
    if (i == n)
      return m - j;
    if (j == m)
      return n - i;

    if (dp[i][j] != -1)
      return dp[i][j];
    int ans = 1e9;
    if (s[i] == t[j])
      ans = min(ans, 1 + rec(i + 1, j + 1));

    return dp[i][j] = min(ans, 1 + min(rec(i + 1, j), rec(i, j + 1)));
  }

  void print_solution(int i, int j, string &ans)
  {

    if (i == n)
    {
      ans += t.substr(j);
      return;
    }
    if (j == m)
    {
      ans += s.substr(i);
      return;
    }

    if (s[i] == t[j])
    {
      ans.push_back(s[i]);
      print_solution(i + 1, j + 1, ans);
    }

    else if (dp[i][j] == 1 + dp[i + 1][j])
    {
      ans.push_back(s[i]);
      print_solution(i + 1, j, ans);
    }
    else
    {
      ans.push_back(t[j]);
      print_solution(i, j + 1, ans);
    }
  }

  string shortestCommonSupersequence(string str1, string str2)
  {
    s = str1;
    t = str2;
    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));

    rec(0, 0); // fill dp table

    string ans = "";
    print_solution(0, 0, ans);
    return ans;
  }
};
