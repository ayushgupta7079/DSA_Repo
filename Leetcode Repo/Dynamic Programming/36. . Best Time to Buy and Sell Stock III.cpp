/*
123. Best Time to Buy and Sell Stock III
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/
class Solution
{
public:
  int dp[100010][2][3];
  int n;
  int rec(int level, int taken, int tran, vector<int> &prices)
  {

    // base
    if (level == n)
    {
      return 0;
    }

    // cache check
    if (dp[level][taken][tran] != -1)
      return dp[level][taken][tran];

    // compute
    int ans = -1e9;

    // buy
    if (taken == 0 && tran < 2)
      ans = max(ans, -prices[level] + rec(level + 1, taken + 1, tran, prices));
    // sell
    if (taken == 1)
      ans = max(ans, prices[level] + rec(level + 1, taken - 1, tran + 1, prices));
    // don't buy and sell
    ans = max(ans, rec(level + 1, taken, tran, prices));
    // save and return
    return dp[level][taken][tran] = ans;
  }
  int maxProfit(vector<int> &prices)
  {
    n = prices.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, 0, prices);
  }
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for(int p : prices) {
            buy1  = max(buy1, -p);          // Best after buying first stock
            sell1 = max(sell1, buy1 + p);   // Best after selling first stock
            buy2  = max(buy2, sell1 - p);   // Best after buying second stock
            sell2 = max(sell2, buy2 + p);   // Best after selling second stock

        }
        return sell2;
    }
};

*/