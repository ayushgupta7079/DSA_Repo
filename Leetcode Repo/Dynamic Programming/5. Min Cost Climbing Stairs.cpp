/*
746. Min Cost Climbing Stairs
https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=dynamic-programming
*/
class Solution
{
public:
  int dp[1010];
  int n;
  int rec(int level, vector<int> &cost)
  {
    // pruning
    if (level > n)
      return 1e9;
    // base
    if (level == n)
      return 0;
    // cache
    if (dp[level] != -1)
      return dp[level];
    // choice
    int ans = cost[level] + min(rec(level + 1, cost), rec(level + 2, cost));
    // save and return
    return dp[level] = ans;
  }
  int minCostClimbingStairs(vector<int> &cost)
  {
    n = cost.size();
    memset(dp, -1, sizeof(dp));
    return min(rec(0, cost), rec(1, cost));
  }
};