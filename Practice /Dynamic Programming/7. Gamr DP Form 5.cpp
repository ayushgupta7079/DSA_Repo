#include <bits/stdc++.h>
using namespace std;

// FORM 5 :  GAME DP
int dp[100100];

int rec(int x)
{

  // base
  if (x == 0)
  {
    return 0;
  }
  // cache check
  if (dp[x] != -1)
    return dp[x];

  int ans = 0;
  for (int i = 0; (1 << i) <= x; i++)
  {
    if (rec(x - (1 << i)) == 0)
    {
      ans = 1;
    }
  }

  // return
  return dp[x] = ans;
}
void solve()
{

  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= 10; i++)
    cout << i << " :" << rec(i) << endl;
}
int main()
{

  int t = 1;
  // cin>>t;
  while (t--)
    solve();
}