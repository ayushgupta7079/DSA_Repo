/*
Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int ans = 0;
    int n = prices.size();
    int curr = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (curr > prices[i])
      {
        curr = prices[i];
      }
      else
      {
        ans = max(ans, prices[i] - curr);
      }
    }
    return ans;
  }
};