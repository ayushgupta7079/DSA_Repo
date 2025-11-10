#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[5005][5005];

int rec(int i, int wr, vector<int> &p, vector<int> &w)
{
  if (i < 0 || wr < 0)
    return -1e9;

  if (i == 0)
  {
    if (wr >= w[0])
      return p[0];
    return 0;
  }

  if (dp[i][wr] != -1)
    return dp[i][wr];

  int take = p[i] + rec(i - 1, wr - w[i], p, w);
  int notTake = rec(i - 1, wr, p, w);

  return dp[i][wr] = max(take, notTake);
}

void solve()
{
  int n, W;
  cin >> n >> W;

  vector<int> p(n), w(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> w[i];

  memset(dp, -1, sizeof(dp));
  cout << rec(n - 1, W, p, w);
}

signed main()
{
  solve();
}
