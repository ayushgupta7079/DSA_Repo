/*
Longest Arithmetic Subsequence of Given Difference
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int d)
  {

    int n = arr.size();
    vector<int> dp(n, 1);
    unordered_map<int, int> mp;
    int ans = 1;

    for (int level = 0; level < n; level++)
    {
      if (mp[arr[level] - d])
      {
        dp[level] = max(dp[level], 1 + mp[arr[level] - d]);
      }
      mp[arr[level]] = max(mp[arr[level]], dp[level]);
      ans = max(ans, dp[level]);
    }
    return ans;
  }
};