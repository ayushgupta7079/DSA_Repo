/*
Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/
*/
class Solution
{
public:
  int dp[205][10010];
  int n;
  int rec(int level, int sum, vector<int> &nums)
  {
    // pruning
    if (sum < 0)
      return 0;
    // base
    if (level == n)
    {
      if (sum == 0)
        return 1;
      else
        return 0;
    }
    // cache check
    if (dp[level][sum] != -1)
      return dp[level][sum];

    // transition
    int take = rec(level + 1, sum - nums[level], nums);
    int skip = rec(level + 1, sum, nums);

    // save and return
    return dp[level][sum] = take || skip;
  }
  bool canPartition(vector<int> &nums)
  {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    int target = 0;
    for (auto v : nums)
    {
      target += v;
    }
    if (target % 2)
      return false;
    return rec(0, target / 2, nums);
  }
};