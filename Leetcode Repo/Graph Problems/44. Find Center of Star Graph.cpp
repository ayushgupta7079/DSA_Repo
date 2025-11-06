/*
1791. Find Center of Star Graph
https://leetcode.com/problems/find-center-of-star-graph/description/
*/
class Solution
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    int n = edges.size();
    vector<int> deg(n + 2);
    for (auto v : edges)
    {
      deg[v[0]]++;
      deg[v[1]]++;
      if (deg[v[0]] > 1)
        return v[0];
      if (deg[v[1]] > 1)
        return v[1];
    }
    return -1;
  }
};