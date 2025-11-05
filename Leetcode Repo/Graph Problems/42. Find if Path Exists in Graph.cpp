/*
1971. Find if Path Exists in Graph
https://leetcode.com/problems/find-if-path-exists-in-graph/description/
*/
class Solution
{
public:
  void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
  {

    vis[node] = 1;
    for (auto v : adj[node])
    {
      if (!vis[v])
      {
        dfs(v, vis, adj);
      }
    }
  }
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {

    vector<vector<int>> adj(n);
    for (auto v : edges)
    {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }

    vector<bool> vis(n, 0);
    dfs(source, vis, adj);

    return vis[destination];
  }
};