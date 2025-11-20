/*
Subset Sum Problem
https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

class Solution
{
public:
  int n;
  int dp[205][10010];
  int rec(int level, int sum_left, vector<int> &arr)
  {
    // pruning
    if (sum_left < 0)
      return 0;
    // base
    if (level == n)
    {
      if (sum_left == 0)
        return 1;
      else
        return 0;
    }

    // cache check
    if (dp[level][sum_left] != -1)
      return dp[level][sum_left];
    // transiiton

    int take = rec(level + 1, sum_left - arr[level], arr);
    int not_take = rec(level + 1, sum_left, arr);

    // save and return
    return dp[level][sum_left] = take + not_take;
  }
  bool isSubsetSum(vector<int> &arr, int sum)
  {
    // code here
    n = arr.size();
    memset(dp, -1, sizeof(dp));
    return rec(0, sum, arr);
  }
};