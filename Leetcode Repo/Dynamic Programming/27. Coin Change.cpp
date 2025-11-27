/*
322. Coin Change
https://leetcode.com/problems/coin-change/description/
*/
class Solution
{
public:
  int dp[13][10010];
  int n;
  int rec(int level, int k, vector<int> &coins)
  {
    // pruning
    if (k < 0)
      return 1e9;

    // base
    if (level == n)
    {
      if (k == 0)
        return 0;
      else
        return 1e9;
    }

    // cache check
    if (dp[level][k] != -1)
      return dp[level][k];

    // compute
    int take = 1 + rec(level, k - coins[level], coins);
    int not_take = rec(level + 1, k, coins);

    // save and return
    return dp[level][k] = min(take, not_take);
  }
  int coinChange(vector<int> &coins, int amount)
  {
    n = coins.size();
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, amount, coins);
    if (ans >= 1e9)
      return -1;
    else
      return ans;
  }
};