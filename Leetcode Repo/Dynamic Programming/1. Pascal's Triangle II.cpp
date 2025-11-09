/*
119. Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle-ii/description/?envType=problem-list-v2&envId=dynamic-programming
*/

class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {

    vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        dp[i][j] += dp[i - 1][j];
        if (j >= 1)
          dp[i][j] += dp[i - 1][j - 1];
      }
    }
    return dp[rowIndex];
  }
};