#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &a)
{
  int n = a.size();
  vector<int> dp(n, 1);
  int ans = 1;

  for (int level = 0; level < n; level++)
  {
    for (int prev = 0; prev < level; prev++)
    {
      if (a[level] > a[prev])
      {
        dp[level] = max(dp[level], dp[prev] + 1);
      }
    }
    ans = max(ans, dp[level]);
  }

  return ans;
}

int main()
{
  int t;
  cin >> t; // number of test cases

  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    cout << lengthOfLIS(a) << "\n";
  }

  return 0;
}
