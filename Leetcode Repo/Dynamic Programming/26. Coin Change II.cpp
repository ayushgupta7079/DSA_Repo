/*
518. Coin Change II
https://leetcode.com/problems/coin-change-ii/
*/
class Solution
{
public:
  int dp[305][5005];
  int n;
  int rec(int level, int k, vector<int> &coins)
  {
    // pruning
    if (k < 0)
      return 0;
    // base
    if (level == n)
    {
      if (k == 0)
        return 1;
      else
        return 0;
    }

    // cache check
    if (dp[level][k] != -1)
      return dp[level][k];

    // compute
    int take_stay = rec(level, k - coins[level], coins);
    int not_take = rec(level + 1, k, coins);

    // save and return
    return dp[level][k] = take_stay + not_take;
  }
  int change(int amount, vector<int> &coins)
  {
    memset(dp, -1, sizeof(dp));
    n = coins.size();
    return rec(0, amount, coins);
  }
};