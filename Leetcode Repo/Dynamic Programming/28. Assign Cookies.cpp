/*
455. Assign Cookies
https://leetcode.com/problems/assign-cookies/
*/

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;
    int n = g.size();
    int m = s.size();
    int ans = 0;
    while (i < n && j < m)
    {
      int greed = g[i];
      while (j < m && greed > s[j])
        j++;

      if (j < m)
      {
        i += 1;
        j += 1;
        ans += 1;
      }
    }
    return ans;
  }
};