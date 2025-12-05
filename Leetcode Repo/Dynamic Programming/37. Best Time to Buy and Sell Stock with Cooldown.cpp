/*
309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

class Solution
{
public:
  int dp[5001][2];
  int n;
  int rec(int level, int taken, vector<int> &prices)
  {

    // base
    if (level == n || level == n + 1)
      return 0;

    // cache check
    if (dp[level][taken] != -1)
      return dp[level][taken];

    // compute
    int ans = -1e9;
    // buy
    if (taken == 0)
      ans = max(ans, -1 * prices[level] + rec(level + 1, 1, prices));

    // sell
    if (taken == 1)
      ans = max(ans, prices[level] + rec(level + 2, 0, prices));

    // do nothing
    ans = max(ans, rec(level + 1, taken, prices));

    // save and return
    return dp[level][taken] = ans;
  }
  int maxProfit(vector<int> &prices)
  {
    n = prices.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, prices);
  }
};