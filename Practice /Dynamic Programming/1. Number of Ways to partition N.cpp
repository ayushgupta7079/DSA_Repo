#include <bits/stdc++.h>
using namespace std;
#define int long long

int rec(int i, int taken, vector<vector<int>> &dp)
{

  if (i == 0)
  {
    return 1;
  }
  if (i < 0 || i < taken)
    return 0;

  if (dp[i][taken] != -1)
    return dp[i][taken];

  int ans = 0;
  // take same
  ans += rec(i - taken, taken, dp);

  // take larger
  ans += rec(i, taken + 1, dp);

  return dp[i][taken] = ans;
}
void solve()
{

  int n;
  cin >> n;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  cout << rec(n, 1, dp);
}

signed main()
{
  solve();
}