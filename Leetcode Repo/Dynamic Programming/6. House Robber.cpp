/*
198. House Robber
https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=dynamic-programming
*/
class Solution
{
public:
  int dp[105];
  int n;

  int rec(int level, vector<int> &nums)
  {

    // pruning
    if (level >= n)
      return 0;
    // base

    // cache
    if (dp[level] != -1)
      return dp[level];

    // choice

    int rob = nums[level] + rec(level + 2, nums);
    int not_rob = rec(level + 1, nums);
    // save and return

    return dp[level] = max(rob, not_rob);
  }
  int rob(vector<int> &nums)
  {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, nums);
  }
};