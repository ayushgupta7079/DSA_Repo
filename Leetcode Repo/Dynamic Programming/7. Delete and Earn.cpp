/*
740. Delete and Earn
https://leetcode.com/problems/delete-and-earn/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  unordered_map<int, int> mp;
  int dp[20010];
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
    int del = nums[level] * mp[nums[level]];
    if (level + 1 < n && nums[level + 1] > nums[level] + 1)
    { // if next element can be explored ie not deleted
      del += rec(level + 1, nums);
    }
    else
    {
      del += rec(level + 2, nums); // if next is deleted go to next->next
    }
    int not_del = rec(level + 1, nums);

    // save and return

    return dp[level] = max(del, not_del);
  }
  int deleteAndEarn(vector<int> &nums)
  {

    for (auto v : nums)
    {
      mp[v]++;
    }
    vector<int> arr;
    for (auto v : mp)
    {
      arr.push_back(v.first);
    }
    n = arr.size();
    sort(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    return rec(0, arr);
  }
};