/*
1306. Jump Game III
https://leetcode.com/problems/jump-game-iii/description/
*/
class Solution
{
public:
  bool canReach(vector<int> &arr, int start)
  {

    int n = arr.size();
    vector<int> vis(n, 0);

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
      int ind = q.front();
      q.pop();
      if (arr[ind] == 0)
        return true;
      vis[ind] = 1;

      // ind + arr[ind]
      int ind1 = ind + arr[ind];
      if (ind1 < n && !vis[ind1])
      {
        q.push(ind1);
      }
      int ind2 = ind - arr[ind];
      if (ind2 >= 0 && !vis[ind2])
      {
        q.push(ind2);
      }
    }
    return false;
  }
};