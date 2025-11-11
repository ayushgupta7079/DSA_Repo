#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

const int NEG = -1e18;
int dp[5005][5005];
vector<int> p, w;

int rec(int ind, int rw)
{
  if (rw < 0)
    return NEG;
  if (ind < 0)
    return 0;

  if (dp[ind][rw] != -1)
    return dp[ind][rw];

  // take current item again (unbounded)
  int take = rec(ind, rw - w[ind]) + p[ind];
  // skip and move left
  int notTake = rec(ind - 1, rw);

  return dp[ind][rw] = max(take, notTake);
}

void solve()
{
  int n, W;
  cin >> n >> W;

  memset(dp, -1, sizeof(dp));
  p.assign(n, 0);
  w.assign(n, 0);

  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> w[i];

  cout << rec(n - 1, W) << "\n";
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
