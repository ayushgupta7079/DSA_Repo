/*
https://leetcode.com/problems/target-sum/description/
494. Target Sum

*/

class Solution
{
public:
  int dp[25][2005];
  int n, target;
  int rec(int level, int cur_sum, vector<int> &nums)
  {

    // pruning

    // base
    if (level == n)
    {
      if (cur_sum == target)
        return 1;
      else
        return 0;
    }

    // cache check
    if (dp[level][cur_sum] != -1)
      return dp[level][cur_sum];

    // transition
    int plus = rec(level + 1, cur_sum + nums[level], nums);
    int minus = rec(level + 1, cur_sum - nums[level], nums);

    // save and return
    return dp[level][cur_sum] = plus + minus;
  }
  int findTargetSumWays(vector<int> &nums, int t)
  {
    n = nums.size();
    target = t + 1000;
    memset(dp, -1, sizeof(dp));
    return rec(0, 1000, nums);
  }
};