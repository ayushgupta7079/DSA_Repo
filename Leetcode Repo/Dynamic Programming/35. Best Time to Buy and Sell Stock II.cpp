/*

122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
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
        ans += (prices[i] - curr);
        curr = prices[i];
      }
    }
    return ans;
  }
};