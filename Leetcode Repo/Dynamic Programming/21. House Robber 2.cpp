/*
213. House Robber II
https://leetcode.com/problems/house-robber-ii/description/
*/

class Solution
{
public:
  int dp[105];
  int rec(int level, int n, vector<int> &nums)
  {
    // base
    if (level >= n)
      return 0;

    // cache check
    if (dp[level] != -1)
      return dp[level];

    // transiton
    int rob = rec(level + 2, n, nums) + nums[level];
    int skip = rec(level + 1, n, nums);

    // save and return
    return dp[level] = max(rob, skip);
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    memset(dp, -1, sizeof(dp));
    int ans1 = rec(0, n - 1, nums);
    memset(dp, -1, sizeof(dp));
    int ans2 = rec(1, n, nums);
    return max(ans1, ans2);
  }
};