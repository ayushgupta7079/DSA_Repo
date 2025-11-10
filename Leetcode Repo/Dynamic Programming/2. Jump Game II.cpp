/*
55. Jump Game
https://leetcode.com/problems/jump-game/?envType=problem-list-v2&envId=dynamic-programming
*/

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {

    int maxi = 0;
    for (int i = 0; i <= maxi; i++)
    {
      if (i >= nums.size() - 1)
        return true;
      maxi = max(maxi, i + nums[i]);
    }
    return false;
  }
};