/*
1443. Minimum Time to Collect All Apples in a Tree
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
*/
class Solution
{
public:
  int dfs(int node, int par, vector<int> &vis, vector<vector<int>> &adj, vector<bool> &hasApple)
  {

    int ans = 0;
    for (auto v : adj[node])
    {
      if (v == par)
        continue;
      if (!vis[v])
      {
        int child_time = dfs(v, node, vis, adj, hasApple);
        if (child_time > 0 || hasApple[v])
        {
          ans += child_time + 2;
        }
      }
    }
    return ans;
  }
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
  {

    vector<vector<int>> adj(n);
    for (auto v : edges)
    {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
    vector<int> vis(n, 0);
    return dfs(0, -1, vis, adj, hasApple);
  }
};