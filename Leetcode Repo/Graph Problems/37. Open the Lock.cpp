/*
752. Open the Lock
https://leetcode.com/problems/open-the-lock/description/
*/
class Solution
{
public:
  int openLock(vector<string> &deadends, string target)
  {

    unordered_map<string, bool> mp;
    for (auto v : deadends)
    {
      mp[v] = true;
    }
    if (mp["0000"])
      return -1;

    queue<pair<string, int>> q;
    q.push({"0000", 0});

    unordered_map<string, bool> seen;
    seen["0000"] = true;

    while (!q.empty())
    {
      string node = q.front().first;
      int dist = q.front().second;
      q.pop();
      if (node == target)
        return dist;

      for (int k = 0; k < 4; k++)
      {
        int c = node[k] - '0';
        int nc = (c + 1);
        int pc = (c - 1);
        if (nc == 10)
          nc = 0;
        if (pc == -1)
          pc = 9;

        string neigh1 = node;
        neigh1[k] = nc + '0';
        string neigh2 = node;
        neigh2[k] = pc + '0';

        if (!mp[neigh1] && !seen[neigh1])
        {
          seen[neigh1] = true;
          q.push({neigh1, dist + 1});
        }
        if (!mp[neigh2] && !seen[neigh2])
        {
          seen[neigh2] = true;
          q.push({neigh2, dist + 1});
        }
      }
    }
    return -1;
  }
};