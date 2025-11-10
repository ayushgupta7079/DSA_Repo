// Maximum sum subarray : Also try kadane
#include <bits/stdc++.h>
using namespace std;
#define int long long

int rec(int i, vector<int> &dp, vector<int> &nums)
{
  if (i < 0)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int ans = max(rec(i - 1, dp, nums) + nums[i], nums[i]);

  return dp[i] = ans;
}
void solve()
{

  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> dp(n, -1);
  int ans = -1e9;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, dp(i, dp, nums));
  }
  cout << ans << endl;
}

signed main()
{
  solve();
}